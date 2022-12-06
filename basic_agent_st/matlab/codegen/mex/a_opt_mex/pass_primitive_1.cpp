//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// pass_primitive_1.cpp
//
// Code generation for function 'pass_primitive_1'
//

// Include files
#include "pass_primitive_1.h"
#include "a_opt_mex_data.h"
#include "eml_setop.h"
#include "evalPrimitiveCoeffs.h"
#include "finalOptTime.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo
    c_emlrtRSI{
        71,      // lineNo
        "power", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" // pathName
    };

static emlrtRSInfo q_emlrtRSI{
    8,             // lineNo
    "finalOptVel", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\finalOptVel.m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    5,                  // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    6,                  // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo v_emlrtRSI{
    8,                  // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    9,                  // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    11,                 // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    12,                 // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    16,                 // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo bb_emlrtRSI{
    23,                 // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    25,                 // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    26,                 // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    27,                 // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    28,                 // lineNo
    "pass_primitive_1", // fcnName
    "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
    "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
    "driving\\Au"
    "tonomous_driving_simulator\\basic_agent_st\\matlab\\pass_primitive_1.m" // pathName
};

static emlrtRSInfo
    gb_emlrtRSI{
        29,                   // lineNo
        "range_intersection", // fcnName
        "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
        "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
        "driving\\Au"
        "tonomous_driving_simulator\\basic_agent_st\\matlab\\range_"
        "intersection.m" // pathName
    };

static emlrtRSInfo
    hb_emlrtRSI{
        31,                   // lineNo
        "range_intersection", // fcnName
        "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
        "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
        "driving\\Au"
        "tonomous_driving_simulator\\basic_agent_st\\matlab\\range_"
        "intersection.m" // pathName
    };

static emlrtRSInfo
    ib_emlrtRSI{
        23,      // lineNo
        "union", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\union.m" // pathName
    };

static emlrtRSInfo jb_emlrtRSI{
    70,          // lineNo
    "eml_setop", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop."
    "m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    39,     // lineNo
    "find", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    23,          // lineNo
    "intersect", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\intersect.m" // pathName
};

static emlrtBCInfo
    emlrtBCI{
        -1,                   // iFirst
        -1,                   // iLast
        41,                   // lineNo
        14,                   // colNo
        "Overlap",            // aName
        "range_intersection", // fName
        "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
        "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
        "driving\\Au"
        "tonomous_driving_simulator\\basic_agent_st\\matlab\\range_"
        "intersection.m", // pName
        0                 // checkKind
    };

static emlrtBCInfo
    b_emlrtBCI{
        -1,                   // iFirst
        -1,                   // iLast
        31,                   // lineNo
        28,                   // colNo
        "input_vector",       // aName
        "range_intersection", // fName
        "C:\\Users\\corra\\Desktop\\Universit\xc3\xa0 Tr"
        "ento\\Master degree\\2nd year\\Intelligent vehicles and autonomous "
        "driving\\Au"
        "tonomous_driving_simulator\\basic_agent_st\\matlab\\range_"
        "intersection.m", // pName
        0                 // checkKind
    };

