/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: openAroundNodeDP.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 01-Apr-2021 15:30:00
 */

#ifndef OPENAROUNDNODEDP_H
#define OPENAROUNDNODEDP_H

/* Include Files */
#include "generateShortcutPath_internal_types.h"
#include "generateShortcutPath_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void openAroundNodeDP(emxArray_struct_T *map, struct_T open_list[999],
                      double ref_x, double ref_y, double size_x, double size_y,
                      const double goal[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for openAroundNodeDP.h
 *
 * [EOF]
 */
