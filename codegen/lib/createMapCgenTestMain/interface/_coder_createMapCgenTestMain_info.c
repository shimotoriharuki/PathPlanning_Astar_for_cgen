/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_createMapCgenTestMain_info.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 29-Mar-2021 16:19:45
 */

/* Include Files */
#include "_coder_createMapCgenTestMain_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[4] = {
      "789c6360f4f465646060e06380800e3608cd0bc4b9402c001567624005e8f28c58e85c24"
      "f5ac0c2c707dc8eafaa174727e5e496a4509849397989b0ad799929f"
      "9b9997985712525990ca50945a9c9f53969a029649cbcc490dc9cc4d0d46e6f88178b96e"
      "4852700e480ac476ce484dce0e2ecd6528ca2846b8300799030f8f1d",
      "48fe6540f22f0b91e11184233c04d0e4a35d639dad62428b538b8a634af352528b627c1d"
      "437c1c9d145c8a32cb526302124b32027212f3f232f3d2e31d8b4b12"
      "8be2d3f28be29dd353f362928b52134b527d130b40bc90d4e212dfc4cc3cbd5c547f5450"
      "e80f4102fe80c963388601d51d0964ba031de072070cc0ecdb40a67d",
      "307ffb11b00f264fcdf803c51da1f0e227d2fdb8f2232f0307432b50305be53a5809bdec"
      "db7321cc8a9ef6c1c040d94769be13c3619f009a7c56ae85678969a2"
      "b151716aae6bb8416158916f999733c21d0138dc81e464bcee6040e223bb83d6e6030007"
      "2a8a3d",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1696U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[6] = {
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  const char_T *propFieldName[5] = {"Version", "ResolvedFunctions",
                                    "EntryPoints", "CoverageInfo",
                                    "IsPolymorphic"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 0);
  emlrtSetField(xEntryPoints, 0, (const char_T *)"Name",
                emlrtMxCreateString((const char_T *)"createMapCgenTestMain"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfInputs",
                emlrtMxCreateDoubleScalar(0.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, (const char_T *)"FullPath",
      emlrtMxCreateString((
          const char_T
              *)"C:\\Users\\under\\MATLAB "
                "Drive\\PathPlanning_Astar_for_Cgen\\createMapCgenTestMain.m"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"TimeStamp",
                emlrtMxCreateDoubleScalar(738244.67993055552));
  xResult =
      emlrtCreateStructMatrix(1, 1, 5, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, (const char_T *)"Version",
                emlrtMxCreateString((const char_T *)"9.10.0.1602886 (R2021a)"));
  emlrtSetField(xResult, 0, (const char_T *)"ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, (const char_T *)"EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_createMapCgenTestMain_info.c
 *
 * [EOF]
 */
