/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: flip.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 01-Apr-2021 15:30:00
 */

/* Include Files */
#include "flip.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *x
 * Return Type  : void
 */
void flip(emxArray_real_T *x)
{
  double tmp;
  int i;
  int k;
  int n;
  int nd2;
  if ((x->size[1] != 0) && (x->size[1] > 1)) {
    n = x->size[1] - 1;
    nd2 = x->size[1] >> 1;
    for (k = 0; k < nd2; k++) {
      tmp = x->data[k];
      i = n - k;
      x->data[k] = x->data[i];
      x->data[i] = tmp;
    }
  }
}

/*
 * File trailer for flip.c
 *
 * [EOF]
 */
