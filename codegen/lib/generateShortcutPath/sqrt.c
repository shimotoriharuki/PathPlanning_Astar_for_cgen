/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sqrt.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 01-Apr-2021 15:30:00
 */

/* Include Files */
#include "sqrt.h"
#include "eml_int_forloop_overflow_check.h"
#include "generateShortcutPath_data.h"
#include "generateShortcutPath_rtwutil.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"
#include <math.h>

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
void b_sqrt(emxArray_real_T *x)
{
  int k;
  int nx;
  bool p;
  p = false;
  nx = x->size[1];
  for (k = 0; k < nx; k++) {
    if (p || (x->data[k] < 0.0)) {
      p = true;
    }
  }
  if (p) {
    i_rtErrorWithMessageID(4, "sqrt", d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  }
  nx = x->size[1];
  if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nx; k++) {
    x->data[k] = sqrt(x->data[k]);
  }
}

/*
 * File trailer for sqrt.c
 *
 * [EOF]
 */
