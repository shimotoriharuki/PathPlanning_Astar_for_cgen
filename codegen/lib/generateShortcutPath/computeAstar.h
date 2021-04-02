/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeAstar.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 15:28:24
 */

#ifndef COMPUTEASTAR_H
#define COMPUTEASTAR_H

/* Include Files */
#include "generateShortcutPath_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void computeAstar(emxArray_struct_T *map, const double start[2],
                  const double goal[2], double size_x, double size_y,
                  emxArray_real_T *shortcut_course);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for computeAstar.h
 *
 * [EOF]
 */
