#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <vector>
#include "rrt.h"

// Impostazioni al momento:
// - strada lunga 180, larga 3.75
// - ostacolo dimensioni 0.5x0.5
// - macchina larga 1.26
// - offset dall'ostacolo 0.5

// int main()
// {

//   // Definisco i punti di partenza e arrivo
//   node start, goal;
//   start.p.x = 35.0;
//   start.p.y = 0.9375;
//   goal.p.x = 1800.0;
//   goal.p.y = 0.0;

//   // Definisco ostacolo
//   obstacle obs;
//   obs.cx = 900.0;
//   obs.cy = 5.0;
//   obs.lx = 5.0;
//   obs.ly = 5.0;

//   // Definisco il vettore dei punti che definiscono il path da seguire
//   std::vector<node> path_car;

//   rrt_path(start, goal, obs, path_car);

//   return 0;
// }
