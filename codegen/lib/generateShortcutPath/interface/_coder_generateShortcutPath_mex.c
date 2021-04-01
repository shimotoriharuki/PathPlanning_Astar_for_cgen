/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_generateShortcutPath_mex.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 01-Apr-2021 15:30:00
 */

/* Include Files */
#include "_coder_generateShortcutPath_mex.h"
#include "_coder_generateShortcutPath_api.h"

/* Function Definitions */
/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[1]
 * Return Type  : void
 */
void generateShortcutPath_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                      int32_T nrhs, const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        20, "generateShortcutPath");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "generateShortcutPath");
  }
  /* Call the function. */
  generateShortcutPath_api(prhs[0], &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&generateShortcutPath_atexit);
  /* Module initialization. */
  generateShortcutPath_initialize();
  /* Dispatch the entry-point. */
  generateShortcutPath_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  generateShortcutPath_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_generateShortcutPath_mex.c
 *
 * [EOF]
 */
