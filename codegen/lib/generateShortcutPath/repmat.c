/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 15:28:24
 */

/* Include Files */
#include "repmat.h"
#include "generateShortcutPath_emxutil.h"
#include "generateShortcutPath_rtwutil.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Variable Definitions */
static rtRunTimeErrorInfo f_emlrtRTEI = {
    58,                   /* lineNo */
    23,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" /* pName */
};

static rtRunTimeErrorInfo g_emlrtRTEI = {
    64,                   /* lineNo */
    15,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" /* pName */
};

/* Function Declarations */
static void f_rtErrorWithMessageID(const int b, const int c,
                                   const char *aFcnName, int aLineNum);

static void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtNonNegativeError(const double aPositive,
                               const rtDoubleCheckInfo *aInfo);

/* Function Definitions */
/*
 * Arguments    : const int b
 *                const int c
 *                const char *aFcnName
 *                int aLineNum
 * Return Type  : void
 */
static void f_rtErrorWithMessageID(const int b, const int c,
                                   const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Size argument must be an integer in the range: %d to %d.", b,
          c);
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

/*
 * Arguments    : const char *aFcnName
 *                int aLineNum
 * Return Type  : void
 */
static void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Maximum variable size allowed by the program is exceeded.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

/*
 * Arguments    : const double aPositive
 *                const rtDoubleCheckInfo *aInfo
 * Return Type  : void
 */
static void rtNonNegativeError(const double aPositive,
                               const rtDoubleCheckInfo *aInfo)
{
  fprintf(stderr,
          "Value %g is not greater than or equal to zero.\nExiting to prevent "
          "memory corruption.",
          aPositive);
  fprintf(stderr, "\n");
  rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  fflush(stderr);
  abort();
}

/*
 * Arguments    : const double a[2]
 *                double varargin_2
 *                emxArray_real_T *b
 * Return Type  : void
 */
void b_repmat(const double a[2], double varargin_2, emxArray_real_T *b)
{
  double b_varargin_2;
  int ibtile;
  int jtilecol;
  int ntilecols;
  if ((varargin_2 != floor(varargin_2)) || rtIsInf(varargin_2) ||
      (varargin_2 < -2.147483648E+9) || (varargin_2 > 2.147483647E+9)) {
    f_rtErrorWithMessageID(MIN_int32_T, MAX_int32_T, f_emlrtRTEI.fName,
                           f_emlrtRTEI.lineNo);
  }
  if (varargin_2 <= 0.0) {
    b_varargin_2 = 0.0;
  } else {
    b_varargin_2 = varargin_2;
  }
  if (!(b_varargin_2 <= 2.147483647E+9)) {
    g_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
  }
  ntilecols = b->size[0] * b->size[1];
  b->size[0] = 2;
  b->size[1] = (short)(int)varargin_2;
  emxEnsureCapacity_real_T(b, ntilecols);
  ntilecols = (int)varargin_2;
  for (jtilecol = 0; jtilecol < ntilecols; jtilecol++) {
    ibtile = jtilecol << 1;
    b->data[ibtile] = a[0];
    b->data[ibtile + 1] = a[1];
  }
}

/*
 * Arguments    : double varargin_1
 *                double varargin_2
 *                emxArray_struct_T *b
 * Return Type  : void
 */
void repmat(double varargin_1, double varargin_2, emxArray_struct_T *b)
{
  static const b_struct_T r = {
      1U,      /* obstacle */
      0U,      /* status */
      0U,      /* g_cost */
      0U,      /* h_cost */
      0U,      /* score */
      {0U, 0U} /* parent */
  };
  static rtDoubleCheckInfo emlrtDCI = {
      31,       /* lineNo */
      14,       /* colNo */
      "repmat", /* fName */
      "C:\\Program "
      "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m", /* pName
                                                                            */
      4 /* checkKind */
  };
  double b_varargin_1;
  int i;
  int loop_ub;
  bool b_b;
  if ((varargin_1 != floor(varargin_1)) || rtIsInf(varargin_1) ||
      (varargin_1 < -2.147483648E+9) || (varargin_1 > 2.147483647E+9)) {
    f_rtErrorWithMessageID(MIN_int32_T, MAX_int32_T, f_emlrtRTEI.fName,
                           f_emlrtRTEI.lineNo);
  } else {
    b_b = true;
  }
  if ((varargin_2 != floor(varargin_2)) || rtIsInf(varargin_2) ||
      (varargin_2 < -2.147483648E+9) || (varargin_2 > 2.147483647E+9)) {
    b_b = false;
  }
  if (!b_b) {
    f_rtErrorWithMessageID(MIN_int32_T, MAX_int32_T, f_emlrtRTEI.fName,
                           f_emlrtRTEI.lineNo);
  }
  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }
  if (varargin_2 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 *= varargin_2;
  }
  if (!(b_varargin_1 <= 2.147483647E+9)) {
    g_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
  }
  if (!(varargin_1 >= 0.0)) {
    rtNonNegativeError(varargin_1, &emlrtDCI);
  }
  if (!(varargin_2 >= 0.0)) {
    rtNonNegativeError(varargin_2, &emlrtDCI);
  }
  i = b->size[0] * b->size[1];
  b->size[0] = (int)varargin_1;
  b->size[1] = (int)varargin_2;
  emxEnsureCapacity_struct_T(b, i);
  loop_ub = (int)varargin_1 * (int)varargin_2;
  for (i = 0; i < loop_ub; i++) {
    b->data[i] = r;
  }
}

/*
 * File trailer for repmat.c
 *
 * [EOF]
 */
