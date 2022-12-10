//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_primitives_api.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 06-Dec-2022 22:21:22
//

// Include Files
#include "_coder_primitives_api.h"
#include "_coder_primitives_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131626U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "primitives",                                         // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const real_T u[6]);

static const mxArray *emlrt_marshallOut(const real_T u);

// Function Definitions
//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *t
//                const char_T *identifier
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *t,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(t), &thisId);
  emlrtDestroyArray(&t);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const real_T u[6]
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const real_T u[6])
{
  static const int32_T iv[2]{0, 0};
  static const int32_T iv1[2]{1, 6};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const real_T u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const mxArray * const prhs[7]
//                const mxArray **plhs
// Return Type  : void
//
void a_opt_api(const mxArray *const prhs[7], const mxArray **plhs)
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T T;
  real_T a0;
  real_T af;
  real_T sf;
  real_T t;
  real_T v0;
  real_T vf;
  st.tls = emlrtRootTLSGlobal;
  // Marshall function inputs
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "sf");
  vf = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "vf");
  af = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "af");
  T = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "T");
  // Invoke the target function
  t = a_opt(t, v0, a0, sf, vf, af, T);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(t);
}

//
// Arguments    : const mxArray * const prhs[7]
//                int32_T nlhs
//                const mxArray *plhs[4]
// Return Type  : void
//
void pass_primitive_api(const mxArray *const prhs[7], int32_T nlhs,
                        const mxArray *plhs[4])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*m1)[6];
  real_T(*m2)[6];
  real_T a0;
  real_T sf;
  real_T t1;
  real_T t2;
  real_T t_max;
  real_T t_min;
  real_T v0;
  real_T v_max;
  real_T v_min;
  st.tls = emlrtRootTLSGlobal;
  m1 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  m2 = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  // Marshall function inputs
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "a0");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  v_min = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "v_min");
  v_max = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "v_max");
  t_min = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "t_min");
  t_max = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "t_max");
  // Invoke the target function
  pass_primitive(a0, v0, sf, v_min, v_max, t_min, t_max, *m1, *m2, &t1, &t2);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(*m1);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*m2);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(t1);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(t2);
  }
}

//
// Arguments    : const mxArray * const prhs[5]
//                int32_T nlhs
//                const mxArray *plhs[3]
// Return Type  : void
//
void pass_primitivej0_api(const mxArray *const prhs[5], int32_T nlhs,
                          const mxArray *plhs[3])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*m)[6];
  real_T a0;
  real_T sf;
  real_T tfj0;
  real_T v0;
  real_T v_max;
  real_T v_min;
  real_T vfj0;
  st.tls = emlrtRootTLSGlobal;
  m = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  // Marshall function inputs
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  v_min = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "v_min");
  v_max = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "v_max");
  // Invoke the target function
  pass_primitivej0(v0, a0, sf, v_min, v_max, *m, &tfj0, &vfj0);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(*m);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(tfj0);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(vfj0);
  }
}

//
// Arguments    : void
// Return Type  : void
//
void primitives_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  primitives_xil_terminate();
  primitives_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void primitives_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void primitives_terminate()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// Arguments    : const mxArray * const prhs[3]
//                int32_T nlhs
//                const mxArray *plhs[3]
// Return Type  : void
//
void stop_primitive_api(const mxArray *const prhs[3], int32_T nlhs,
                        const mxArray *plhs[3])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*m)[6];
  real_T a0;
  real_T sf;
  real_T smax;
  real_T tf;
  real_T v0;
  st.tls = emlrtRootTLSGlobal;
  m = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  // Marshall function inputs
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sf");
  // Invoke the target function
  stop_primitive(v0, a0, sf, *m, &tf, &smax);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(*m);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(tf);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(smax);
  }
}

//
// Arguments    : const mxArray * const prhs[2]
//                int32_T nlhs
//                const mxArray *plhs[3]
// Return Type  : void
//
void stop_primitivej0_api(const mxArray *const prhs[2], int32_T nlhs,
                          const mxArray *plhs[3])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*m)[6];
  real_T T;
  real_T a0;
  real_T smax;
  real_T v0;
  st.tls = emlrtRootTLSGlobal;
  m = (real_T(*)[6])mxMalloc(sizeof(real_T[6]));
  // Marshall function inputs
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a0");
  // Invoke the target function
  stop_primitivej0(v0, a0, *m, &T, &smax);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(*m);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(T);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(smax);
  }
}

//
// Arguments    : const mxArray * const prhs[7]
//                const mxArray **plhs
// Return Type  : void
//
void v_opt_api(const mxArray *const prhs[7], const mxArray **plhs)
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T T;
  real_T a0;
  real_T af;
  real_T sf;
  real_T t;
  real_T v0;
  real_T vf;
  st.tls = emlrtRootTLSGlobal;
  // Marshall function inputs
  t = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t");
  v0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "v0");
  a0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "a0");
  sf = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "sf");
  vf = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "vf");
  af = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "af");
  T = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "T");
  // Invoke the target function
  t = v_opt(t, v0, a0, sf, vf, af, T);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(t);
}

//
// File trailer for _coder_primitives_api.cpp
//
// [EOF]
//
