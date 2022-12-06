//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// find.cpp
//
// Code generation for function 'find'
//

// Include files
#include "find.h"
#include "a_opt_mex_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo lb_emlrtRSI{
    144,        // lineNo
    "eml_find", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

static emlrtRTEInfo d_emlrtRTEI{
    392,                  // lineNo
    1,                    // colNo
    "find_first_indices", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

// Function Definitions
namespace coder {
void eml_find(const emlrtStack *sp, const boolean_T x_data[],
              const int32_T x_size[2], int32_T i_data[], int32_T i_size[2])
{
  emlrtStack st;
  int32_T idx;
  int32_T ii;
  int32_T nx;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  nx = x_size[1];
  st.site = &lb_emlrtRSI;
  idx = 0;
  i_size[0] = 1;
  i_size[1] = x_size[1];
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x_size[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (x_size[1] == 1) {
    if (idx == 0) {
      i_size[0] = 1;
      i_size[1] = 0;
    }
  } else if (idx < 1) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

} // namespace coder

// End of code generation (find.cpp)
