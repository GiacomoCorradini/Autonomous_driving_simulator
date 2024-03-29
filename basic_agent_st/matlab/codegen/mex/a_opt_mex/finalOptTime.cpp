//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// finalOptTime.cpp
//
// Code generation for function 'finalOptTime'
//

// Include files
#include "finalOptTime.h"
#include "a_opt_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo o_emlrtRSI{
    8,              // lineNo
    "finalOptTime", // fcnName
    "/home/giacomo/University/Autonomous_driving_simulator/basic_agent_st/"
    "matlab/finalOptTime.m" // pathName
};

// Function Definitions
real_T finalOptTime(const emlrtStack *sp, real_T v0, real_T a0, real_T sf,
                    real_T vf)
{
  emlrtStack st;
  real_T x;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 0);
  // finalOptTime
  //     OUT1 = finalOptTime(V0,A0,SF,VF)
  //     This function was generated by the Symbolic Math Toolbox version 9.2.
  //     12-Dec-2022 17:49:36
  st.site = &o_emlrtRSI;
  x = ((a0 * sf * 60.0 + v0 * vf * 112.0) + v0 * v0 * 49.0) + vf * vf * 64.0;
  if (x < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  x = muDoubleScalarSqrt(x);
  return sf * 30.0 / ((v0 * 7.0 + vf * 8.0) + x);
}

// End of code generation (finalOptTime.cpp)
