#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <vector>


extern "C" {
#include "screen_print_c.h"
}
#include "screen_print.h"
#include "server_lib.h"
#include "logvars.h"
#include "Clothoids.hh"


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

// STATIC FUNCTION DECLARATION

static void copy_m(double m1[6], double m2[6]);
static int check_0(double m[6]);
static double jEval(double t, double m[6]);
static double v_requested(double t, double m[6]);
static void vehicle_position(double x0, double x_act, double offL, double offR, double* X, double* Y);

// MAIN
using G2lib::real_type;
using G2lib::int_type;
using namespace std;

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
/* -------------------------------------------------------------------------------------------------------------- */

            //   _____ ____      _       _ _____ ____ _____ ___  ______   __
            //  |_   _|  _ \    / \     | | ____/ ___|_   _/ _ \|  _ \ \ / /
            //    | | | |_) |  / _ \ _  | |  _|| |     | || | | | |_) \ V / 
            //    | | |  _ <  / ___ \ |_| | |__| |___  | || |_| |  _ < | |  
            //    |_| |_| \_\/_/   \_\___/|_____\____| |_| \___/|_| \_\|_|  
                                                                        
            vector<std::pair<double, double>> trajectory;

            // for (size_t i = 0; i < count; i++){
            //     /* code */
            // }


/* -------------------------------------------------------------------------------------------------------------- */

            //    ____    _    ____    ____   ___  ____ ___ _____ ___ ___  _   _ 
            //   / ___|  / \  |  _ \  |  _ \ / _ \/ ___|_ _|_   _|_ _/ _ \| \ | |
            //  | |     / _ \ | |_) | | |_) | | | \___ \| |  | |  | | | | |  \| |
            //  | |___ / ___ \|  _ <  |  __/| |_| |___) | |  | |  | | |_| | |\  |
            //   \____/_/   \_\_| \_\ |_|    \___/|____/___| |_| |___\___/|_| \_|
            
            static double pos0 = in->TrfLightDist;       // initial distance of the traffic-light      
            double LatPosL = in->LatOffsLineL;           // Relative lateral position from left line
            double LatPosR = in->LatOffsLineR;           // Relative lateral position from right line
            double yaw;  // TO UPDATE                                 
            double X, Y;                                 // (X,Y) coordinate of the vehicle in the env

            // compute vehicle position
            vehicle_position(pos0, in->TrfLightDist, LatPosL, LatPosR, &X, &Y);
                                                                  
/* -------------------------------------------------------------------------------------------------------------- */
            
            //   _        _  _____ _____ ____      _    _        ____ ___  _   _ _____ ____   ___  _     
            //  | |      / \|_   _| ____|  _ \    / \  | |      / ___/ _ \| \ | |_   _|  _ \ / _ \| |    
            //  | |     / _ \ | | |  _| | |_) |  / _ \ | |     | |  | | | |  \| | | | | |_) | | | | |    
            //  | |___ / ___ \| | | |___|  _ <  / ___ \| |___  | |__| |_| | |\  | | | |  _ <| |_| | |___ 
            //  |_____/_/   \_\_| |_____|_| \_\/_/   \_\_____|  \____\___/|_| \_| |_| |_| \_\\___/|_____|
                                                                                                      

            double steer = in->SteerWhlAg;               // Actual steering wheel angle
            double req_steer = -0.01;                    // Requested steering wheel angle
            real_type P0x = X;                           // x coordinate of car posiotion
            real_type P0y = Y;                           // y coordinate of car posiotion
            real_type P0theta = Utils::m_pi_2;           // Default
            real_type P1x;                               // x coordinate of point trajectory
            real_type P1y;                               // y coordinate of point trajectory
            real_type P1theta = Utils::m_pi_2;           // Default
            G2lib::G2solve3arc C1;                       // Clothoid
            vector<real_type> vec_x, vec_y;              // 
            vector<real_type> vec_theta, vec_kappa;      // 
            real_type x, y, theta, kappa;             

            C1.build(P0x, P0y, P0theta, 0, P1x, P1y, P1theta, 0);

            for(int i = 0; i <= 100; i++){
                real_type s = i * 0.05;
                C1.eval(s, theta, kappa, x, y);
                vec_x.push_back(x);
                vec_y.push_back(y);
                vec_theta.push_back(theta);
                vec_kappa.push_back(kappa);
            }

            logger.log_var(filename, "vec_x", x);
            logger.log_var(filename, "vec_y", y);
            logger.log_var(filename, "vec_theta", theta);
            logger.log_var(filename, "vec_kappa", kappa);



            // Update output: requested steering angle
            out->RequestedSteerWhlAg = req_steer;

