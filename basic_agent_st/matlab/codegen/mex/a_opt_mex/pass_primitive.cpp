//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// pass_primitive.cpp
//
// Code generation for function 'pass_primitive'
//

// Include files
#include "pass_primitive.h"
#include "a_opt_mex_data.h"
#include "evalPrimitiveCoeffs.h"
#include "finalOptTime.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo d_emlrtRSI{
    5,                // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    6,                // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    8,                // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    9,                // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    11,               // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    12,               // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    16,               // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    31,               // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    32,               // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    33,               // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    34,               // lineNo
    "pass_primitive", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive.m" // pathName
};

// Function Definitions
void pass_primitive(const emlrtStack *sp, real_T a0, real_T v0, real_T sf,
                    real_T v_min, real_T v_max, real_T t_min, real_T t_max,
                    real_T m1[6], real_T m2[6])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T t_bar;
  real_T v_bar;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 1, 0);
  //  Passing primitive algorithm
  if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, a0 >= 0.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 0);
    st.site = &d_emlrtRSI;
    t_bar = finalOptTime(&st, v0, a0, sf, v_min);
    st.site = &e_emlrtRSI;
    v_bar = finalOptTime(&st, v0, a0, sf, v_max);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 1);
    st.site = &f_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 0);
    // finalOptTimeVel
    //     OUT1 = finalOptTimeVel(A0,SF)
    //     This function was generated by the Symbolic Math Toolbox version 9.1.
    //     29-Nov-2022 16:34:33
    b_st.site = &p_emlrtRSI;
    v_bar = -a0 * sf;
    if (v_bar < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    v_bar = muDoubleScalarSqrt(v_bar);
    t_bar = -(3.872983346207417 * v_bar) / a0;
    st.site = &g_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
    // finalOptVel
    //     VF_BAR = finalOptVel(V0,A0,SF,T)
    //     This function was generated by the Symbolic Math Toolbox version 9.1.
    //     29-Nov-2022 16:34:32
    v_bar =
        ((sf * -15.0 + t_bar * v0 * 7.0) + t_bar * t_bar * a0) * -0.125 / t_bar;
    if (covrtLogCond(&emlrtCoverageInstance, 1, 0, 0, v_bar < v_min) &&
        covrtLogCond(&emlrtCoverageInstance, 1, 0, 1, v_min < v_max)) {
      covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 0, true);
      covrtLogIf(&emlrtCoverageInstance, 1, 0, 1, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 2);
      st.site = &h_emlrtRSI;
      t_bar = finalOptTime(&st, v0, a0, sf, v_min);
      st.site = &i_emlrtRSI;
      v_bar = finalOptTime(&st, v0, a0, sf, v_max);
    } else {
      covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 0, false);
      covrtLogIf(&emlrtCoverageInstance, 1, 0, 1, false);
      if (covrtLogCond(&emlrtCoverageInstance, 1, 0, 2, v_min < v_bar) &&
          covrtLogCond(&emlrtCoverageInstance, 1, 0, 3, v_bar < v_max)) {
        covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 1, true);
        covrtLogIf(&emlrtCoverageInstance, 1, 0, 2, true);
        covrtLogBasicBlock(&emlrtCoverageInstance, 1, 3);
        st.site = &j_emlrtRSI;
        v_bar = finalOptTime(&st, v0, a0, sf, v_max);
      } else {
        covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 1, false);
        covrtLogIf(&emlrtCoverageInstance, 1, 0, 2, false);
        covrtLogBasicBlock(&emlrtCoverageInstance, 1, 4);
        t_bar = 0.0;
        v_bar = 0.0;
      }
    }
  }
  if (covrtLogCond(&emlrtCoverageInstance, 1, 0, 4, t_min == 0.0) &&
      covrtLogCond(&emlrtCoverageInstance, 1, 0, 5, t_max == 0.0)) {
    covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 2, true);
    covrtLogIf(&emlrtCoverageInstance, 1, 0, 3, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 5);
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 2, false);
    covrtLogIf(&emlrtCoverageInstance, 1, 0, 3, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 6);
    v_bar = muDoubleScalarMax(v_bar, t_min);
    t_bar = muDoubleScalarMin(t_bar, t_max);
  }
  if (covrtLogCond(&emlrtCoverageInstance, 1, 0, 6, v_bar > 0.0) &&
      covrtLogCond(&emlrtCoverageInstance, 1, 0, 7, v_bar <= t_bar)) {
    covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 3, true);
    covrtLogIf(&emlrtCoverageInstance, 1, 0, 4, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 7);
    st.site = &k_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
    // finalOptVel
    //     VF_BAR = finalOptVel(V0,A0,SF,T)
    //     This function was generated by the Symbolic Math Toolbox version 9.1.
    //     29-Nov-2022 16:34:32
    st.site = &l_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
    // finalOptVel
    //     VF_BAR = finalOptVel(V0,A0,SF,T)
    //     This function was generated by the Symbolic Math Toolbox version 9.1.
    //     29-Nov-2022 16:34:32
    st.site = &m_emlrtRSI;
    evalPrimitiveCoeffs(v0, a0, sf,
                        ((sf * -15.0 + v_bar * v0 * 7.0) + v_bar * v_bar * a0) *
                            -0.125 / v_bar,
                        v_bar, m1);
    st.site = &n_emlrtRSI;
    evalPrimitiveCoeffs(v0, a0, sf,
                        ((sf * -15.0 + t_bar * v0 * 7.0) + t_bar * t_bar * a0) *
                            -0.125 / t_bar,
                        t_bar, m2);
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 3, false);
    covrtLogIf(&emlrtCoverageInstance, 1, 0, 4, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 8);
    for (int32_T i{0}; i < 6; i++) {
      m1[i] = 0.0;
      m2[i] = 0.0;
    }
  }
}

// End of code generation (pass_primitive.cpp)
