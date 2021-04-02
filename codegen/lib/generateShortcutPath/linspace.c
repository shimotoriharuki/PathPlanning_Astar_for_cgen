/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: linspace.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 15:28:24
 */

/* Include Files */
#include "linspace.h"
#include "generateShortcutPath_emxutil.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Function Definitions */
/*
 * Arguments    : double d1
 *                double d2
 *                double n
 *                emxArray_real_T *y
 * Return Type  : void
 */
void linspace(double d1, double d2, double n, emxArray_real_T *y)
{
  double delta1;
  int i;
  int k;
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)n;
  emxEnsureCapacity_real_T(y, i);
  if ((int)n >= 1) {
    y->data[(int)n - 1] = d2;
    if (y->size[1] >= 2) {
      y->data[0] = d1;
      if (y->size[1] >= 3) {
        delta1 = (d2 - d1) / ((double)y->size[1] - 1.0);
        i = y->size[1];
        for (k = 0; k <= i - 3; k++) {
          y->data[k + 1] = d1 + ((double)k + 1.0) * delta1;
        }
      }
    }
  }
}

/*
 * File trailer for linspace.c
 *
 * [EOF]
 */
