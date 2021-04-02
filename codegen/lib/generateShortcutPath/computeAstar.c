/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: computeAstar.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 16:12:11
 */

/* Include Files */
#include "computeAstar.h"
#include "flip.h"
#include "generateShortcutPath_data.h"
#include "generateShortcutPath_emxutil.h"
#include "generateShortcutPath_internal_types.h"
#include "generateShortcutPath_rtwutil.h"
#include "generateShortcutPath_types.h"
#include "openAroundNodeDP.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Function Declarations */
static void h_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

/* Function Definitions */
/*
 * Arguments    : const char *aFcnName
 *                int aLineNum
 * Return Type  : void
 */
static void h_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
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
 * % -----------A star開始------------ %
 *
 * Arguments    : emxArray_struct_T *map
 *                const double start[2]
 *                const double goal[2]
 *                double size_x
 *                double size_y
 *                emxArray_real_T *shortcut_course
 * Return Type  : void
 */
void computeAstar(emxArray_struct_T *map, const double start[2],
                  const double goal[2], double size_x, double size_y,
                  emxArray_real_T *shortcut_course)
{
  static rtBoundsCheckInfo b_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      34,             /* lineNo */
      19,             /* colNo */
      "map",          /* aName */
      "computeAstar", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\computeAstar.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo c_emlrtBCI = {
      1,              /* iFirst */
      9999,           /* iLast */
      38,             /* lineNo */
      9,              /* colNo */
      "store_x",      /* aName */
      "computeAstar", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\computeAstar.m", /* pName */
      3                                                     /* checkKind */
  };
  static rtBoundsCheckInfo emlrtBCI = {
      1,              /* iFirst */
      9999,           /* iLast */
      43,             /* lineNo */
      41,             /* colNo */
      "store_x",      /* aName */
      "computeAstar", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\computeAstar.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtDoubleCheckInfo emlrtDCI = {
      34,             /* lineNo */
      19,             /* colNo */
      "computeAstar", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\computeAstar.m", /* pName */
      1                                                     /* checkKind */
  };
  static rtRunTimeErrorInfo h_emlrtRTEI = {
      6,                              /* lineNo */
      23,                             /* colNo */
      "checkNonEmptyMemberValueList", /* fName */
      "C:\\Program "
      "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
      "internal\\checkNonEmptyMemberValueList.m" /* pName */
  };
  emxArray_real_T *r;
  emxArray_real_T *varargin_1;
  emxArray_real_T *varargin_2;
  struct_T arg_data[999];
  struct_T b_arg_data[999];
  struct_T open_list[999];
  double x;
  double y;
  int cnt;
  int ex;
  int i;
  int idx;
  int loop_ub;
  unsigned short store_x[9999];
  unsigned short store_y[9999];
  short ii_data[999];
  unsigned short scores[999];
  unsigned short temp_xy_idx_1;
  bool exitg1;
  x = start[0];
  y = start[1];
  for (i = 0; i < 999; i++) {
    open_list[i].x = -1.0;
    open_list[i].y = -1.0;
    open_list[i].score = 9999U;
    open_list[i].g_cost = 9999U;
    open_list[i].h_cost = 9999U;
  }
  openAroundNodeDP(map, open_list, start[0], start[1], size_x, size_y, goal);
  /*  スタートノードの周りをオープン */
  while ((x != goal[0]) || (y != goal[1])) {
    for (idx = 0; idx < 999; idx++) {
      scores[idx] = open_list[idx].score;
    }
    ex = scores[0];
    for (idx = 0; idx < 998; idx++) {
      i = scores[idx + 1];
      if (ex > i) {
        ex = i;
      }
    }
    idx = 0;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 999)) {
      if (scores[loop_ub] == ex) {
        idx++;
        ii_data[idx - 1] = (short)(loop_ub + 1);
        if (idx >= 999) {
          exitg1 = true;
        } else {
          loop_ub++;
        }
      } else {
        loop_ub++;
      }
    }
    if (1 > idx) {
      idx = 0;
    }
    /*  最小スコアのインデックスを取得 */
    for (i = 0; i < idx; i++) {
      arg_data[i] = open_list[ii_data[i] - 1];
    }
    if (idx == 0) {
      h_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
    }
    for (i = 0; i < idx; i++) {
      b_arg_data[i] = open_list[ii_data[i] - 1];
    }
    x = arg_data[0].x;
    y = b_arg_data[0].y;
    /*  スコアが最も小さいノードのx, yを得る */
    openAroundNodeDP(map, open_list, arg_data[0].x, b_arg_data[0].y, size_x,
                     size_y, goal);
  }
  /*  % -----------最短経路の座標を取得------------ % */
  memset(&store_x[0], 0, 9999U * sizeof(unsigned short));
  memset(&store_y[0], 0, 9999U * sizeof(unsigned short));
  cnt = 0;
  while ((x != start[0]) || (y != start[1])) {
    i = (int)floor(y);
    if (y != i) {
      rtIntegerError(y, &emlrtDCI);
    }
    idx = (int)y;
    if ((y < 1.0) || (idx > map->size[0])) {
      rtDynamicBoundsError((int)y, 1, map->size[0], &b_emlrtBCI);
    }
    loop_ub = (int)floor(x);
    if (x != loop_ub) {
      rtIntegerError(x, &emlrtDCI);
    }
    ex = (int)x;
    if ((x < 1.0) || (ex > map->size[1])) {
      rtDynamicBoundsError((int)x, 1, map->size[1], &b_emlrtBCI);
    }
    if (idx != i) {
      rtIntegerError(y, &emlrtDCI);
    }
    if ((y < 1.0) || (idx > map->size[0])) {
      rtDynamicBoundsError((int)y, 1, map->size[0], &b_emlrtBCI);
    }
    if (ex != loop_ub) {
      rtIntegerError(x, &emlrtDCI);
    }
    if ((x < 1.0) || (ex > map->size[1])) {
      rtDynamicBoundsError((int)x, 1, map->size[1], &b_emlrtBCI);
    }
    temp_xy_idx_1 = map->data[(idx + map->size[0] * (ex - 1)) - 1].parent[1];
    x = map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].parent[0];
    y = temp_xy_idx_1;
    if ((cnt + 1 < 1) || (cnt + 1 > 9999)) {
      rtDynamicBoundsError(cnt + 1, 1, 9999, &c_emlrtBCI);
    }
    store_x[cnt] = map->data[(idx + map->size[0] * (ex - 1)) - 1].parent[0];
    store_y[cnt] = temp_xy_idx_1;
    cnt++;
  }
  if (1 > cnt) {
    cnt = 0;
    loop_ub = 0;
  } else {
    if (cnt > 9999) {
      rtDynamicBoundsError(cnt, 1, 9999, &emlrtBCI);
    }
    loop_ub = cnt;
  }
  emxInit_real_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = cnt;
  emxEnsureCapacity_real_T(r, i);
  for (i = 0; i < cnt; i++) {
    r->data[i] = store_x[i];
  }
  emxInit_real_T(&varargin_1, 2);
  flip(r);
  i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = r->size[1];
  emxEnsureCapacity_real_T(varargin_1, i);
  idx = r->size[1];
  for (i = 0; i < idx; i++) {
    varargin_1->data[i] = r->data[i];
  }
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = loop_ub;
  emxEnsureCapacity_real_T(r, i);
  for (i = 0; i < loop_ub; i++) {
    r->data[i] = store_y[i];
  }
  emxInit_real_T(&varargin_2, 2);
  flip(r);
  i = varargin_2->size[0] * varargin_2->size[1];
  varargin_2->size[0] = 1;
  varargin_2->size[1] = r->size[1];
  emxEnsureCapacity_real_T(varargin_2, i);
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    varargin_2->data[i] = r->data[i];
  }
  emxFree_real_T(&r);
  if (varargin_2->size[1] != varargin_1->size[1]) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  i = shortcut_course->size[0] * shortcut_course->size[1];
  shortcut_course->size[0] = 2;
  shortcut_course->size[1] = varargin_1->size[1];
  emxEnsureCapacity_real_T(shortcut_course, i);
  loop_ub = varargin_1->size[1];
  for (i = 0; i < loop_ub; i++) {
    shortcut_course->data[2 * i] = varargin_1->data[i];
  }
  emxFree_real_T(&varargin_1);
  loop_ub = varargin_2->size[1];
  for (i = 0; i < loop_ub; i++) {
    shortcut_course->data[2 * i + 1] = varargin_2->data[i];
  }
  emxFree_real_T(&varargin_2);
  /*  順序が逆なのでflipでもとに戻す */
}

/*
 * File trailer for computeAstar.c
 *
 * [EOF]
 */
