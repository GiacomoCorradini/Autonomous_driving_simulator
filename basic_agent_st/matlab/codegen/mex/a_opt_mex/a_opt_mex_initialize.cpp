//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// a_opt_mex_initialize.cpp
//
// Code generation for function 'a_opt_mex_initialize'
//

// Include files
#include "a_opt_mex_initialize.h"
#include "_coder_a_opt_mex_mex.h"
#include "a_opt_mex_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static void a_opt_mex_once();

// Function Definitions
static void a_opt_mex_once()
{
  const int32_T postfix_exprs_11_0[3]{0, 1, -2};
  const int32_T postfix_exprs_13_0[3]{0, 1, -3};
  const int32_T postfix_exprs_1_0[3]{0, 1, -3};
  const int32_T postfix_exprs_1_1[3]{0, 1, -3};
  const int32_T postfix_exprs_1_2[3]{0, 1, -3};
  const int32_T postfix_exprs_1_3[3]{0, 1, -3};
  const int32_T postfix_exprs_6_0[3]{0, 1, -3};
  const int32_T postfix_exprs_6_1[3]{0, 1, -3};
  const int32_T postfix_exprs_6_2[3]{0, 1, -3};
  const int32_T postfix_exprs_7_0[3]{0, 1, -2};
  const int32_T postfix_exprs_7_1[3]{0, 1, -2};
  const int32_T postfix_exprs_8_0[3]{0, 1, -3};
  const int32_T postfix_exprs_8_1[3]{0, 1, -3};
  const int32_T cond_ends_11_0[2]{86, 99};
  const int32_T cond_ends_13_0[2]{96, 108};
  const int32_T cond_ends_1_0[2]{329, 348};
  const int32_T cond_ends_1_1[2]{494, 513};
  const int32_T cond_ends_1_2[2]{730, 744};
  const int32_T cond_ends_1_3[2]{884, 898};
  const int32_T cond_ends_6_0[2]{331, 350};
  const int32_T cond_ends_6_1[2]{496, 515};
  const int32_T cond_ends_6_2[2]{796, 810};
  const int32_T cond_ends_7_0[2]{347, 369};
  const int32_T cond_ends_7_1[2]{496, 518};
  const int32_T cond_ends_8_0[2]{211, 229};
  const int32_T cond_ends_8_1[2]{393, 411};
  const int32_T cond_starts_11_0[2]{79, 92};
  const int32_T cond_starts_13_0[2]{90, 102};
  const int32_T cond_starts_1_0[2]{316, 335};
  const int32_T cond_starts_1_1[2]{481, 500};
  const int32_T cond_starts_1_2[2]{720, 734};
  const int32_T cond_starts_1_3[2]{878, 890};
  const int32_T cond_starts_6_0[2]{318, 337};
  const int32_T cond_starts_6_1[2]{483, 502};
  const int32_T cond_starts_6_2[2]{790, 802};
  const int32_T cond_starts_7_0[2]{330, 351};
  const int32_T cond_starts_7_1[2]{479, 500};
  const int32_T cond_starts_8_0[2]{199, 217};
  const int32_T cond_starts_8_1[2]{381, 399};
  mex_InitInfAndNan();
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
                  "ento\\Master degree\\2nd year\\Intelligent vehicles and "
                  "autonomous driving\\Au"
                  "tonomous_driving_simulator\\basic_agent_st\\matlab\\a_opt.m",
                  0U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "a_opt", 0, -1, 464);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 190, -1, 463);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m",
      1U, 1U, 9U, 5U, 0U, 0U, 0U, 0U, 0U, 8U, 4U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "pass_primitive", 32, -1, 1235);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 8U, 1111, -1, 1226);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 7U, 908, -1, 1093);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 804, -1, 859);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 753, -1, 786);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 635, -1, 676);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 531, -1, 601);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 362, -1, 451);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 227, -1, 303);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 124, -1, 209);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 105, 115, 214, 712);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 312, 349, 460, 704);
  covrtIfInit(&emlrtCoverageInstance, 1U, 2U, 477, 514, 614, 692);
  covrtIfInit(&emlrtCoverageInstance, 1U, 3U, 717, 744, 791, 869);
  covrtIfInit(&emlrtCoverageInstance, 1U, 4U, 874, 899, 1098, 1235);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 0U, 315, 349, 2, 0,
                *(int32_T(*)[2]) & cond_starts_1_0[0],
                *(int32_T(*)[2]) & cond_ends_1_0[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_1_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 1U, 480, 514, 2, 2,
                *(int32_T(*)[2]) & cond_starts_1_1[0],
                *(int32_T(*)[2]) & cond_ends_1_1[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_1_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 2U, 720, 744, 2, 4,
                *(int32_T(*)[2]) & cond_starts_1_2[0],
                *(int32_T(*)[2]) & cond_ends_1_2[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_1_2[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 3U, 877, 899, 2, 6,
                *(int32_T(*)[2]) & cond_starts_1_3[0],
                *(int32_T(*)[2]) & cond_ends_1_3[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_1_3[0]);
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 1U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\finalOptTime.m",
      2U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "finalOptTime", 0, -1, 302);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 197, -1, 301);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 2U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\finalOptTimeVel.m",
      3U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U, "finalOptTimeVel", 0, -1, 237);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 194, -1, 236);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 3U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\finalOptVel.m",
      4U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 4U, 0U, "finalOptVel", 0, -1, 258);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 0U, 196, -1, 257);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 4U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
                  "ento\\Master degree\\2nd year\\Intelligent vehicles and "
                  "autonomous driving\\Au"
                  "tonomous_driving_simulator\\basic_agent_"
                  "st\\matlab\\evalPrimitiveCoeffs.m",
                  5U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 5U, 0U, "evalPrimitiveCoeffs", 0, -1,
               492);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 0U, 222, -1, 491);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 5U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m",
      6U, 1U, 8U, 4U, 0U, 0U, 0U, 0U, 0U, 6U, 3U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 6U, 0U, "pass_primitive_1", 32, -1,
               1147);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 7U, 1023, -1, 1138);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 6U, 820, -1, 1005);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 5U, 719, -1, 781);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 4U, 637, -1, 678);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 3U, 533, -1, 603);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 2U, 364, -1, 453);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 1U, 229, -1, 305);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 0U, 126, -1, 211);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 6U, 0U, 107, 117, 216, 714);
  covrtIfInit(&emlrtCoverageInstance, 6U, 1U, 314, 351, 462, 706);
  covrtIfInit(&emlrtCoverageInstance, 6U, 2U, 479, 516, 616, 694);
  covrtIfInit(&emlrtCoverageInstance, 6U, 3U, 786, 811, 1010, 1147);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 6U, 0U, 317, 351, 2, 0,
                *(int32_T(*)[2]) & cond_starts_6_0[0],
                *(int32_T(*)[2]) & cond_ends_6_0[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_6_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 6U, 1U, 482, 516, 2, 2,
                *(int32_T(*)[2]) & cond_starts_6_1[0],
                *(int32_T(*)[2]) & cond_ends_6_1[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_6_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 6U, 2U, 789, 811, 2, 4,
                *(int32_T(*)[2]) & cond_starts_6_2[0],
                *(int32_T(*)[2]) & cond_ends_6_2[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_6_2[0]);
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 6U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
                  "ento\\Master degree\\2nd year\\Intelligent vehicles and "
                  "autonomous driving\\Au"
                  "tonomous_driving_simulator\\basic_agent_st\\matlab\\range_"
                  "intersection.m",
                  7U, 1U, 10U, 4U, 0U, 0U, 0U, 0U, 0U, 4U, 2U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 7U, 0U, "range_intersection", 0, -1,
               871);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 9U, 833, -1, 866);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 8U, 810, -1, 827);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 7U, 764, -1, 780);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 6U, 659, -1, 754);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 5U, 604, -1, 630);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 4U, 558, -1, 578);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 3U, 524, -1, 544);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 2U, 409, -1, 429);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 1U, 375, -1, 395);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 0U, 154, -1, 229);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 7U, 0U, 326, 370, 400, 434);
  covrtIfInit(&emlrtCoverageInstance, 7U, 1U, 475, 519, 549, 583);
  covrtIfInit(&emlrtCoverageInstance, 7U, 2U, 632, 654, 755, 784);
  covrtIfInit(&emlrtCoverageInstance, 7U, 3U, 786, 805, -1, 831);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 7U, 0U, 330, 369, 2, 0,
                *(int32_T(*)[2]) & cond_starts_7_0[0],
                *(int32_T(*)[2]) & cond_ends_7_0[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_7_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 7U, 1U, 479, 518, 2, 2,
                *(int32_T(*)[2]) & cond_starts_7_1[0],
                *(int32_T(*)[2]) & cond_ends_7_1[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_7_1[0]);
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 7U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitivej0.m",
      8U, 1U, 5U, 2U, 0U, 0U, 0U, 0U, 0U, 4U, 2U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 8U, 0U, "pass_primitivej0", 44, -1, 607);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 4U, 526, -1, 587);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 3U, 425, -1, 500);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 2U, 328, -1, 368);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 1U, 239, -1, 310);
  covrtBasicBlockInit(&emlrtCoverageInstance, 8U, 0U, 112, -1, 190);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 8U, 0U, 195, 230, 315, 607);
  covrtIfInit(&emlrtCoverageInstance, 8U, 1U, 377, 412, 509, 599);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 8U, 0U, 198, 230, 2, 0,
                *(int32_T(*)[2]) & cond_starts_8_0[0],
                *(int32_T(*)[2]) & cond_ends_8_0[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_8_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 8U, 1U, 380, 412, 2, 2,
                *(int32_T(*)[2]) & cond_starts_8_1[0],
                *(int32_T(*)[2]) & cond_ends_8_1[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_8_1[0]);
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 8U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\finalOptTimej0.m",
      9U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 9U, 0U, "finalOptTimej0", 0, -1, 370);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 9U, 0U, 201, -1, 369);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 9U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\finalOptVelj0.m",
      10U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 10U, 0U, "finalOptVelj0", 0, -1, 269);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 10U, 0U, 200, -1, 268);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 10U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\stop_primitive.m",
      11U, 1U, 4U, 2U, 0U, 0U, 0U, 0U, 0U, 2U, 1U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 11U, 0U, "stop_primitive", 33, -1, 502);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 3U, 449, -1, 494);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 2U, 371, -1, 428);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 1U, 215, -1, 276);
  covrtBasicBlockInit(&emlrtCoverageInstance, 11U, 0U, 109, -1, 160);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 11U, 0U, 75, 100, 165, 502);
  covrtIfInit(&emlrtCoverageInstance, 11U, 1U, 178, 202, 285, 440);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 11U, 0U, 78, 100, 2, 0,
                *(int32_T(*)[2]) & cond_starts_11_0[0],
                *(int32_T(*)[2]) & cond_ends_11_0[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_11_0[0]);
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 11U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\finalOptTimeStop.m",
      12U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 12U, 0U, "finalOptTimeStop", 0, -1, 264);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 12U, 0U, 203, -1, 263);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 12U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\stop_primitivej0.m",
      13U, 1U, 2U, 1U, 0U, 0U, 0U, 0U, 0U, 2U, 1U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 13U, 0U, "stop_primitivej0", 45, -1,
               316);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 1U, 258, -1, 308);
  covrtBasicBlockInit(&emlrtCoverageInstance, 13U, 0U, 118, -1, 240);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 13U, 0U, 86, 109, 245, 316);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 13U, 0U, 89, 109, 2, 0,
                *(int32_T(*)[2]) & cond_starts_13_0[0],
                *(int32_T(*)[2]) & cond_ends_13_0[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_13_0[0]);
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 13U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
                  "ento\\Master degree\\2nd year\\Intelligent vehicles and "
                  "autonomous driving\\Au"
                  "tonomous_driving_simulator\\basic_agent_"
                  "st\\matlab\\finalOptTimeStopj0.m",
                  14U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 14U, 0U, "finalOptTimeStopj0", 0, -1,
               226);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 14U, 0U, 203, -1, 225);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 14U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
      "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
      "driving\\Au"
      "tonomous_driving_simulator\\basic_agent_st\\matlab\\finalOptPosj0.m",
      15U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 15U, 0U, "finalOptPosj0", 0, -1, 237);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 15U, 0U, 194, -1, 236);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 15U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
                  "ento\\Master degree\\2nd year\\Intelligent vehicles and "
                  "autonomous driving\\Au"
                  "tonomous_driving_simulator\\basic_agent_st\\matlab\\v_opt.m",
                  16U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 16U, 0U, "v_opt", 0, -1, 484);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 16U, 0U, 190, -1, 483);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 16U);
}

void a_opt_mex_initialize()
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    a_opt_mex_once();
  }
}

// End of code generation (a_opt_mex_initialize.cpp)