// Function Definitions
void pass_primitive_1(const emlrtStack *sp, real_T a0, real_T v0, real_T sf,
                      real_T v_min, real_T v_max, real_T t_min, real_T t_max,
                      real_T m1[6], real_T m2[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T Overlap_data[4];
  real_T input_vector_data[4];
  real_T A[2];
  real_T B[2];
  real_T Lower_A;
  real_T Lower_B;
  real_T Upper_A;
  real_T t_bar;
  real_T v_bar;
  int32_T b_ii_data[4];
  int32_T ii_data[4];
  int32_T Overlap_size[2];
  int32_T ia_data[2];
  int32_T ib_data[2];
  int32_T ii_size[2];
  int32_T input_vector_size[2];
  int32_T x_size[2];
  int32_T ia_size;
  int32_T ib_size;
  boolean_T x_data[4];
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 6, 0);
  //  Passing primitive algorithm
  if (covrtLogIf(&emlrtCoverageInstance, 6, 0, 0, a0 >= 0.0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 6, 0);
    st.site = &t_emlrtRSI;
    t_bar = finalOptTime(&st, v0, a0, sf, v_min);
    st.site = &u_emlrtRSI;
    v_bar = finalOptTime(&st, v0, a0, sf, v_max);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 6, 1);
    st.site = &v_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 0);
    // finalOptTimeVel
    //     OUT1 = finalOptTimeVel(A0,SF)
    //     This function was generated by the Symbolic Math Toolbox version 9.1.
    //     29-Nov-2022 16:34:33
    b_st.site = &p_emlrtRSI;
    b_st.site = &p_emlrtRSI;
    v_bar = -a0 * sf;
    if (v_bar < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    v_bar = muDoubleScalarSqrt(v_bar);
    t_bar = -(3.872983346207417 * v_bar) / a0;
    st.site = &w_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
    // finalOptVel
    //     VF_BAR = finalOptVel(V0,A0,SF,T)
    //     This function was generated by the Symbolic Math Toolbox version 9.1.
    //     29-Nov-2022 16:34:32
    b_st.site = &q_emlrtRSI;
    c_st.site = &c_emlrtRSI;
    v_bar =
        ((sf * -15.0 + t_bar * v0 * 7.0) + t_bar * t_bar * a0) * -0.125 / t_bar;
    if (covrtLogCond(&emlrtCoverageInstance, 6, 0, 0, v_bar < v_min) &&
        covrtLogCond(&emlrtCoverageInstance, 6, 0, 1, v_min < v_max)) {
      covrtLogMcdc(&emlrtCoverageInstance, 6, 0, 0, true);
      covrtLogIf(&emlrtCoverageInstance, 6, 0, 1, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 6, 2);
      st.site = &x_emlrtRSI;
      t_bar = finalOptTime(&st, v0, a0, sf, v_min);
      st.site = &y_emlrtRSI;
      v_bar = finalOptTime(&st, v0, a0, sf, v_max);
    } else {
      covrtLogMcdc(&emlrtCoverageInstance, 6, 0, 0, false);
      covrtLogIf(&emlrtCoverageInstance, 6, 0, 1, false);
      if (covrtLogCond(&emlrtCoverageInstance, 6, 0, 2, v_min < v_bar) &&
          covrtLogCond(&emlrtCoverageInstance, 6, 0, 3, v_bar < v_max)) {
        covrtLogMcdc(&emlrtCoverageInstance, 6, 0, 1, true);
        covrtLogIf(&emlrtCoverageInstance, 6, 0, 2, true);
        covrtLogBasicBlock(&emlrtCoverageInstance, 6, 3);
        st.site = &ab_emlrtRSI;
        v_bar = finalOptTime(&st, v0, a0, sf, v_max);
      } else {
        covrtLogMcdc(&emlrtCoverageInstance, 6, 0, 1, false);
        covrtLogIf(&emlrtCoverageInstance, 6, 0, 2, false);
        covrtLogBasicBlock(&emlrtCoverageInstance, 6, 4);
        t_bar = 0.0;
        v_bar = 0.0;
      }
    }
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 6, 5);
  st.site = &bb_emlrtRSI;
  A[0] = t_min;
  A[1] = t_max;
  B[0] = v_bar;
  B[1] = t_bar;
  covrtLogFcn(&emlrtCoverageInstance, 7, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 7, 0);
  // A and B is a vector
  // for example A = [1 2]; B = [2 2.5];
  // find lower and upper limit for vector A and B
  if ((t_min > t_max) ||
      (muDoubleScalarIsNaN(t_min) && (!muDoubleScalarIsNaN(t_max)))) {
    Lower_A = t_max;
  } else {
    Lower_A = t_min;
  }
  if ((t_min < t_max) ||
      (muDoubleScalarIsNaN(t_min) && (!muDoubleScalarIsNaN(t_max)))) {
    Upper_A = t_max;
  } else {
    Upper_A = t_min;
  }
  if ((v_bar > t_bar) ||
      (muDoubleScalarIsNaN(v_bar) && (!muDoubleScalarIsNaN(t_bar)))) {
    Lower_B = t_bar;
  } else {
    Lower_B = v_bar;
  }
  if ((v_bar < t_bar) ||
      (muDoubleScalarIsNaN(v_bar) && (!muDoubleScalarIsNaN(t_bar)))) {
    v_bar = t_bar;
  }
  // check condition of lower and upper limit both vector
  // this part is to determine lower limit
  if (covrtLogCond(&emlrtCoverageInstance, 7, 0, 0, Lower_A > Lower_B) ||
      covrtLogCond(&emlrtCoverageInstance, 7, 0, 1, Lower_A == Lower_B)) {
    covrtLogMcdc(&emlrtCoverageInstance, 7, 0, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 7, 0, 0, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 7, 1);
    Lower_B = Lower_A;
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 7, 0, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 7, 0, 0, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 7, 2);
  }
  // this part is to determine upper limit
  if (covrtLogCond(&emlrtCoverageInstance, 7, 0, 2, Upper_A > v_bar) ||
      covrtLogCond(&emlrtCoverageInstance, 7, 0, 3, Upper_A == v_bar)) {
    covrtLogMcdc(&emlrtCoverageInstance, 7, 0, 1, true);
    covrtLogIf(&emlrtCoverageInstance, 7, 0, 1, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 7, 3);
    Upper_A = v_bar;
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 7, 0, 1, false);
    covrtLogIf(&emlrtCoverageInstance, 7, 0, 1, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 7, 4);
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 7, 5);
  // merge all vectors
  b_st.site = &gb_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  d_st.site = &jb_emlrtRSI;
  coder::do_vectors(&d_st, A, B, input_vector_data, input_vector_size, ia_data,
                    &ia_size, ib_data, &ib_size);
  x_size[1] = input_vector_size[1];
  ia_size = input_vector_size[1];
  for (int32_T i{0}; i < ia_size; i++) {
    x_data[i] = (input_vector_data[i] != 0.0);
  }
  y = (input_vector_size[1] != 0);
  if (y) {
    boolean_T exitg1;
    ia_size = 0;
    exitg1 = false;
    while ((!exitg1) && (ia_size <= x_size[1] - 1)) {
      if (!x_data[ia_size]) {
        y = false;
        exitg1 = true;
      } else {
        ia_size++;
      }
    }
  }
  if (covrtLogIf(&emlrtCoverageInstance, 7, 0, 2, y)) {
    real_T c_data[4];
    real_T c_ii_data[4];
    covrtLogBasicBlock(&emlrtCoverageInstance, 7, 6);
    b_st.site = &hb_emlrtRSI;
    x_size[0] = 1;
    x_size[1] = input_vector_size[1];
    ia_size = input_vector_size[1];
    for (int32_T i{0}; i < ia_size; i++) {
      x_data[i] = (input_vector_data[i] >= Lower_B);
    }
    c_st.site = &kb_emlrtRSI;
    coder::eml_find(&c_st, x_data, x_size, ii_data, ia_data);
    b_st.site = &hb_emlrtRSI;
    x_size[0] = 1;
    x_size[1] = input_vector_size[1];
    ia_size = input_vector_size[1];
    for (int32_T i{0}; i < ia_size; i++) {
      x_data[i] = (input_vector_data[i] <= Upper_A);
    }
    c_st.site = &kb_emlrtRSI;
    coder::eml_find(&c_st, x_data, x_size, b_ii_data, ib_data);
    b_st.site = &hb_emlrtRSI;
    c_st.site = &mb_emlrtRSI;
    Overlap_size[0] = 1;
    Overlap_size[1] = ia_data[1];
    ia_size = ia_data[1];
    for (int32_T i{0}; i < ia_size; i++) {
      Overlap_data[i] = ii_data[i];
    }
    ii_size[0] = 1;
    ii_size[1] = ib_data[1];
    ia_size = ib_data[1];
    for (int32_T i{0}; i < ia_size; i++) {
      c_ii_data[i] = b_ii_data[i];
    }
    d_st.site = &jb_emlrtRSI;
    coder::do_vectors(&d_st, Overlap_data, Overlap_size, c_ii_data, ii_size,
                      c_data, ia_data, ii_data, &ia_size, b_ii_data, &ib_size);
    Overlap_size[1] = ia_data[1];
    ia_size = ia_data[1];
    for (int32_T i{0}; i < ia_size; i++) {
      ib_size = static_cast<int32_T>(c_data[i]);
      if ((ib_size < 1) || (ib_size > input_vector_size[1])) {
        emlrtDynamicBoundsCheckR2012b(ib_size, 1, input_vector_size[1],
                                      &b_emlrtBCI, &st);
      }
      Overlap_data[i] = input_vector_data[ib_size - 1];
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 7, 7);
    Overlap_size[1] = 2;
    Overlap_data[0] = 0.0;
    Overlap_data[1] = 0.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 7, 0, 3, Overlap_size[1] == 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 7, 8);
    Overlap_size[1] = 2;
    Overlap_data[0] = 0.0;
    Overlap_data[1] = 0.0;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 7, 9);
  if (Overlap_size[1] < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, Overlap_size[1], &emlrtBCI, &st);
  }
  if (covrtLogCond(&emlrtCoverageInstance, 6, 0, 4, Overlap_data[0] > 0.0) &&
      covrtLogCond(&emlrtCoverageInstance, 6, 0, 5,
                   Overlap_data[0] <= Overlap_data[1])) {
    covrtLogMcdc(&emlrtCoverageInstance, 6, 0, 2, true);
    covrtLogIf(&emlrtCoverageInstance, 6, 0, 3, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 6, 6);
    st.site = &cb_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
    // finalOptVel
    //     VF_BAR = finalOptVel(V0,A0,SF,T)
    //     This function was generated by the Symbolic Math Toolbox version 9.1.
    //     29-Nov-2022 16:34:32
    b_st.site = &q_emlrtRSI;
    c_st.site = &c_emlrtRSI;
    st.site = &db_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
    // finalOptVel
    //     VF_BAR = finalOptVel(V0,A0,SF,T)
    //     This function was generated by the Symbolic Math Toolbox version 9.1.
    //     29-Nov-2022 16:34:32
    b_st.site = &q_emlrtRSI;
    c_st.site = &c_emlrtRSI;
    st.site = &eb_emlrtRSI;
    evalPrimitiveCoeffs(v0, a0, sf,
                        ((sf * -15.0 + Overlap_data[0] * v0 * 7.0) +
                         Overlap_data[0] * Overlap_data[0] * a0) *
                            -0.125 / Overlap_data[0],
                        Overlap_data[0], m1);
    st.site = &fb_emlrtRSI;
    evalPrimitiveCoeffs(v0, a0, sf,
                        ((sf * -15.0 + Overlap_data[1] * v0 * 7.0) +
                         Overlap_data[1] * Overlap_data[1] * a0) *
                            -0.125 / Overlap_data[1],
                        Overlap_data[1], m2);
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 6, 0, 2, false);
    covrtLogIf(&emlrtCoverageInstance, 6, 0, 3, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 6, 7);
    for (int32_T i{0}; i < 6; i++) {
      m1[i] = 0.0;
      m2[i] = 0.0;
    }
  }
}

// End of code generation (pass_primitive_1.cpp)
