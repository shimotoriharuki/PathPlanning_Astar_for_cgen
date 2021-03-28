#include "computeAstar_emxAPI.h"
#include "computeAstar_emxutil.h"
#include "computeAstar_types.h"
#include <stdlib.h>

// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2021 Haruki Shimotor. All right reserved.
*/
emxArray_struct0_T *emxCreateND_struct0_T(int numDimensions, const int *size)
{
  emxArray_struct0_T *emx;
  int i;
  int numEl;
  emxInit_struct0_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = (struct0_T *)calloc((unsigned int)numEl, sizeof(struct0_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_struct0_T *emxCreateWrapperND_struct0_T(struct0_T *data,
                                                 int numDimensions,
                                                 const int *size)
{
  emxArray_struct0_T *emx;
  int i;
  int numEl;
  emxInit_struct0_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_struct0_T *emxCreateWrapper_struct0_T(struct0_T *data, int rows,
                                               int cols)
{
  emxArray_struct0_T *emx;
  emxInit_struct0_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_struct0_T *emxCreate_struct0_T(int rows, int cols)
{
  emxArray_struct0_T *emx;
  int numEl;
  emxInit_struct0_T(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (struct0_T *)calloc((unsigned int)numEl, sizeof(struct0_T));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

void emxDestroyArray_struct0_T(emxArray_struct0_T *emxArray)
{
  emxFree_struct0_T(&emxArray);
}

void emxInitArray_struct0_T(emxArray_struct0_T **pEmxArray, int numDimensions)
{
  emxInit_struct0_T(pEmxArray, numDimensions);
}
