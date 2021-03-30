/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_createMapCgenTestMain_api.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Mar-2021 16:19:45
 */

/* Include Files */
#include "_coder_createMapCgenTestMain_api.h"
#include "_coder_createMapCgenTestMain_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131610U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "createMapCgenTestMain",                              /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static const mxArray *emlrt_marshallOut(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(void)
{
  static const int32_T iv1[2] = {0, 0};
  static const int32_T iv2[2] = {0, 0};
  static const int32_T iv3[2] = {0, 0};
  static const char_T *sv[3] = {"obstacle", "status", "parent"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  y = NULL;
  iv[0] = 3;
  iv[1] = 3;
  emlrtAssign(&y,
              emlrtCreateStructArray(2, &iv[0], 3, (const char_T **)&sv[0]));
  for (i = 0; i < 9; i++) {
    b_y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS,
                                mxREAL);
    emlrtAssign(&b_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"obstacle", b_y, 0);
    c_y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv2[0], mxDOUBLE_CLASS,
                                mxREAL);
    emlrtAssign(&c_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"status", c_y, 1);
    d_y = NULL;
    m = emlrtCreateNumericArray(2, (const void *)&iv3[0], mxDOUBLE_CLASS,
                                mxREAL);
    emlrtAssign(&d_y, m);
    emlrtSetFieldR2017b(y, i, (const char_T *)"parent", d_y, 2);
  }
  return y;
}

/*
 * Arguments    : const mxArray **plhs
 * Return Type  : void
 */
void createMapCgenTestMain_api(const mxArray **plhs)
{
  /* Invoke the target function */
  createMapCgenTestMain();
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void createMapCgenTestMain_atexit(void)
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
  createMapCgenTestMain_xil_terminate();
  createMapCgenTestMain_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void createMapCgenTestMain_initialize(void)
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
void createMapCgenTestMain_terminate(void)
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
 * File trailer for _coder_createMapCgenTestMain_api.c
 *
 * [EOF]
 */
