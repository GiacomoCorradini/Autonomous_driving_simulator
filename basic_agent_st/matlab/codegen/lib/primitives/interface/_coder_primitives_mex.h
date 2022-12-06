//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_primitives_mex.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 02-Dec-2022 09:30:20
//

#ifndef _CODER_PRIMITIVES_MEX_H
#define _CODER_PRIMITIVES_MEX_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_a_opt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[7]);

void unsafe_pass_primitive_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                       int32_T nrhs, const mxArray *prhs[7]);

void unsafe_pass_primitivej0_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                         int32_T nrhs, const mxArray *prhs[5]);

void unsafe_stop_primitive_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                       int32_T nrhs, const mxArray *prhs[3]);

void unsafe_stop_primitivej0_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                         int32_T nrhs, const mxArray *prhs[2]);

void unsafe_v_opt_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                              const mxArray *prhs[7]);

#endif
//
// File trailer for _coder_primitives_mex.h
//
// [EOF]
//
