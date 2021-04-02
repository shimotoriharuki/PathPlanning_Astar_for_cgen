/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 16:12:11
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "generateShortcutPath.h"
#include "generateShortcutPath_emxAPI.h"
#include "generateShortcutPath_terminate.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"
#include <stdio.h>

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Function Declarations */
static emxArray_real_T *argInit_2xUnbounded_real_T(void);

static double argInit_real_T(void);

static void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void main_generateShortcutPath(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_2xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result->data[idx0 + 2 * idx1] = argInit_real_T();
    }
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : const char *aFcnName
 *                int aLineNum
 * Return Type  : void
 */
static void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  fprintf(stderr, "Example main does not support command line arguments.");
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
static void main_generateShortcutPath(void)
{
  static double shortcut_course[19998];
  emxArray_real_T *src_course;
  /* Initialize function 'generateShortcutPath' input arguments. */
  /* Initialize function input argument 'src_course'. */
  src_course = argInit_2xUnbounded_real_T();
  /* Call the entry-point 'generateShortcutPath'. */
  generateShortcutPath(src_course, argInit_real_T(), shortcut_course);
  emxDestroyArray_real_T(src_course);
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  static rtRunTimeErrorInfo h_emlrtRTEI = {
      1,                      /* lineNo */
      28,                     /* colNo */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m" /* pName */
  };
  (void)argv;
  if (argc > 1) {
    i_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_generateShortcutPath();
  /* Terminate the application.
You do not need to do this more than one time. */
  generateShortcutPath_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
