#include "_coder_computeAstar_api.h"
#include "_coder_computeAstar_mex.h"

emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,
    false,
    131610U,
    NULL,
    "computeAstar",
    NULL,
    false,
    {2045744189U, 2170104910U, 2743257031U, 4284093946U},
    NULL};

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_struct0_T *y);

static uint16_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               uint16_T y[2]);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *start,
                                   const char_T *identifier))[2];

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *map,
                             const char_T *identifier, emxArray_struct0_T *y);

static const mxArray *emlrt_marshallOut(const real_T u[19998]);

static void emxEnsureCapacity_struct0_T(emxArray_struct0_T *emxArray,
                                        int32_T oldNumel);

static void emxFree_struct0_T(emxArray_struct0_T **pEmxArray);

static void emxInit_struct0_T(const emlrtStack *sp,
                              emxArray_struct0_T **pEmxArray,
                              int32_T numDimensions, boolean_T doPush);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *size_x,
                                 const char_T *identifier);

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static uint16_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               uint16_T ret[2]);

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_struct0_T *y)
{
  static const int32_T dims[2] = {-1, -1};
  static const char_T *fieldNames[6] = {"obstacle", "status", "g_cost",
                                        "h_cost",   "score",  "parent"};
  emlrtMsgIdentifier thisId;
  int32_T sizes[2];
  int32_T i;
  int32_T n;
  const boolean_T bv[2] = {true, true};
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckVsStructR2012b((emlrtCTX)sp, parentId, u, 6,
                           (const char_T **)&fieldNames[0], 2U,
                           (void *)&dims[0], &bv[0], &sizes[0]);
  i = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_struct0_T(y, i);
  n = sizes[0] * sizes[1];
  for (i = 0; i < n; i++) {
    thisId.fIdentifier = "obstacle";
    y->data[i].obstacle = c_emlrt_marshallIn(
        sp,
        emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, i, 0,
                                       (const char_T *)"obstacle")),
        &thisId);
    thisId.fIdentifier = "status";
    y->data[i].status = c_emlrt_marshallIn(
        sp,
        emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, i, 1,
                                       (const char_T *)"status")),
        &thisId);
    thisId.fIdentifier = "g_cost";
    y->data[i].g_cost = c_emlrt_marshallIn(
        sp,
        emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, i, 2,
                                       (const char_T *)"g_cost")),
        &thisId);
    thisId.fIdentifier = "h_cost";
    y->data[i].h_cost = c_emlrt_marshallIn(
        sp,
        emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, i, 3,
                                       (const char_T *)"h_cost")),
        &thisId);
    thisId.fIdentifier = "score";
    y->data[i].score =
        c_emlrt_marshallIn(sp,
                           emlrtAlias(emlrtGetFieldR2017b(
                               (emlrtCTX)sp, u, i, 4, (const char_T *)"score")),
                           &thisId);
    thisId.fIdentifier = "parent";
    d_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b(
                           (emlrtCTX)sp, u, i, 5, (const char_T *)"parent")),
                       &thisId, y->data[i].parent);
  }
  emlrtDestroyArray(&u);
}

static uint16_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId)
{
  uint16_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               uint16_T y[2])
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *start,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(start), &thisId);
  emlrtDestroyArray(&start);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *map,
                             const char_T *identifier, emxArray_struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(map), &thisId, y);
  emlrtDestroyArray(&map);
}

static const mxArray *emlrt_marshallOut(const real_T u[19998])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {2, 9999};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void emxEnsureCapacity_struct0_T(emxArray_struct0_T *emxArray,
                                        int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(struct0_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(struct0_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (struct0_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxFree_struct0_T(emxArray_struct0_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_struct0_T *)NULL) {
    if (((*pEmxArray)->data != (struct0_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_struct0_T *)NULL;
  }
}

static void emxInit_struct0_T(const emlrtStack *sp,
                              emxArray_struct0_T **pEmxArray,
                              int32_T numDimensions, boolean_T doPush)
{
  emxArray_struct0_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_struct0_T *)emlrtMallocMex(sizeof(emxArray_struct0_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_struct0_T, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (struct0_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *size_x,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(size_x), &thisId);
  emlrtDestroyArray(&size_x);
  return y;
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static uint16_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  uint16_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint16",
                          false, 0U, (void *)&dims);
  ret = *(uint16_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, uint16_T ret[2])
{
  static const int32_T dims[2] = {1, 2};
  uint16_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint16",
                          false, 2U, (void *)&dims[0]);
  r = (uint16_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims = 2;
  real_T(*ret)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void computeAstar_api(const mxArray *const prhs[5], const mxArray **plhs)
{
  emlrtStack st = {NULL, NULL, NULL};
  emxArray_struct0_T *map;
  real_T(*shortcut_course)[19998];
  real_T(*goal)[2];
  real_T(*start)[2];
  real_T size_x;
  real_T size_y;
  st.tls = emlrtRootTLSGlobal;
  shortcut_course = (real_T(*)[19998])mxMalloc(sizeof(real_T[19998]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_struct0_T(&st, &map, 2, true);

  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "map", map);
  start = e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "start");
  goal = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "goal");
  size_x = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "size_x");
  size_y = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "size_y");

  computeAstar(map, *start, *goal, size_x, size_y, *shortcut_course);

  *plhs = emlrt_marshallOut(*shortcut_course);
  emxFree_struct0_T(&map);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void computeAstar_atexit(void)
{
  emlrtStack st = {NULL, NULL, NULL};
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  computeAstar_xil_terminate();
  computeAstar_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void computeAstar_initialize(void)
{
  emlrtStack st = {NULL, NULL, NULL};
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void computeAstar_terminate(void)
{
  emlrtStack st = {NULL, NULL, NULL};
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}
