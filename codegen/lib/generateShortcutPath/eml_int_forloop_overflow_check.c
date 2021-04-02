/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_int_forloop_overflow_check.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 15:28:24
 */

/* Include Files */
#include "eml_int_forloop_overflow_check.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"
#include <stdio.h>

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Function Declarations */
static void d_rtErrorWithMessageID(const int b, const char *c,
                                   const char *aFcnName, int aLineNum);

/* Function Definitions */
/*
 * Arguments    : const int b
 *                const char *c
 *                const char *aFcnName
 *                int aLineNum
 * Return Type  : void
 */
static void d_rtErrorWithMessageID(const int b, const char *c,
                                   const char *aFcnName, int aLineNum)
{
  fprintf(stderr,
          "The loop variable of class %.*s might overflow on the last "
          "iteration of the for loop. This could lead to an infinite loop.",
          b, c);
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void check_forloop_overflow_error(void)
{
  static rtRunTimeErrorInfo h_emlrtRTEI = {
      88,                             /* lineNo */
      9,                              /* colNo */
      "check_forloop_overflow_error", /* fName */
      "C:\\Program "
      "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
      "overflow_check.m" /* pName */
  };
  d_rtErrorWithMessageID(5, "int32", h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
}

/*
 * File trailer for eml_int_forloop_overflow_check.c
 *
 * [EOF]
 */
