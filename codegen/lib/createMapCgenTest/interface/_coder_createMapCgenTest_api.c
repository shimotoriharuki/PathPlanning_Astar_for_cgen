/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_createMapCgenTest_api.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 26-Mar-2021 19:12:49
 */

/* Include Files */
#include "_coder_createMapCgenTest_api.h"
#include "_coder_createMapCgenTest_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131610U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "createMapCgenTest",                                  /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const struct0_T u[9]);

/* Function Definitions */
/*
 * Arguments    : const struct0_T u[9]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const struct0_T u[9])
{
  static const int32_T iv1[2] = {1, 2};
  static const char_T *sv[3] = {"obstacle", "status", "parent"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  const struct0_T *r;
  int32_T iv[2];
  int32_T i;
  uint16_T b_u;
  uint8_T u_idx_0;
  uint8_T u_idx_1;
  uint8_T *pData;
  y = NULL;
  iv[0] = 3;
  iv[1] = 3;
  emlrtAssign(&y,
              emlrtCreateStructArray(2, &iv[0], 3, (const char_T **)&sv[0]));
  for (i = 0; i < 9; i++) {
    r = &u[i];
    b_u = r->obstacle;
    b_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT16_CLASS, mxREAL);
    *(uint16_T *)emlrtMxGetData(m) = b_u;
    emlrtAssign(&b_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"obstacle", b_y, 0);
    b_u = r->status;
    c_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxUINT16_CLASS, mxREAL);
    *(uint16_T *)emlrtMxGetData(m) = b_u;
    emlrtAssign(&c_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"status", c_y, 1);
    u_idx_0 = r->parent[0];
    u_idx_1 = r->parent[1];
    d_y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxUINT8_CLASS,
                                mxREAL);
    pData = (uint8_T *)emlrtMxGetData(m);
    *pData = u_idx_0;
    pData[1] = u_idx_1;
    emlrtAssign(&d_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"parent", d_y, 2);
  }
  return y;
}

/*
 * Arguments    : const mxArray **plhs
 * Return Type  : void
 */
void createMapCgenTest_api(const mxArray **plhs)
{
  struct0_T ret[9];
  /* Invoke the target function */
  createMapCgenTest(ret);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(ret);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void createMapCgenTest_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  createMapCgenTest_xil_terminate();
  createMapCgenTest_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void createMapCgenTest_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void createMapCgenTest_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_createMapCgenTest_api.c
 *
 * [EOF]
 */