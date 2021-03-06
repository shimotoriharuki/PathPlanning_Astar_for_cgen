/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: generateShortcutPath_rtwutil.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 16:12:11
 */

/* Include Files */
#include "generateShortcutPath_rtwutil.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Function Definitions */
/*
 * Arguments    : const int b
 *                const char *c
 *                const char *aFcnName
 *                int aLineNum
 * Return Type  : void
 */
void b_rtErrorWithMessageID(const int b, const char *c, const char *aFcnName,
                            int aLineNum)
{
  fprintf(stderr,
          "Domain error. To compute complex results from real x, use "
          "\'%.*s(complex(x))\'.",
          b, c);
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

/*
 * Arguments    : int aIndexValue
 *                int aLoBound
 *                int aHiBound
 *                const rtBoundsCheckInfo *aInfo
 * Return Type  : void
 */
void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                          const rtBoundsCheckInfo *aInfo)
{
  if (aLoBound == 0) {
    aIndexValue++;
    aLoBound = 1;
    aHiBound++;
  }
  if (rtIsNullOrEmptyString(aInfo->aName)) {
    fprintf(stderr,
            "Index exceeds array dimensions.  Index value %d exceeds valid "
            "range [%d-%d].",
            aIndexValue, aLoBound, aHiBound);
    fprintf(stderr, "\n");
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
    fflush(stderr);
    abort();
  } else {
    fprintf(stderr,
            "Index exceeds array dimensions. Index value %d exceeds valid "
            "range [%d-%d] for array \'%s\'.",
            aIndexValue, aLoBound, aHiBound, aInfo->aName);
    fprintf(stderr, "\n");
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
    fflush(stderr);
    abort();
  }
}

/*
 * Arguments    : const char *aFcnName
 *                int aLineNum
 * Return Type  : void
 */
void rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr,
          "Dimensions of arrays being concatenated are not consistent.");
  fprintf(stderr, "\n");
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNum);
  fprintf(stderr, "\n");
  fflush(stderr);
  abort();
}

/*
 * Arguments    : const double aInteger
 *                const rtDoubleCheckInfo *aInfo
 * Return Type  : void
 */
void rtIntegerError(const double aInteger, const rtDoubleCheckInfo *aInfo)
{
  fprintf(stderr,
          "Expected a value representable in the C type \'int\'.  Found %g "
          "instead.",
          aInteger);
  fprintf(stderr, "\n");
  rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  fflush(stderr);
  abort();
}

/*
 * Arguments    : const char *aString
 * Return Type  : bool
 */
bool rtIsNullOrEmptyString(const char *aString)
{
  return (aString == NULL) || (*aString == '\x00');
}

/*
 * Arguments    : const char *aFcnName
 *                int aLineNo
 * Return Type  : void
 */
void rtReportErrorLocation(const char *aFcnName, int aLineNo)
{
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNo);
  fprintf(stderr, "\n");
}

/*
 * Arguments    : double u
 * Return Type  : double
 */
double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

/*
 * File trailer for generateShortcutPath_rtwutil.c
 *
 * [EOF]
 */
