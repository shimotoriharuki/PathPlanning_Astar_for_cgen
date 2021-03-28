/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: createMapCgenTest.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 26-Mar-2021 19:12:49
 */

/* Include Files */
#include "createMapCgenTest.h"
#include "createMapCgenTest_types.h"

/* Function Definitions */
/*
 * Arguments    : struct0_T ret[9]
 * Return Type  : void
 */
void createMapCgenTest(struct0_T ret[9])
{
  struct0_T s;
  int i;
  s.obstacle = 0U;
  s.status = 0U;
  s.parent[0] = 0U;
  s.parent[1] = 0U;
  for (i = 0; i < 9; i++) {
    ret[i] = s;
  }
}

/*
 * File trailer for createMapCgenTest.c
 *
 * [EOF]
 */
