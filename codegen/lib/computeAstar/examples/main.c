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

#include "main.h"
#include "computeAstar.h"
#include "computeAstar_emxAPI.h"
#include "computeAstar_terminate.h"
#include "computeAstar_types.h"

// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2021 Haruki Shimotor. All right reserved.
*/
static void argInit_1x2_uint16_T(unsigned short result[2]);

static void argInit_2x1_real_T(double result[2]);

static double argInit_real_T(void);

static struct0_T argInit_struct0_T(void);

static unsigned short argInit_uint16_T(void);

static emxArray_struct0_T *c_argInit_UnboundedxUnbounded_s(void);

static void main_computeAstar(void);

static void argInit_1x2_uint16_T(unsigned short result[2])
{
  int idx1;

  for (idx1 = 0; idx1 < 2; idx1++) {

    result[idx1] = argInit_uint16_T();
  }
}

static void argInit_2x1_real_T(double result[2])
{
  int idx0;

  for (idx0 = 0; idx0 < 2; idx0++) {

    result[idx0] = argInit_real_T();
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

static struct0_T argInit_struct0_T(void)
{
  struct0_T result;
  unsigned short result_tmp;

  result_tmp = argInit_uint16_T();
  result.status = result_tmp;
  result.g_cost = result_tmp;
  result.h_cost = result_tmp;
  result.score = result_tmp;
  result.obstacle = result_tmp;
  argInit_1x2_uint16_T(result.parent);
  return result;
}

static unsigned short argInit_uint16_T(void)
{
  return 0U;
}

static emxArray_struct0_T *c_argInit_UnboundedxUnbounded_s(void)
{
  emxArray_struct0_T *result;
  int idx0;
  int idx1;

  result = emxCreate_struct0_T(2, 2);

  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {

      result->data[idx0 + result->size[0] * idx1] = argInit_struct0_T();
    }
  }
  return result;
}

static void main_computeAstar(void)
{
  static double shortcut_course[19998];
  emxArray_struct0_T *map;
  double start_tmp[2];
  double size_x_tmp;

  map = c_argInit_UnboundedxUnbounded_s();

  argInit_2x1_real_T(start_tmp);

  size_x_tmp = argInit_real_T();

  computeAstar(map, start_tmp, start_tmp, size_x_tmp, size_x_tmp,
               shortcut_course);
  emxDestroyArray_struct0_T(map);
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  main_computeAstar();

  computeAstar_terminate();
  return 0;
}