/* -------------------------------------------------------------------------------------------------------------- */

            //   _     ___  _   _  ____ ___ _____ _   _ ____ ___ _   _    _    _        ____ ___  _   _ _____ ____   ___  _     
            //  | |   / _ \| \ | |/ ___|_ _|_   _| | | |  _ \_ _| \ | |  / \  | |      / ___/ _ \| \ | |_   _|  _ \ / _ \| |    
            //  | |  | | | |  \| | |  _ | |  | | | | | | | | | ||  \| | / _ \ | |     | |  | | | |  \| | | | | |_) | | | | |    
            //  | |__| |_| | |\  | |_| || |  | | | |_| | |_| | || |\  |/ ___ \| |___  | |__| |_| | |\  | | | |  _ <| |_| | |___ 
            //  |_____\___/|_| \_|\____|___| |_|  \___/|____/___|_| \_/_/   \_\_____|  \____\___/|_| \_| |_| |_| \_\\___/|_____|
                                                                                                                             
            double v0 = in->VLgtFild;                  // actual longitudinal velocity
            double a0 = in->ALgtFild;                  // actual longitudinal acceleration
            double lookahead = std::max(50.0,v0*5.0);  // lookahead distance
            double v_min = 3.0;                        // vel min to pass the traffic light
            double v_max = 15.0;                       // vel max to pass the traffic light
            double x_s = 5.0;                          // safety space before traffic light
            double x_in = 10.0;                        // length of the intersection
            double v_r = in->RequestedCruisingSpeed;   // req cruising speed of the vehicle
            double T_s = x_s / v_min;                  // time to travel the safety space
            double T_in = x_in / v_min;                // time to safety space
            double x_tr = 0;                           // distance to the traffic light
            double x_stop = 0;                         // distance to the stop the vehicle
            double T_green = 0;                        // 
            double T_red = 0;                          // 
            double m_star[6], m1[6], m2[6];            // primitives
            double T1 = 0, T2 = 0, smax = 0, v1 = 0;   // usefull variable

            // Check if there is almost one Traffic light in the scenario
            if(in->NrTrfLights != 0){
                x_tr = in->TrfLightDist;
                x_stop = in->TrfLightDist - (x_s / 2.0);
            }

            if(in->NrTrfLights == 0 || x_tr >= lookahead){
                pass_primitive(a0,v0,lookahead,&v_r,&v_r,0.0,0.0,m1,m2,&T1,&T2);
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
                    pass_primitive(a0,v0,lookahead,&v_r,&v_r,0.0,0.0,m1,m2,&T1,&T2);
                    copy_m(m_star, m1);
                } else {
                    pass_primitive(a0,v0,x_tr,&v_min,&v_max,T_green,T_red,m1,m2,&T1,&T2);
                    if(check_0(m1) == 0 && check_0(m2) == 0){
                        stop_primitive(v0,a0,x_stop,m_star,&T1,&smax);
                    } else {
                        if((m1[3] < 0 && m2[3] > 0) || (m1[3] > 0 && m2[3] < 0)){
                            pass_primitivej0(v0,a0,x_tr,v_min,v_max,m_star,&T1,&v1);
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

            // Integrated jerk - trapezoidal - with internal a0
            double req_acc = a0 + DT/2.0 * (jEval(0.0,m_star) + jEval(DT,m_star));
            
            //static double a0_bar = 0.0;
            //double req_acc = a0_bar + DT/2.0 * (jEval(0.0,m_star) + jEval(DT,m_star));
            //a0_bar = req_acc;
            
            double v_req = v_requested(DT,m_star);

            // ADD LOW LEVEL CONTROL
            static double integral = 0.0;
            double P_gain = 0.3;
            double I_gain = 1.0;
            double req_pedal;
            double error = req_acc - a0;
            integral = integral + error * DT;
            req_pedal = P_gain * error + I_gain * integral;

            // Reset the memory
            if(in->VLgtFild < 0.1 && jEval(0.0,m_star) > 0.0){
                integral = 0.0;
            }

            //if(in->VLgtFild < 0.1 && a0_bar < 0.0 && jEval(0.0,m_star) > 0.0){
            //    a0_bar = 0.0;
            //    integral = 0.0;
            //}

            // Update output: requested acceleration
            out->RequestedAcc = req_pedal;

/* -------------------------------------------------------------------------------------------------------------- */

            //   ____ ___ ____  ____  _        _ __   __
            //  |  _ \_ _/ ___||  _ \| |      / \\ \ / /
            //  | | | | |\___ \| |_) | |     / _ \\ V / 
            //  | |_| | | ___) |  __/| |___ / ___ \| |  
            //  |____/___|____/|_|   |_____/_/   \_\_|  
                                                     
            // Log_vars
            logger.log_var(filename, "N Cycle", in->CycleNumber);
            logger.log_var(filename, "Time", num_seconds);
            logger.log_var(filename, "Vel_act", in->VLgtFild);
            logger.log_var(filename, "Acc_act", in->ALgtFild);
            logger.log_var(filename, "TrafficLight", in->TrfLightCurrState);
            logger.log_var(filename, "Vel_req", v_req);
            logger.log_var(filename, "Acc_req", req_pedal);
            logger.log_var(filename, "T_green", T_green);
            logger.log_var(filename, "T_red", T_red);
            logger.log_var(filename, "T1", T1);
            logger.log_var(filename, "T2", T2);
            logger.log_var(filename, "v_min", v_min);
            logger.log_var(filename, "v_max", v_max);
            logger.log_var(filename, "TrfLightDist",in->TrfLightDist);
            logger.log_var(filename, "c1", m_star[1]);
            logger.log_var(filename, "c2", m_star[2]);
            logger.log_var(filename, "c3", m_star[3]);
            logger.log_var(filename, "c4", m_star[4]);
            logger.log_var(filename, "c5", m_star[5]);

            // Write log
            logger.write_line(filename);

            // Screen print
            printLogVar(message_id, "Status", in->Status);
            printLogVar(message_id, "CycleNumber", in->CycleNumber);
            printLogVar(message_id, "Time", num_seconds);
            printLogVar(message_id, "TrafficLight", in->TrfLightCurrState);
            printLogVar(message_id, "Dist to TrfLight", in->TrfLightDist);
            printLogVar(message_id, "Actual velocity", in->VLgtFild);
            printLogVar(message_id, "Actual acceleration", in->ALgtFild);
            printLogVar(message_id, "Actual steering wheel", steer);
            printLogVar(message_id, "Requested acceleration", req_pedal);
            //printLogVar(message_id, "Requested steering wheel", req_steer);

            printLogVar(message_id, "Lateral position Left", LatPosL);
            printLogVar(message_id, "Lateral position Right", LatPosR);


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

//   ____ _____  _  _____ ___ ____   _____ _   _ _   _  ____ _____ ___ ___  _   _ 
//  / ___|_   _|/ \|_   _|_ _/ ___| |  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | |
//  \___ \ | | / _ \ | |  | | |     | |_  | | | |  \| | |     | |  | | | | |  \| |
//   ___) || |/ ___ \| |  | | |___  |  _| | |_| | |\  | |___  | |  | | |_| | |\  |
//  |____/ |_/_/   \_\_| |___\____| |_|    \___/|_| \_|\____| |_| |___\___/|_| \_|

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

static double jEval(double t, double m[6]){
    double jerk = m[3] + m[4] * t + 1.0/2.0 * m[5] * pow(t,2);
    return jerk;
}

static double v_requested(double t, double m[6]){
    double vel = m[1] + m[2] * t + 1.0/2.0 * m[3] * pow(t,2) + 1.0/6.0 * m[4] * pow(t,3) + 1.0/24.0 * m[5] * pow(t,4);
    return vel;
}

static void vehicle_position(double x0, double x_act, double offL, double offR, double* X, double* Y){
    *X = x0 - x_act;
    *Y = offL;
}