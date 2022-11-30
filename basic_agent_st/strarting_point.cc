//
// Created by Gastone Pietro Rosati Papini on 10/08/22.
//

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>

extern "C" {
#include "screen_print_c.h"
}
#include "screen_print.h"
#include "server_lib.h"
#include "logvars.h"

// --- MATLAB PRIMITIVES INCLUDE ---
#include "primitives.h"
// --- MATLAB PRIMITIVES INCLUDE ---

#define DEFAULT_SERVER_IP  "127.0.1.1"
#define SERVER_PORT             30000  // Server port
#define DT 0.05

// Handler for CTRL-C
#include <signal.h>
static uint32_t server_run = 1;
void intHandler(int signal) {
    server_run = 0;
}

// STATIC FUNCTION

static void copy_m(double m1[6], double m2[6]){
  for(int i = 0; i < 6; i++){
    m1[i] = m2[i];
  }
}

static int check_0(double m[6]){
  int tmp = 0;
  for(int i = 0; i < 6; i++){
    if(m[i] != 0) tmp += 1;
  }
  return tmp;
}

int main(int argc, const char * argv[]) {
    logger.enable(true);

    // Messages variables
    scenario_msg_t scenario_msg;
    manoeuvre_msg_t manoeuvre_msg;
    size_t scenario_msg_size = sizeof(scenario_msg.data_buffer);
    size_t manoeuvre_msg_size = sizeof(manoeuvre_msg.data_buffer);
    uint32_t message_id = 0;

#ifndef _MSC_VER
    // More portable way of supporting signals on UNIX
    struct sigaction act;
    act.sa_handler = intHandler;
    sigaction(SIGINT, &act, NULL);
#else
    signal(SIGINT, intHandler);
#endif

    server_agent_init(DEFAULT_SERVER_IP, SERVER_PORT);

    // Start server of the Agent
    printLine();
    printTable("Waiting for scenario message...", 0);
    printLine();
    while (server_run == 1) {

        // Clean the buffer
        memset(scenario_msg.data_buffer, '\0', scenario_msg_size);

        // Receive scenario message from the environment
        if (server_receive_from_client(&server_run, &message_id, &scenario_msg.data_struct) == 0) {
            // Init time
            static auto start = std::chrono::system_clock::now();
            auto time = std::chrono::system_clock::now()-start;
            double num_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(time).count()/1000.0;
            printLogTitle(message_id, "received message");

            // Data struct
            input_data_str *in = &scenario_msg.data_struct;
            //output_data_str *out = &manoeuvre_msg.data_struct;
            manoeuvre_msg.data_struct.CycleNumber = in->CycleNumber;
            manoeuvre_msg.data_struct.Status = in->Status;

            // Example of using log
            logger.log_var("Example", "Cycle", in->CycleNumber);
            logger.log_var("Example", "Time", num_seconds);
            logger.log_var("Example", "Velocity", in->VLgtFild);
            logger.log_var("Example", "Acceleration", in->ALgtFild);

            // ADD AGENT CODE HERE

            double v0 = in->VLgtFild;
            double a0 = in->ALgtFild;
            double lookahead = fmax(50,v0*5);
            double v_min = 3;
            double v_max = 15;
            double x_s = 5;
            double x_in = 10;
            double v_r = in->RequestedCruisingSpeed;
            double T_s = x_s / v_min;
            double T_in = x_in / v_min;
            double x_tr = 0;
            double x_stop = 0;
            double T_green = 0;
            double T_red = 0;
            double m_star[6], m1[6], m2[6];

            if(in->NrTrfLights != 0){
                x_tr = in->TrfLightDist;
                x_stop = x_tr - x_s / 2;
            }

            if(in->NrTrfLights == 0 || x_tr >= lookahead){
                pass_primitive(a0,v0,lookahead,v_r,v_r,0,0,m1,m2);
                copy_m(m_star, m1);
            } else {
                double Trf1 = in->TrfLightFirstTimeToChange;
                double Trf2 = in->TrfLightSecondTimeToChange;
                double Trf3 = in->TrfLightThirdTimeToChange;

                switch (in->TrfLightCurrState) {
                    case 1:
                        T_green = 0;
                        T_red = Trf1 - T_in;
                        break;
                    case 2:
                        T_green = Trf2 + T_s;
                        T_red = Trf3 - T_in;
                        break;
                    case 3:
                        T_green = Trf1 + T_s;
                        T_red = Trf2 - T_in;
                        break;
                    default:
                        break;
                }

                if(in->TrfLightCurrState == 1 && in->TrfLightDist <= x_s){
                    pass_primitive(a0,v0,lookahead,v_r,v_r,0,0,m1,m2);
                    copy_m(m_star, m1);
                } else {
                    pass_primitive(a0,v0,x_tr,v_min,v_max,T_green,T_red,m1,m2);
                    
                    if(check_0(m1) == 0 && check_0(m2) == 0){
                        stop_primitive(v0,a0,x_stop,m_star);
                    } else {
                        if((m1[3] < 0 && m2[3] > 0) || (m1[3] > 0 && m2[3] < 0)){
                            pass_primitivej0(v0,a0,x_tr,v_min,v_max,m_star);
                        } else {
                            if(abs(m1[3]) < abs(m2[3])){
                                copy_m(m_star, m1);
                            } else {
                                copy_m(m_star, m2);
                            }
                        }
                    }
                }
            }

            double req_acc = m_star[2] + m_star[3]*num_seconds + 0.5*m_star[4]*pow(num_seconds,2) + 1.6666667*m_star[5]*pow(num_seconds,3);

            // ADD LOW LEVEL CONTROL
            static double integral = 0.0;
            double P_gain = 0.2;
            double I_gain = 1;
            double req_pedal;
            double error = req_acc - a0;
            integral = integral + error * DT;
            req_pedal = P_gain * error + I_gain * integral;
/*
            // Reset the memory
            if(vel < 0.1 && old_req_acc < 0 && jint > 0){
                old_req_acc = 0;
                integral = 0;
            }
*/

            // Update output: requested acceleration
            manoeuvre_msg.data_struct.RequestedAcc = req_pedal;

            // Write log
            logger.write_line("Example");

            // Screen print
            printLogVar(message_id, "Status", in->Status);
            printLogVar(message_id, "Time", num_seconds);
            printLogVar(message_id, "CycleNumber", in->CycleNumber);
            printLogVar(message_id, "Actual velocity", in->VLgtFild);
            printLogVar(message_id, "Actual acceleration", in->ALgtFild);
            printLogVar(message_id, "Requested acceleration", req_pedal);

            // Send manoeuvre message to the environment
            if (server_send_to_client(server_run, message_id, &manoeuvre_msg.data_struct) == -1) {
                perror("error send_message()");
                exit(EXIT_FAILURE);
            } else {
                printLogTitle(message_id, "sent message");
            }
        }
    }

    // Close the server of the agent
    server_agent_close();
    return 0;
}