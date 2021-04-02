/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: minOrMax.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 15:28:24
 */

/* Include Files */
#include "minOrMax.h"
#include "eml_int_forloop_overflow_check.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <stdio.h>

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Variable Definitions */
static rtRunTimeErrorInfo c_emlrtRTEI = {
    124,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

/* Function Declarations */
static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
/*
 * Arguments    : const char *aFcnName
 *                int aLineNum
 * Return Type  : void
 */
static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "If the working dimension of MAX or MIN is variable in "
                  "length, it must not have zero length at runtime.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double maximum(const emxArray_real_T *x)
{
  double d;
  double ex;
  int a;
  int idx;
  int k;
  int last;
  bool exitg1;
  if (x->size[1] < 1) {
    c_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
  }
  last = x->size[1];
  if (x->size[1] <= 2) {
    if (x->size[1] == 1) {
      ex = x->data[0];
    } else if ((x->data[0] < x->data[1]) ||
               (rtIsNaN(x->data[0]) && (!rtIsNaN(x->data[1])))) {
      ex = x->data[1];
    } else {
      ex = x->data[0];
    }
  } else {
    if (!rtIsNaN(x->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      if (x->size[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x->data[0];
    } else {
      ex = x->data[idx - 1];
      a = idx + 1;
      if ((idx + 1 <= x->size[1]) && (x->size[1] > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (k = a; k <= last; k++) {
        d = x->data[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double minimum(const emxArray_real_T *x)
{
  double d;
  double ex;
  int a;
  int idx;
  int k;
  int last;
  bool exitg1;
  if (x->size[1] < 1) {
    c_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
  }
  last = x->size[1];
  if (x->size[1] <= 2) {
    if (x->size[1] == 1) {
      ex = x->data[0];
    } else if ((x->data[0] > x->data[1]) ||
               (rtIsNaN(x->data[0]) && (!rtIsNaN(x->data[1])))) {
      ex = x->data[1];
    } else {
      ex = x->data[0];
    }
  } else {
    if (!rtIsNaN(x->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      if (x->size[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x->data[0];
    } else {
      ex = x->data[idx - 1];
      a = idx + 1;
      if ((idx + 1 <= x->size[1]) && (x->size[1] > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (k = a; k <= last; k++) {
        d = x->data[k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

/*
 * File trailer for minOrMax.c
 *
 * [EOF]
 */
