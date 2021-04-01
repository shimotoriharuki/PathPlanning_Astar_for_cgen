/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: find.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 01-Apr-2021 14:26:53
 */

/* Include Files */
#include "find.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const bool x[9999]
 *                int i_data[]
 *                int i_size[2]
 * Return Type  : void
 */
void b_eml_find(const bool x[9999], int i_data[], int i_size[2])
{
  int idx;
  int ii;
  bool exitg1;
  idx = 0;
  i_size[0] = 1;
  i_size[1] = 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 9999)) {
    if (x[ii]) {
      idx = 1;
      i_data[0] = ii + 1;
      exitg1 = true;
    } else {
      ii++;
    }
  }
  if (idx == 0) {
    i_size[0] = 1;
    i_size[1] = 0;
  }
}

/*
 * Arguments    : const bool x[999]
 *                int i_data[]
 *                int i_size[2]
 * Return Type  : void
 */
void eml_find(const bool x[999], int i_data[], int i_size[2])
{
  int idx;
  int ii;
  bool exitg1;
  idx = 0;
  i_size[0] = 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 999)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 999) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (1 > idx) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

/*
 * File trailer for find.c
 *
 * [EOF]
 */
