//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// stop_primitive.cpp
//
// Code generation for function 'stop_primitive'
//

// Include files
#include "stop_primitive.h"
#include "a_opt_mex_data.h"
#include "evalPrimitiveCoeffs.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo db_emlrtRSI{
    9,                // lineNo
    "stop_primitive", // fcnName
    "/home/giacomo/University/Autonomous_driving_simulator/basic_agent_st/"
    "matlab/stop_primitive.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    10,               // lineNo
    "stop_primitive", // fcnName
    "/home/giacomo/University/Autonomous_driving_simulator/basic_agent_st/"
    "matlab/stop_primitive.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    14,               // lineNo
    "stop_primitive", // fcnName
    "/home/giacomo/University/Autonomous_driving_simulator/basic_agent_st/"
    "matlab/stop_primitive.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    16,               // lineNo
    "stop_primitive", // fcnName
    "/home/giacomo/University/Autonomous_driving_simulator/basic_agent_st/"
    "matlab/stop_primitive.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    8,                  // lineNo
    "finalOptTimeStop", // fcnName
    "/home/giacomo/University/Autonomous_driving_simulator/basic_agent_st/"
    "matlab/finalOptTimeStop.m" // pathName
};

// Function Definitions
void stop_primitive(const emlrtStack *sp, real_T v0, real_T a0, real_T sf,
                    real_T m[6], real_T *tf, real_T *smax)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 9, 0);
  //  Stopping primitive algorithm
  if (covrtLogCond(&emlrtCoverageInstance, 9, 0, 0, v0 <= 0.0) ||
      covrtLogCond(&emlrtCoverageInstance, 9, 0, 1, sf == 0.0)) {
    covrtLogMcdc(&emlrtCoverageInstance, 9, 0, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 9, 0, 0, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 9, 0);
    *tf = 0.0;
    *smax = 0.0;
    for (int32_T i{0}; i < 6; i++) {
      m[i] = 0.0;
    }
  } else {
    real_T x;
    covrtLogMcdc(&emlrtCoverageInstance, 9, 0, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 9, 0, 0, false);
    st.site = &db_emlrtRSI;
    x = 4.0 * (v0 * v0);
    if (covrtLogIf(&emlrtCoverageInstance, 9, 0, 1, x + 5.0 * a0 * sf < 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9, 1);
      st.site = &eb_emlrtRSI;
      *smax = -(x / (5.0 * a0));
      *tf = 10.0 * *smax / (2.0 * v0);
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 9, 2);
      *smax = sf;
      st.site = &fb_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 10, 0);
      covrtLogBasicBlock(&emlrtCoverageInstance, 10, 0);
      // finalOptTimeStop
      //     OUT1 = finalOptTimeStop(V0,A0,SF)
      //     This function was generated by the Symbolic Math Toolbox
      //     version 9.2. 12-Dec-2022 17:49:35
      b_st.site = &ib_emlrtRSI;
      x += a0 * sf * 5.0;
      if (x < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      x = muDoubleScalarSqrt(x);
      *tf = sf * 10.0 / (v0 * 2.0 + x);
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 9, 3);
    st.site = &gb_emlrtRSI;
    evalPrimitiveCoeffs(v0, a0, *smax, 0.0, *tf, m);
  }
}

// End of code generation (stop_primitive.cpp)
