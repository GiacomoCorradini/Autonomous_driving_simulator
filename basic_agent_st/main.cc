#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <vector>

extern "C"
{
#include "screen_print_c.h"
}
#include "screen_print.h"
#include "server_lib.h"
#include "logvars.h"
#include "Clothoids.hh"
#include "primitives.h"
#include "rrt.h"

#define DEFAULT_SERVER_IP "127.0.0.1" // IP Address
#define SERVER_PORT 30000             // Server port
#define DT 0.05                       // Time step

// Handler for CTRL-C
#include <signal.h>
static uint32_t server_run = 1;
void intHandler(int signal)
{
    server_run = 0;
}

// STATIC FUNCTION DECLARATION
static void copy_m(double m1[6], double m2[6]);
static int check_0(double m[6]);
static double jEval(double t, double m[6]);
static double v_requested(double t, double m[6]);
static void vehicle_position(double x0, double x_act, double offL, double offR, double *X, double *Y);

//   __  __    _    ___ _   _
//  |  \/  |  / \  |_ _| \ | |
//  | |\/| | / _ \  | ||  \| |
//  | |  | |/ ___ \ | || |\  |
//  |_|  |_/_/   \_\___|_| \_|

int main(int argc, const char *argv[])
{
    logger.enable(true);

    // Messages variables
    scenario_msg_t scenario_msg;
    manoeuvre_msg_t manoeuvre_msg;
    size_t scenario_msg_size = sizeof(scenario_msg.data_buffer);
    size_t manoeuvre_msg_size = sizeof(manoeuvre_msg.data_buffer);
    uint32_t message_id = 0;
    std::string filename = "Long_param";
    std::string filename_path = "Path";
    std::string filename_traj = "Trajectory";
    static bool traj = false;
    G2lib::ClothoidList trajectory;

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
    while (server_run == 1)
    {

        // Clean the buffer
        memset(scenario_msg.data_buffer, '\0', scenario_msg_size);

        // Receive scenario message from the environment
        if (server_receive_from_client(&server_run, &message_id, &scenario_msg.data_struct) == 0)
        {
            // Init time
            static auto start = std::chrono::system_clock::now();
            auto time = std::chrono::system_clock::now() - start;
            double num_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(time).count() / 1000.0;
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

            static std::string select_traj = "RRT";
            //static std::string select_traj = "Staigth_line";

           int mode = in->ObjID[0];
           

            // Get the initial car position
            static double pos_X0 = 0.;
            static double pos_Y0 = in->LatOffsLineL;
            static double yaw0 = in->LaneHeading;


            // Calculate the trajectory only at the beginning of the algorithm
            if (!traj)
            {

                /* RRT ALGORITHM */
                if(mode == 1){
                    // Starting and goal points definition
                    node start, goal;
                    start.p.x = pos_X0 * 10;
                    start.p.y = pos_Y0 * 10;
                    goal.p.x = 1800.0;
                    goal.p.y = 0.0;

                    // Obstacles definition
                    obstacle obs0, obs1, obs2;
                    
                    obs0.x = in->ObjX[0]*10;
                    obs0.y = in->ObjY[0]*10;
                    obs0.lenght = in->ObjLen[0]*10;
                    obs0.width = in->ObjWidth[0]*10;

                    obs1.x = in->ObjX[1]*10;
                    obs1.y = in->ObjY[1]*10;
                    obs1.lenght = in->ObjLen[0]*10;
                    obs1.width = in->ObjWidth[0]*10;

                    obs2.x = in->ObjX[2]*10;
                    obs2.y = in->ObjY[2]*10;
                    obs2.lenght = in->ObjLen[0]*10;
                    obs2.width = in->ObjWidth[0]*10;

                    // Definisco il vettore dei punti che definiscono il path da seguire
                    std::vector<node> path_car;

                    rrt_path(start, goal, obs0, obs1, obs2, path_car);

                    for (int i = 0; i < path_car.size() - 1; i++)
                    {
                        G2lib::ClothoidCurve part_traj;
                        double x1 = path_car[i].p.x;
                        double x2 = path_car[i + 1].p.x;
                        double y1 = path_car[i].p.y;
                        double y2 = path_car[i + 1].p.y;
                        part_traj.build_G1(x1, y1, 0., x2, y2, 0.);

                        G2lib::PolyLine poly;
                        poly.build(part_traj,1);
                        trajectory.push_back(part_traj);
                    }

                    G2lib::real_type x_1, y_1;
                    std::vector<G2lib::real_type> vec_x_1, vec_y_1;
                    for (int i = 0; i <= (trajectory.length() / DT); i++)
                    {
                        G2lib::real_type s = i * 0.05;
                        trajectory.eval(s, x_1, y_1);

                        vec_x_1.push_back(x_1);
                        vec_y_1.push_back(y_1);

                        logger.log_var(filename_path, "X path", vec_x_1[i]);
                        logger.log_var(filename_path, "Y path", vec_y_1[i]);
                        logger.write_line(filename_path);
                    }
                }

                /* LINE */
                if(mode == 0){
                    G2lib::ClothoidCurve line;
                    G2lib::real_type x_1, y_1, theta_1;
                    std::vector<G2lib::real_type> vec_x_1, vec_y_1, vec_theta_1;
                    line.build_G1(pos_X0, pos_Y0, 0., 182., pos_Y0, 0.);
                    for(int i = 0; i <= (line.length() / DT); i++){
                        G2lib::real_type s = i * 0.05;
                        line.eval(s, x_1, y_1);
                        theta_1 = line.theta(s);

                        vec_x_1.push_back(x_1);
                        vec_y_1.push_back(y_1);
                        vec_theta_1.push_back(theta_1);

                        logger.log_var(filename_path, "X0", vec_x_1[i]);
                        logger.log_var(filename_path, "Y0", vec_y_1[i]);
                        logger.log_var(filename_path, "THETA0", vec_theta_1[i]);
                        logger.write_line(filename_path);
                    }

                    trajectory.push_back(line);
                }

                traj = true;
            }

            /* -------------------------------------------------------------------------------------------------------------- */

            //    ____    _    ____            ____   ___  ____ ___ _____ ___ ___  _   _
            //   / ___|  / \  |  _ \          |  _ \ / _ \/ ___|_ _|_   _|_ _/ _ \| \ | |
            //  | |     / _ \ | |_) |  _____  | |_) | | | \___ \| |  | |  | | | | |  \| |
            //  | |___ / ___ \|  _ <  |_____| |  __/| |_| |___) | |  | |  | | |_| | |\  |
            //   \____/_/   \_\_| \_\         |_|    \___/|____/___| |_| |___\___/|_| \_|

            static double pos0 = in->TrfLightDist; // initial distance of the traffic-light
            double LatPosL = in->LatOffsLineL;     // Relative lateral position from left line
            double LatPosR = in->LatOffsLineR;     // Relative lateral position from right line
            double yaw = in->LaneHeading;          // Attitude of the vehicle w.r.t straight road
            double vehicle_X, vehicle_Y;           // (X,Y) coordinate of the vehicle in the env

            // compute vehicle position
            vehicle_position(pos0, in->TrfLightDist, LatPosL, LatPosR, &vehicle_X, &vehicle_Y);
            /**
             * Position of the vehicle
             * X = distance from the start position of the car
             * Y = distance from the left line
             * YAW = Yaw angle from the horizontal axel
             */

            logger.log_var(filename_traj, "X vehicle", vehicle_X);
            logger.log_var(filename_traj, "Y vehicle", vehicle_Y);
            logger.log_var(filename_traj, "Yaw vehicle", yaw);

            /* -------------------------------------------------------------------------------------------------------------- */

            //   _        _  _____ _____ ____      _    _        ____ ___  _   _ _____ ____   ___  _
            //  | |      / \|_   _| ____|  _ \    / \  | |      / ___/ _ \| \ | |_   _|  _ \ / _ \| |
            //  | |     / _ \ | | |  _| | |_) |  / _ \ | |     | |  | | | |  \| | | | | |_) | | | | |
            //  | |___ / ___ \| | | |___|  _ <  / ___ \| |___  | |__| |_| | |\  | | | |  _ <| |_| | |___
            //  |_____/_/   \_\_| |_____|_| \_\/_/   \_\_____|  \____\___/|_| \_| |_| |_| \_\\___/|_____|

            //static std::string select_latcontroller = "Clothoids";
            static std::string select_latcontroller = "Previw_point";

            double req_steer_angle = 0;    // Requested steering wheel angle
            double steer = in->SteerWhlAg; // Actual steering wheel angle

            if(select_latcontroller == "Clothoids"){
                double K_US = 0;               // understeering gradient
                double lookahead_lat = 15;     // lookahead distance [m]

                // Take a point from the reference trajectory
                G2lib::real_type P1x;     // x coordinate of point trajectory
                G2lib::real_type P1y;     // y coordinate of point trajectory
                G2lib::real_type P1theta; // theta coordinate of point trajectory
                G2lib::real_type variable_s, t_coordiate, points_dist;

                // evaluate the closest point on the trajectory considering the actual position of the vehicle
                trajectory.closestPoint_ISO(vehicle_X, vehicle_Y, P1x, P1y, variable_s, t_coordiate, points_dist);

                // calculate the lookahead point on the trajectory
                trajectory.eval(variable_s + lookahead_lat, P1x, P1y);
                P1theta = trajectory.theta(variable_s + lookahead_lat);

                // Clothoid to connect vehicle position to lookahead point
                G2lib::ClothoidCurve C1;
                C1.build_G1(vehicle_X, vehicle_Y, yaw, P1x, P1y, P1theta);
                double curvature = C1.kappaBegin(); // curvature at the beginning

                // requested steering angle
                req_steer_angle = curvature * (in->VehicleLen + K_US * pow(in->VLgtFild, 2));
            }

            if(select_latcontroller == "Previw_point"){
                double lookahead_lat = 15;     // lookahead distance [m]
                double K_e = 0.1;              // traking error coefficient
                double K_theta = 0.007;         // heading error coefficient

                // Lookahead point Ph
                G2lib::real_type Ph_x = vehicle_X + lookahead_lat * cos(yaw); // x coordinate of the lookahead point
                G2lib::real_type Ph_y = vehicle_Y + lookahead_lat * sin(yaw); // y coordinate of the lookahead point
                
                // Closest point on the trajectory
                G2lib::real_type Pp_x;     // x coordinate of point trajectory
                G2lib::real_type Pp_y;     // y coordinate of point trajectory
                G2lib::real_type Pp_theta; // theta coordinate of point trajectory
                G2lib::real_type variable_s, t_coordiate, e_p;

                trajectory.closestPoint_ISO(Ph_x, Ph_y, Pp_x, Pp_y, variable_s, t_coordiate, e_p);
                Pp_theta = trajectory.theta(variable_s);
                double e_theta = yaw - Pp_theta;

                if(vehicle_Y >= Pp_y) e_p = -e_p;

                req_steer_angle = K_e * e_p + K_theta * e_theta;
            }

            /* -------------------------------------------------------------------------------------------------------------- */

            //   _     ___  _   _  ____ ___ _____ _   _ ____ ___ _   _    _    _        ____ ___  _   _ _____ ____   ___  _
            //  | |   / _ \| \ | |/ ___|_ _|_   _| | | |  _ \_ _| \ | |  / \  | |      / ___/ _ \| \ | |_   _|  _ \ / _ \| |
            //  | |  | | | |  \| | |  _ | |  | | | | | | | | | ||  \| | / _ \ | |     | |  | | | |  \| | | | | |_) | | | | |
            //  | |__| |_| | |\  | |_| || |  | | | |_| | |_| | || |\  |/ ___ \| |___  | |__| |_| | |\  | | | |  _ <| |_| | |___
            //  |_____\___/|_| \_|\____|___| |_|  \___/|____/___|_| \_/_/   \_\_____|  \____\___/|_| \_| |_| |_| \_\\___/|_____|

            double v0 = in->VLgtFild;                    // actual longitudinal velocity
            double a0 = in->ALgtFild;                    // actual longitudinal acceleration
            double lookahead = std::max(50.0, v0 * 5.0); // lookahead distance
            double v_min = 3.0;                          // vel min to pass the traffic light
            double v_max = 15.0;                         // vel max to pass the traffic light
            double x_s = 5.0;                            // safety space before traffic light
            double x_in = 10.0;                          // length of the intersection
            double v_r = in->RequestedCruisingSpeed;     // req cruising speed of the vehicle
            double T_s = x_s / v_min;                    // time to travel the safety space
            double T_in = x_in / v_min;                  // time to safety space
            double x_tr = 0;                             // distance to the traffic light
            double x_stop = 0;                           // distance to the stop the vehicle
            double T_green = 0;                          //
            double T_red = 0;                            //
            double m_star[6], m1[6], m2[6];              // primitives
            double T1 = 0, T2 = 0, smax = 0, v1 = 0;     // usefull variable

            if (in->NrTrfLights != 0)
            {
                x_tr = in->TrfLightDist;
                x_stop = in->TrfLightDist - (x_s / 2.0);
            }

            if (in->NrTrfLights == 0 || x_tr >= lookahead)
            {
                pass_primitive(a0, v0, lookahead, &v_r, &v_r, 0.0, 0.0, m1, m2, &T1, &T2);
                copy_m(m_star, m1);
            }
            else
            {
                switch (in->TrfLightCurrState)
                {
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

                if (in->TrfLightCurrState == 1 && in->TrfLightDist <= x_s)
                {
                    pass_primitive(a0, v0, lookahead, &v_r, &v_r, 0.0, 0.0, m1, m2, &T1, &T2);
                    copy_m(m_star, m1);
                }
                else
                {
                    pass_primitive(a0, v0, x_tr, &v_min, &v_max, T_green, T_red, m1, m2, &T1, &T2);
                    if (check_0(m1) == 0 && check_0(m2) == 0)
                    {
                        stop_primitive(v0, a0, x_stop, m_star, &T1, &smax);
                    }
                    else
                    {
                        if ((m1[3] < 0 && m2[3] > 0) || (m1[3] > 0 && m2[3] < 0))
                        {
                            pass_primitivej0(v0, a0, x_tr, v_min, v_max, m_star, &T1, &v1);
                        }
                        else
                        {
                            if (abs(m1[3]) < abs(m2[3]))
                            {
                                copy_m(m_star, m1);
                            }
                            else
                            {
                                copy_m(m_star, m2);
                            }
                        }
                    }
                }
            }

            // Integrated jerk - trapezoidal - with internal a0
            static double a0_bar = 0.0;
            double minAcc = -3;
            double maxAcc = 3;

            double j_req = (DT * (jEval(0.0, m_star) + jEval(DT, m_star)) * 0.5);
            double req_acc = fmin(fmax((a0_bar + j_req),minAcc),maxAcc);

            a0_bar = req_acc;
            double v_req = v_requested(DT, m_star);

            /* -------------------------------------------------------------------------------------------------------------- */

            //   _     _____        __    _     _______     _______ _           ____ ___  _   _ _____ ____   ___  _
            //  | |   / _ \ \      / /   | |   | ____\ \   / / ____| |         / ___/ _ \| \ | |_   _|  _ \ / _ \| |
            //  | |  | | | \ \ /\ / /____| |   |  _|  \ \ / /|  _| | |   _____| |  | | | |  \| | | | | |_) | | | | |
            //  | |__| |_| |\ V  V /_____| |___| |___  \ V / | |___| |__|_____| |__| |_| | |\  | | | |  _ <| |_| | |___
            //  |_____\___/  \_/\_/      |_____|_____|  \_/  |_____|_____|     \____\___/|_| \_| |_| |_| \_\\___/|_____|

            // PID longitudinal control
            static double integral_long = 0.0;
            double P_gain_long;
            if(mode == 0) P_gain_long = 0.13;
            else P_gain_long = 0.15;
            double I_gain_long = 1.0;
            double req_pedal;
            double error_long = req_acc - a0;
            integral_long = integral_long + (error_long * DT);
            req_pedal = (P_gain_long * error_long) + (I_gain_long * integral_long);

            // Reset the memory
            if (in->VLgtFild < 0.15 && a0_bar < 0.0 && j_req > 0.0)
            {
                a0_bar = 0.0;
                integral_long = 0.0;
            }

            // Update output: requested acceleration and requested steering angle
            out->RequestedAcc = req_pedal;
            out->RequestedSteerWhlAg = req_steer_angle;

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
            logger.log_var(filename, "TrfLightDist", in->TrfLightDist);
            logger.log_var(filename, "c1", m_star[1]);
            logger.log_var(filename, "c2", m_star[2]);
            logger.log_var(filename, "c3", m_star[3]);
            logger.log_var(filename, "c4", m_star[4]);
            logger.log_var(filename, "c5", m_star[5]);

            // Write log
            logger.write_line(filename_traj);
            logger.write_line(filename);

            // Screen print
            printLogVar(message_id, "Status", in->Status);
            printLogVar(message_id, "CycleNumber", in->CycleNumber);
            printLogVar(message_id, "Time", num_seconds);
            printLogVar(message_id, "TrafficLight", in->TrfLightCurrState);
            printLogVar(message_id, "Actual velocity", in->VLgtFild);
            printLogVar(message_id, "Actual acceleration", in->ALgtFild);
            printLogVar(message_id, "Actual steering wheel", steer);
            printLogVar(message_id, "Vehicle X coordinate", vehicle_X);
            printLogVar(message_id, "Vehicle Y coordinate", vehicle_Y);
            printLogVar(message_id, "Vehicle Yaw coordinate", yaw);
            printLogVar(message_id, "Obs1 X coordinate", in->ObjX[0]);

            // Send manoeuvre message to the environment
            if (server_send_to_client(server_run, message_id, &manoeuvre_msg.data_struct) == -1)
            {
                perror("error send_message()");
                exit(EXIT_FAILURE);
            }
            else
            {
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

static void copy_m(double m1[6], double m2[6])
{
    for (int i = 0; i < 6; i++)
    {
        m1[i] = m2[i];
    }
}

static int check_0(double m[6])
{
    int tmp = 0;
    for (int i = 0; i < 6; i++)
    {
        if (m[i] != 0)
            tmp += 1;
    }
    return tmp;
}

static double jEval(double t, double m[6])
{
    double jerk = m[3] + m[4] * t + 1.0 / 2.0 * m[5] * pow(t, 2);
    return jerk;
}

static double v_requested(double t, double m[6])
{
    double vel = m[1] + m[2] * t + 1.0 / 2.0 * m[3] * pow(t, 2) + 1.0 / 6.0 * m[4] * pow(t, 3) + 1.0 / 24.0 * m[5] * pow(t, 4);
    return vel;
}

static void vehicle_position(double x0, double x_act, double offL, double offR, double *X, double *Y)
{
    *X = x0 - x_act;
    *Y = offL;
}