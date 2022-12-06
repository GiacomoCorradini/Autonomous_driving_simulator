//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eml_setop.h
//
// Code generation for function 'eml_setop'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
void do_vectors(const emlrtStack *sp, const real_T a[2], const real_T b[2],
                real_T c_data[], int32_T c_size[2], int32_T ia_data[],
                int32_T *ia_size, int32_T ib_data[], int32_T *ib_size);

void do_vectors(const emlrtStack *sp, const real_T a_data[],
                const int32_T a_size[2], const real_T b_data[],
                const int32_T b_size[2], real_T c_data[], int32_T c_size[2],
                int32_T ia_data[], int32_T *ia_size, int32_T ib_data[],
                int32_T *ib_size);

} // namespace coder

// End of code generation (eml_setop.h)
