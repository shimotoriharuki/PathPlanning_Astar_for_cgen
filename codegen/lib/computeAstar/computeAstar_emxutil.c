#include "computeAstar_emxutil.h"
#include "computeAstar_types.h"
#include <stdlib.h>

// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2021 Haruki Shimotor. All right reserved.
*/
void emxFree_struct0_T(emxArray_struct0_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_struct0_T *)NULL) {
    if (((*pEmxArray)->data != (struct0_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_struct0_T *)NULL;
  }
}

void emxInit_struct0_T(emxArray_struct0_T **pEmxArray, int numDimensions)
{
  emxArray_struct0_T *emxArray;
  int i;
  *pEmxArray = (emxArray_struct0_T *)malloc(sizeof(emxArray_struct0_T));
  emxArray = *pEmxArray;
  emxArray->data = (struct0_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}
