#include "_coder_computeAstar_mex.h"
#include "_coder_computeAstar_api.h"

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&computeAstar_atexit);

  computeAstar_initialize();

  unsafe_computeAstar_mexFunction(nlhs, plhs, nrhs, prhs);

  computeAstar_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

void unsafe_computeAstar_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                     int32_T nrhs, const mxArray *prhs[5])
{
  emlrtStack st = {NULL, NULL, NULL};
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;

  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        12, "computeAstar");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "computeAstar");
  }

  computeAstar_api(prhs, &outputs);

  emlrtReturnArrays(1, &plhs[0], &outputs);
}
