//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// issorted.cpp
//
// Code generation for function 'issorted'
//

// Include files
#include "issorted.h"
#include "a_opt_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder {
boolean_T issorted(const real_T x_data[], const int32_T x_size[2])
{
  boolean_T y;
  y = true;
  if ((x_size[1] != 0) && (x_size[1] != 1)) {
    int32_T k;
    boolean_T exitg1;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x_size[1] - 2)) {
      real_T v_idx_1;
      v_idx_1 = x_data[k + 1];
      if ((x_data[k] <= v_idx_1) || muDoubleScalarIsNaN(v_idx_1)) {
        k++;
      } else {
        y = false;
        exitg1 = true;
      }
    }
  }
  return y;
}

} // namespace coder

// End of code generation (issorted.cpp)
