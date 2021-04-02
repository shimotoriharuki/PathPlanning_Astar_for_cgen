/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: generateShortcutPath_rtwutil.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 15:28:24
 */

#ifndef GENERATESHORTCUTPATH_RTWUTIL_H
#define GENERATESHORTCUTPATH_RTWUTIL_H

/* Include Files */
#include "generateShortcutPath_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                                 const rtBoundsCheckInfo *aInfo);

extern void rtErrorWithMessageID(const int b, const char *c,
                                 const char *aFcnName, int aLineNum);

extern void rtIntegerError(const double aInteger,
                           const rtDoubleCheckInfo *aInfo);

extern bool rtIsNullOrEmptyString(const char *aString);

extern void rtReportErrorLocation(const char *aFcnName, int aLineNo);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for generateShortcutPath_rtwutil.h
 *
 * [EOF]
 */
