/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: power.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 15:28:24
 */

/* Include Files */
#include "power.h"
#include "eml_int_forloop_overflow_check.h"
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
 * Arguments    : const emxArray_real_T *a
 *                emxArray_real_T *y
 * Return Type  : void
 */
void power(const emxArray_real_T *a, emxArray_real_T *y)
{
  double d;
  int k;
  int nx;
  nx = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = a->size[1];
  emxEnsureCapacity_real_T(y, nx);
  nx = a->size[1];
  if ((1 <= a->size[1]) && (a->size[1] > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nx; k++) {
    d = a->data[k];
    y->data[k] = d * d;
  }
}

/*
 * File trailer for power.c
 *
 * [EOF]
 */
