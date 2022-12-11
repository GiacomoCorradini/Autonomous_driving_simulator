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

#define DEFAULT_SERVER_IP  "127.0.0.1"
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

static double j_opt(double t, double m[6]){
    double jerk = m[3] + m[4] * t + 1.0/2.0 * m[5] * pow(t,2);
    return jerk;
}

static double v_opt(double t, double m[6]){
    double vel = m[1] + m[2] * t + 1.0/2.0 * m[3] * pow(t,2) + 1.0/6.0 * m[4] * pow(t,3) + 1.0/24.0 * m[5] * pow(t,4);
    return vel;
}

double max_max(double a1, double a2, double a3){
  double max;
  if(a1 < a2){
      if(a2 < a3) max = a3;
      else max = a2;
  } else {
      if(a1 < a3) max = a3;
      else max = a1;
  }

  return max;
}

int main(int argc, const char * argv[]) {
    logger.enable(true);

    // Messages variables
    scenario_msg_t scenario_msg;
    manoeuvre_msg_t manoeuvre_msg;
    size_t scenario_msg_size = sizeof(scenario_msg.data_buffer);
    size_t manoeuvre_msg_size = sizeof(manoeuvre_msg.data_buffer);
    uint32_t message_id = 0;
    std::string filename = "Example1";

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
            output_data_str *out = &manoeuvre_msg.data_struct;
            manoeuvre_msg.data_struct.CycleNumber = in->CycleNumber;
            manoeuvre_msg.data_struct.Status = in->Status;

            // Example of using log
            logger.log_var(filename, "Cycle", in->CycleNumber);
            logger.log_var(filename, "Time", num_seconds);
            logger.log_var(filename, "Vel_0", in->VLgtFild);
            logger.log_var(filename, "Acc_0", in->ALgtFild);
            logger.log_var(filename, "TrafficLight", in->TrfLightCurrState);

            // ADD AGENT CODE HERE

            double v0 = in->VLgtFild;
            double a0 = in->ALgtFild;
            double lookahead = std::max(50.0,v0*5.0);
            double v_min = 3.0;
            double v_max = 15.0;
            double x_s = 5.0;
            double x_in = 10.0;
            double v_r = in->RequestedCruisingSpeed;
            double T_s = x_s / v_min;
            double T_in = x_in / v_min;
            double x_tr;
            double x_stop;
            double T_green;
            double T_red;
            double m_star[6], m1[6], m2[6];
            double T1, T2, smax, v1, v2;

            if(in->NrTrfLights != 0){
                x_tr = in->TrfLightDist;
                x_stop = in->TrfLightDist - (x_s / 2.0);
            }

            if(in->NrTrfLights == 0 || x_tr >= lookahead){
                //pass_primitive(a0,v0,lookahead,v_r,v_r,0,0,m1,m2);
                pass_primitive(a0,v0,lookahead,v_r,v_r,0.0,0.0,m1,m2,&T1,&T2);
                copy_m(m_star, m1);
            } else {
                switch (in->TrfLightCurrState) {
                    case 1:
                        T_green = 0.0;
                        T_red = in->TrfLightFirstTimeToChange - T_in;
                        break;
                    case 2:
                        T_green = in->TrfLightSecondTimeToChange + T_s;
                        T_red = in->TrfLightThirdTimeToChange - T_in;
                        break;
                    case 3:
                        T_green = in->TrfLightFirstTimeToChange + T_s;
                        T_red = in->TrfLightSecondTimeToChange - T_in;
                        break;
                    default:
                        break;
                }

                if(in->TrfLightCurrState == 1 && in->TrfLightDist <= x_s){
                    //pass_primitive(a0,v0,lookahead,v_r,v_r,0,0,m1,m2);
                    pass_primitive(a0,v0,lookahead,v_r,v_r,0.0,0.0,m1,m2,&T1,&T2);
                    copy_m(m_star, m1);
                } else {
                    //pass_primitive(a0,v0,x_tr,v_min,v_max,T_green,T_red,m1,m2);
                    pass_primitive(a0,v0,x_tr,v_min,v_max,T_green,T_red,m1,m2,&T1,&T2);
                    if(check_0(m1) == 0 && check_0(m2) == 0){
                        //stop_primitive(v0,a0,x_stop,m_star);
                        stop_primitive(v0,a0,x_stop,m_star,&T1,&smax);
                    } else {
                        if((m1[2] < 0 && m2[2] > 0) || (m1[2] > 0 && m2[2] < 0)){
                            //pass_primitivej0(v0,a0,x_tr,v_min,v_max,m_star);
                            pass_primitivej0(v0,a0,x_tr,v_min,v_max,m_star,&T1,&v1);
                        } else {
                            if(abs(m1[2]) < abs(m2[2])){
                                copy_m(m_star, m1);
                            } else {
                                copy_m(m_star, m2);
                            }
                        }
                    }
                }
            }
/*
            // ADD AGENT OLD CODE HERE

            double v0 = in->VLgtFild;
            double a0 = in->ALgtFild;
            double lookahead = max_max(50.0,v0*10.0,v0*v0);
            double v_r = fmin(in->RequestedCruisingSpeed, in->AdasisSpeedLimitValues[0]);
            double T_s = 0.5;
            double v_min = 5.0;
            double x_s = v_r * T_s;
            double x_stop;
            double T_p = x_s / v_min;
            double T_red;
            double T_green;
            double x_f;
            double m_star[6], m1[6], m2[6];
            double T1, T2, smax, v1, v2;

            if(in->NrTrfLights != 0){
                x_f = in->TrfLightDist - x_s;
                x_stop = in->TrfLightDist - (x_s / 2.0);
            }

            if(in->NrTrfLights == 0 || x_f >= lookahead){
                pass_primitive(a0,v0,lookahead,v_r,v_r,0.0,0.0,m1,m2,&T1,&T2);
                copy_m(m_star, m1);
            } else {
                double Trf1 = in->TrfLightFirstTimeToChange;
                double Trf2 = in->TrfLightSecondTimeToChange;
                double Trf3 = in->TrfLightThirdTimeToChange;

                switch (in->TrfLightCurrState) {
                    case 1:
                        T_green = 0.0;
                        T_red = Trf1;
                        break;
                    case 2:
                        T_green = Trf2;
                        T_red = Trf3;
                        break;
                    case 3:
                        T_green = Trf1;
                        T_red = Trf2;
                        break;
                    default:
                        break;
                }

                if(in->TrfLightCurrState == 1 && in->TrfLightDist <= x_s){
                    pass_primitive(a0,v0,lookahead,v_r,v_r,0.0,0.0,m1,m2,&T1,&T2);
                    copy_m(m_star, m1);
                } else {
                    pass_primitive(a0,v0,x_f,v_min,v_r,T_green,T_red - T_s - T_p,m1,m2,&T1,&T2);
                    if(check_0(m1) == 0 && check_0(m2) == 0){
                        stop_primitive(v0,a0,x_stop,m_star,&T1,&smax);
                    } else {
                        if((m1[2] < 0 && m2[2] > 0) || (m1[2] > 0 && m2[2] < 0)){
                            pass_primitivej0(v0,a0,x_f,v_min,v_r,m_star,&T1,&v1);
                        } else {
                            if(abs(m1[2]) < abs(m2[2])){
                                copy_m(m_star, m1);
                            } else {
                                copy_m(m_star, m2);
                            }
                        }
                    }
                }
            }
*/
            // Integrated jerk - trapezoidal - with internal a0
            double a0_bar = a0;
            double req_acc = a0 + DT/2.0 * (j_opt(0.0,m_star) + j_opt(DT,m_star));
            a0_bar = req_acc;


            // Include saturation
            //double a_saturate = 2.0;
            //req_acc = std::min(std::max(req_acc, -a_saturate), a_saturate);

            // ADD LOW LEVEL CONTROL
            static double integral = 0.0;
            double P_gain = 0.2;
            double I_gain = 1.0;
            double req_pedal;
            double error = req_acc - a0;
            integral = integral + error * DT;
            req_pedal = P_gain * error + I_gain * integral;
/*
            // Reset the memory
            if(in->VLgtFild < 0.1 && a0_bar < 0 && integral < 0){
                out->RequestedAcc = 0;
                integral = 0.0;
            }
*/
            // Update output: requested acceleration
            out->RequestedAcc = req_pedal;

            double v_req = v_opt(DT,m_star);

            logger.log_var(filename, "Vel_req", v_req);
            logger.log_var(filename, "Acc_req", req_pedal);

            logger.log_var(filename, "c1", m_star[1]);
            logger.log_var(filename, "c2", m_star[2]);
            logger.log_var(filename, "c3", m_star[3]);
            logger.log_var(filename, "c4", m_star[4]);
            logger.log_var(filename, "c5", m_star[5]);


            // Write log
            logger.write_line(filename);

            // Screen print
            printLogVar(message_id, "Status", in->Status);
            printLogVar(message_id, "Time", num_seconds);
            printLogVar(message_id, "CycleNumber", in->CycleNumber);
            printLogVar(message_id, "TrafficLight", in->TrfLightCurrState);
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