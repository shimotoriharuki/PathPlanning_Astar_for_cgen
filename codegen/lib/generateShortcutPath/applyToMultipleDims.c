/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: applyToMultipleDims.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 16:12:11
 */

/* Include Files */
#include "applyToMultipleDims.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Function Definitions */
/*
 * Arguments    : const emxArray_boolean_T *x
 * Return Type  : double
 */
double applyToMultipleDims(const emxArray_boolean_T *x)
{
  double bsum;
  double varargout_1;
  int firstBlockLength;
  int hi;
  int ib;
  int k;
  int lastBlockLength;
  int nblocks;
  if (x->size[1] == 0) {
    varargout_1 = 0.0;
  } else {
    if (x->size[1] <= 1024) {
      firstBlockLength = x->size[1];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = x->size[1] / 1024;
      lastBlockLength = x->size[1] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    varargout_1 = x->data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      varargout_1 += (double)x->data[k - 1];
    }
    for (ib = 2; ib <= nblocks; ib++) {
      firstBlockLength = (ib - 1) << 10;
      bsum = x->data[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        bsum += (double)x->data[(firstBlockLength + k) - 1];
      }
      varargout_1 += bsum;
    }
  }
  return varargout_1;
}

/*
 * File trailer for applyToMultipleDims.c
 *
 * [EOF]
 */
