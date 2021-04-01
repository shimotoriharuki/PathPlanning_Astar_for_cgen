/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: checkNonEmptyMemberValueList.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 01-Apr-2021 15:30:00
 */

/* Include Files */
#include "checkNonEmptyMemberValueList.h"
#include "generateShortcutPath_internal_types.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"
#include <stdio.h>

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Function Declarations */
static void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
/*
 * Arguments    : const char *aFcnName
 *                int aLineNum
 * Return Type  : void
 */
static void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Insufficient number of outputs from right hand side of "
                  "equal sign to satisfy assignment.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

/*
 * Arguments    : const struct_T arg_data[]
 *                const int arg_size[2]
 *                double *result_x
 *                double *result_y
 * Return Type  : void
 */
void checkNonEmptyMemberValueList(const struct_T arg_data[],
                                  const int arg_size[2], double *result_x,
                                  double *result_y)
{
  static rtRunTimeErrorInfo e_emlrtRTEI = {
      6,                              /* lineNo */
      23,                             /* colNo */
      "checkNonEmptyMemberValueList", /* fName */
      "C:\\Program "
      "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
      "internal\\checkNonEmptyMemberValueList.m" /* pName */
  };
  if (arg_size[1] == 0) {
    g_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
  }
  *result_x = arg_data[0].x;
  *result_y = arg_data[0].y;
}

/*
 * File trailer for checkNonEmptyMemberValueList.c
 *
 * [EOF]
 */
