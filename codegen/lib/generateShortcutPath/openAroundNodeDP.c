/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: openAroundNodeDP.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 01-Apr-2021 15:30:00
 */

/* Include Files */
#include "openAroundNodeDP.h"
#include "generateShortcutPath_data.h"
#include "generateShortcutPath_internal_types.h"
#include "generateShortcutPath_rtwutil.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Function Declarations */
static double rt_roundd_snf(double u);

/* Function Definitions */
/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
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
 * Diagonal prohibition
 *
 * Arguments    : emxArray_struct_T *map
 *                struct_T open_list[999]
 *                double ref_x
 *                double ref_y
 *                double size_x
 *                double size_y
 *                const double goal[2]
 * Return Type  : void
 */
void openAroundNodeDP(emxArray_struct_T *map, struct_T open_list[999],
                      double ref_x, double ref_y, double size_x, double size_y,
                      const double goal[2])
{
  static rtBoundsCheckInfo b_emlrtBCI = {
      -1,                 /* iFirst */
      -1,                 /* iLast */
      23,                 /* lineNo */
      16,                 /* colNo */
      "map",              /* aName */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      0                                                         /* checkKind */
  };
  static rtBoundsCheckInfo c_emlrtBCI = {
      -1,                 /* iFirst */
      -1,                 /* iLast */
      23,                 /* lineNo */
      43,                 /* colNo */
      "map",              /* aName */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      0                                                         /* checkKind */
  };
  static rtBoundsCheckInfo d_emlrtBCI = {
      -1,                 /* iFirst */
      -1,                 /* iLast */
      24,                 /* lineNo */
      17,                 /* colNo */
      "map",              /* aName */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      0                                                         /* checkKind */
  };
  static rtBoundsCheckInfo e_emlrtBCI = {
      -1,                 /* iFirst */
      -1,                 /* iLast */
      26,                 /* lineNo */
      48,                 /* colNo */
      "map",              /* aName */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      0                                                         /* checkKind */
  };
  static rtBoundsCheckInfo emlrtBCI = {
      -1,          /* iFirst */
      -1,          /* iLast */
      7,           /* lineNo */
      5,           /* colNo */
      "map",       /* aName */
      "calcScore", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\calcScore.m", /* pName */
      0                                                  /* checkKind */
  };
  static rtBoundsCheckInfo f_emlrtBCI = {
      -1,                 /* iFirst */
      -1,                 /* iLast */
      26,                 /* lineNo */
      55,                 /* colNo */
      "map",              /* aName */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      0                                                         /* checkKind */
  };
  static rtBoundsCheckInfo g_emlrtBCI = {
      -1,          /* iFirst */
      -1,          /* iLast */
      3,           /* lineNo */
      5,           /* colNo */
      "map",       /* aName */
      "calcScore", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\calcScore.m", /* pName */
      0                                                  /* checkKind */
  };
  static rtBoundsCheckInfo h_emlrtBCI = {
      -1,          /* iFirst */
      -1,          /* iLast */
      9,           /* lineNo */
      23,          /* colNo */
      "map",       /* aName */
      "calcScore", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\calcScore.m", /* pName */
      0                                                  /* checkKind */
  };
  static rtBoundsCheckInfo i_emlrtBCI = {
      -1,          /* iFirst */
      -1,          /* iLast */
      9,           /* lineNo */
      42,          /* colNo */
      "map",       /* aName */
      "calcScore", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\calcScore.m", /* pName */
      0                                                  /* checkKind */
  };
  static rtBoundsCheckInfo j_emlrtBCI = {
      -1,          /* iFirst */
      -1,          /* iLast */
      9,           /* lineNo */
      5,           /* colNo */
      "map",       /* aName */
      "calcScore", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\calcScore.m", /* pName */
      0                                                  /* checkKind */
  };
  static rtBoundsCheckInfo k_emlrtBCI = {
      -1,                 /* iFirst */
      -1,                 /* iLast */
      30,                 /* lineNo */
      35,                 /* colNo */
      "map",              /* aName */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      0                                                         /* checkKind */
  };
  static rtBoundsCheckInfo l_emlrtBCI = {
      -1,                 /* iFirst */
      -1,                 /* iLast */
      31,                 /* lineNo */
      36,                 /* colNo */
      "map",              /* aName */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      0                                                         /* checkKind */
  };
  static rtBoundsCheckInfo m_emlrtBCI = {
      -1,                 /* iFirst */
      -1,                 /* iLast */
      32,                 /* lineNo */
      36,                 /* colNo */
      "map",              /* aName */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      0                                                         /* checkKind */
  };
  static rtBoundsCheckInfo n_emlrtBCI = {
      -1,                 /* iFirst */
      -1,                 /* iLast */
      41,                 /* lineNo */
      17,                 /* colNo */
      "map",              /* aName */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      0                                                         /* checkKind */
  };
  static rtBoundsCheckInfo o_emlrtBCI = {
      -1,                 /* iFirst */
      -1,                 /* iLast */
      44,                 /* lineNo */
      13,                 /* colNo */
      "map",              /* aName */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      0                                                         /* checkKind */
  };
  static rtDoubleCheckInfo b_emlrtDCI = {
      26,                 /* lineNo */
      48,                 /* colNo */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      1                                                         /* checkKind */
  };
  static rtDoubleCheckInfo c_emlrtDCI = {
      26,                 /* lineNo */
      55,                 /* colNo */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      1                                                         /* checkKind */
  };
  static rtDoubleCheckInfo d_emlrtDCI = {
      44,                 /* lineNo */
      13,                 /* colNo */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      1                                                         /* checkKind */
  };
  static rtDoubleCheckInfo emlrtDCI = {
      23,                 /* lineNo */
      16,                 /* colNo */
      "openAroundNodeDP", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\openAroundNodeDP.m", /* pName */
      1                                                         /* checkKind */
  };
  static const struct_T r = {
      -1.0,  /* x */
      -1.0,  /* y */
      9999U, /* score */
      9999U, /* g_cost */
      9999U  /* h_cost */
  };
  static const signed char iv[4] = {0, -1, 1, 0};
  struct_T temp_list[999];
  struct_T a__1;
  struct_T temp_node;
  double temp_open_list[999];
  double a;
  double b_a;
  double x;
  double y;
  int i;
  int idx;
  int ii_size_idx_1;
  int j;
  int k;
  unsigned int u;
  short ii_data;
  unsigned short u1;
  bool exitg1;
  for (i = 0; i < 4; i++) {
    x = ref_x + (double)iv[i];
    if ((!(x < 1.0)) && (!(x > size_x))) {
      for (j = 0; j < 3; j++) {
        if (iv[i] != 0) {
          y = ref_y;
        } else {
          y = ref_y + ((double)j + -1.0);
        }
        if ((!(y < 1.0)) && (!(y > size_y))) {
          k = map->size[0];
          if (y != (int)floor(y)) {
            rtIntegerError(y, &emlrtDCI);
          }
          if (((int)y < 1) || ((int)y > k)) {
            rtDynamicBoundsError((int)y, 1, k, &b_emlrtBCI);
          }
          k = map->size[1];
          if (x != (int)floor(x)) {
            rtIntegerError(x, &emlrtDCI);
          }
          if (((int)x < 1) || ((int)x > k)) {
            rtDynamicBoundsError((int)x, 1, k, &b_emlrtBCI);
          }
          if (map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].obstacle ==
              0) {
            k = map->size[0];
            if (((int)y < 1) || ((int)y > k)) {
              rtDynamicBoundsError((int)y, 1, k, &c_emlrtBCI);
            }
            k = map->size[1];
            if (((int)x < 1) || ((int)x > k)) {
              rtDynamicBoundsError((int)x, 1, k, &c_emlrtBCI);
            }
            if ((map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].status ==
                 0) &&
                ((!(ref_x == x)) || (!(ref_y == y)))) {
              /*  移動可能 かつ 状態がNone かつ 基準ノードでない */
              k = map->size[0];
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &d_emlrtBCI);
              }
              k = map->size[1];
              if (((int)x < 1) || ((int)x > k)) {
                rtDynamicBoundsError((int)x, 1, k, &d_emlrtBCI);
              }
              map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].status = 1U;
              /*  open */
              if (ref_y != (int)floor(ref_y)) {
                rtIntegerError(ref_y, &b_emlrtDCI);
              }
              k = map->size[0];
              if (((int)ref_y < 1) || ((int)ref_y > k)) {
                rtDynamicBoundsError((int)ref_y, 1, k, &e_emlrtBCI);
              }
              if (ref_x != (int)floor(ref_x)) {
                rtIntegerError(ref_x, &c_emlrtDCI);
              }
              k = map->size[1];
              if (((int)ref_x < 1) || ((int)ref_x > k)) {
                rtDynamicBoundsError((int)ref_x, 1, k, &f_emlrtBCI);
              }
              /*     map(y, x).g_cost = g_cost + 1 + direction_cost; */
              k = map->size[0];
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &g_emlrtBCI);
              }
              k = map->size[1];
              if (((int)x < 1) || ((int)x > k)) {
                rtDynamicBoundsError((int)x, 1, k, &g_emlrtBCI);
              }
              u = map->data[((int)ref_y + map->size[0] * ((int)ref_x - 1)) - 1]
                      .g_cost +
                  1U;
              if (u > 65535U) {
                u = 65535U;
              }
              map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].g_cost =
                  (unsigned short)u;
              /*     map(y, x).g_cost = 0; */
              /*     map(y, x).h_cost = abs(obj.goal_x - x) + abs(obj.goal_y -
               * y); */
              a = goal[0] - x;
              b_a = goal[1] - y;
              a = a * a + b_a * b_a;
              if (a < 0.0) {
                i_rtErrorWithMessageID(4, "sqrt", d_emlrtRTEI.fName,
                                       d_emlrtRTEI.lineNo);
              }
              a = sqrt(a);
              k = map->size[0];
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &emlrtBCI);
              }
              k = map->size[1];
              if (((int)x < 1) || ((int)x > k)) {
                rtDynamicBoundsError((int)x, 1, k, &emlrtBCI);
              }
              a = rt_roundd_snf(a);
              if (a < 65536.0) {
                u1 = (unsigned short)a;
              } else if (a >= 65536.0) {
                u1 = MAX_uint16_T;
              } else {
                u1 = 0U;
              }
              map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].h_cost = u1;
              /*    map(y, x).h_cost = 0; */
              k = map->size[0];
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &h_emlrtBCI);
              }
              k = map->size[1];
              if (((int)x < 1) || ((int)x > k)) {
                rtDynamicBoundsError((int)x, 1, k, &h_emlrtBCI);
              }
              k = map->size[0];
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &i_emlrtBCI);
              }
              k = map->size[1];
              if (((int)x < 1) || ((int)x > k)) {
                rtDynamicBoundsError((int)x, 1, k, &i_emlrtBCI);
              }
              k = map->size[0];
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &j_emlrtBCI);
              }
              k = map->size[1];
              if (((int)x < 1) || ((int)x > k)) {
                rtDynamicBoundsError((int)x, 1, k, &j_emlrtBCI);
              }
              u = (unsigned int)map
                      ->data[((int)y + map->size[0] * ((int)x - 1)) - 1]
                      .g_cost +
                  map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].h_cost;
              if (u > 65535U) {
                u = 65535U;
              }
              map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].score =
                  (unsigned short)u;
              /*  コストを計算 */
              temp_node.x = x;
              temp_node.y = y;
              k = map->size[0];
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &k_emlrtBCI);
              }
              k = map->size[1];
              if (((int)x < 1) || ((int)x > k)) {
                rtDynamicBoundsError((int)x, 1, k, &k_emlrtBCI);
              }
              temp_node.score =
                  map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].score;
              k = map->size[0];
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &l_emlrtBCI);
              }
              k = map->size[1];
              if (((int)x < 1) || ((int)x > k)) {
                rtDynamicBoundsError((int)x, 1, k, &l_emlrtBCI);
              }
              temp_node.g_cost =
                  map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].g_cost;
              k = map->size[0];
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &m_emlrtBCI);
              }
              k = map->size[1];
              if (((int)x < 1) || ((int)x > k)) {
                rtDynamicBoundsError((int)x, 1, k, &m_emlrtBCI);
              }
              temp_node.h_cost =
                  map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].h_cost;
              for (k = 0; k < 999; k++) {
                temp_open_list[k] = open_list[k].x;
              }
              idx = 0;
              ii_size_idx_1 = 1;
              k = 0;
              exitg1 = false;
              while ((!exitg1) && (k < 999)) {
                if (temp_open_list[k] < 0.0) {
                  idx = 1;
                  ii_data = (short)(k + 1);
                  exitg1 = true;
                } else {
                  k++;
                }
              }
              if (idx == 0) {
                ii_size_idx_1 = 0;
              }
              /*  使われていない要素のインデックスを取得 */
              for (k = 0; k < ii_size_idx_1; k++) {
                open_list[ii_data - 1] = temp_node;
              }
              k = map->size[0];
              idx = map->size[1];
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &n_emlrtBCI);
              }
              if (((int)x < 1) || ((int)x > idx)) {
                rtDynamicBoundsError((int)x, 1, idx, &n_emlrtBCI);
              }
              a = rt_roundd_snf(ref_x);
              if (a < 65536.0) {
                if (a >= 0.0) {
                  u1 = (unsigned short)a;
                } else {
                  u1 = 0U;
                }
              } else if (a >= 65536.0) {
                u1 = MAX_uint16_T;
              } else {
                u1 = 0U;
              }
              map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].parent[0] =
                  u1;
              if (((int)y < 1) || ((int)y > k)) {
                rtDynamicBoundsError((int)y, 1, k, &n_emlrtBCI);
              }
              if (((int)x < 1) || ((int)x > idx)) {
                rtDynamicBoundsError((int)x, 1, idx, &n_emlrtBCI);
              }
              a = rt_roundd_snf(ref_y);
              if (a < 65536.0) {
                if (a >= 0.0) {
                  u1 = (unsigned short)a;
                } else {
                  u1 = 0U;
                }
              } else if (a >= 65536.0) {
                u1 = MAX_uint16_T;
              } else {
                u1 = 0U;
              }
              map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].parent[1] =
                  u1;
              /* 親ノードの位置を保存 */
            }
          }
          k = map->size[0];
          if (ref_y != (int)floor(ref_y)) {
            rtIntegerError(ref_y, &d_emlrtDCI);
          }
          if (((int)ref_y < 1) || ((int)ref_y > k)) {
            rtDynamicBoundsError((int)ref_y, 1, k, &o_emlrtBCI);
          }
          k = map->size[1];
          if (ref_x != (int)floor(ref_x)) {
            rtIntegerError(ref_x, &d_emlrtDCI);
          }
          if (((int)ref_x < 1) || ((int)ref_x > k)) {
            rtDynamicBoundsError((int)ref_x, 1, k, &o_emlrtBCI);
          }
          map->data[((int)ref_y + map->size[0] * ((int)ref_x - 1)) - 1].status =
              2U;
          /* 基準ノードをクローズ */
          idx = 0;
          exitg1 = false;
          while ((!exitg1) && (idx < 999)) {
            if ((open_list[idx].x == ref_x) && (open_list[idx].y == ref_y)) {
              if (idx + 1 == 1) {
                /*  配列の最初だったら、初期化してシフトして一番うしろに持っていく
                 */
                open_list[0] = r;
                a__1 = open_list[0];
                for (k = 0; k < 998; k++) {
                  open_list[k] = open_list[k + 1];
                }
                open_list[998] = a__1;
              } else if (idx + 1 == 999) {
                /*  配列の最後だったら初期化だけする */
                open_list[998].x = -1.0;
                open_list[998].y = -1.0;
                open_list[998].score = 9999U;
                open_list[998].g_cost = 9999U;
                open_list[998].h_cost = 9999U;
              } else {
                /*  その他は対象のやつを初期化して後ろに持っていく */
                /*                  open_list(i) = init_node; */
                for (k = 0; k < 999; k++) {
                  temp_list[k] = r;
                }
                if (0 <= idx - 1) {
                  memcpy(&temp_list[0], &open_list[0], idx * sizeof(struct_T));
                }
                k = 997 - idx;
                if (0 <= k) {
                  memcpy(&temp_list[idx], &open_list[idx + 1],
                         (((k + idx) - idx) + 1) * sizeof(struct_T));
                }
                /*                  temp_list(end) = init_node; */
                memcpy(&open_list[0], &temp_list[0], 999U * sizeof(struct_T));
                /*                  first = open_list(1 : i - 1); */
                /*                  last = open_list(i : end); */
                /*                  last = circshift(last, -1); */
                /*                  open_list = horzcat(first, last); */
              }
              exitg1 = true;
            } else {
              idx++;
            }
          }
          /* オープンリストからクローズした基準ノードを削除 */
        }
      }
    }
  }
}

/*
 * File trailer for openAroundNodeDP.c
 *
 * [EOF]
 */
