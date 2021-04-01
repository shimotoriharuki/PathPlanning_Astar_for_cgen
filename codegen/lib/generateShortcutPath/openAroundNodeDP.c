/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: openAroundNodeDP.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 01-Apr-2021 14:26:53
 */

/* Include Files */
#include "openAroundNodeDP.h"
#include "generateShortcutPath_internal_types.h"
#include "generateShortcutPath_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

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
  int ii;
  int ii_size_idx_1;
  int j;
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
          if ((map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].obstacle ==
               0) &&
              (map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].status ==
               0) &&
              ((!(ref_x == x)) || (!(ref_y == y)))) {
            /*  移動可能 かつ 状態がNone かつ 基準ノードでない */
            map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].status = 1U;
            /*  open */
            /*     map(y, x).g_cost = g_cost + 1 + direction_cost; */
            u = map->data[((int)ref_y + map->size[0] * ((int)ref_x - 1)) - 1]
                    .g_cost +
                1U;
            if (u > 65535U) {
              u = 65535U;
            }
            map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].g_cost =
                (unsigned short)u;
            /*     map(y, x).g_cost = 0; */
            /*     map(y, x).h_cost = abs(obj.goal_x - x) + abs(obj.goal_y - y);
             */
            a = goal[0] - x;
            b_a = goal[1] - y;
            a = rt_roundd_snf(sqrt(a * a + b_a * b_a));
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
            map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].h_cost = u1;
            /*    map(y, x).h_cost = 0; */
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
            temp_node.score =
                map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].score;
            temp_node.g_cost =
                map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].g_cost;
            temp_node.h_cost =
                map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].h_cost;
            /*                  open_list = [open_list, temp_node];
             * %オープンリストに追加 */
            for (idx = 0; idx < 999; idx++) {
              temp_open_list[idx] = open_list[idx].x;
            }
            idx = 0;
            ii_size_idx_1 = 1;
            ii = 0;
            exitg1 = false;
            while ((!exitg1) && (ii < 999)) {
              if (temp_open_list[ii] < 0.0) {
                idx = 1;
                ii_data = (short)(ii + 1);
                exitg1 = true;
              } else {
                ii++;
              }
            }
            if (idx == 0) {
              ii_size_idx_1 = 0;
            }
            /*  使われていない要素のインデックスを取得 */
            for (idx = 0; idx < ii_size_idx_1; idx++) {
              open_list[ii_data - 1] = temp_node;
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
          map->data[((int)ref_y + map->size[0] * ((int)ref_x - 1)) - 1].status =
              2U;
          /* 基準ノードをクローズ */
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii < 999)) {
            if ((open_list[ii].x == ref_x) && (open_list[ii].y == ref_y)) {
              if (ii + 1 == 1) {
                /*  配列の最初だったら、初期化してシフトして一番うしろに持っていく
                 */
                open_list[0] = r;
                a__1 = open_list[0];
                for (idx = 0; idx < 998; idx++) {
                  open_list[idx] = open_list[idx + 1];
                }
                open_list[998] = a__1;
              } else if (ii + 1 == 999) {
                /*  配列の最後だったら初期化だけする */
                open_list[998].x = -1.0;
                open_list[998].y = -1.0;
                open_list[998].score = 9999U;
                open_list[998].g_cost = 9999U;
                open_list[998].h_cost = 9999U;
              } else {
                /*  その他は対象のやつを初期化して後ろに持っていく */
                /*                  open_list(i) = init_node; */
                for (idx = 0; idx < 999; idx++) {
                  temp_list[idx] = r;
                }
                if (0 <= ii - 1) {
                  memcpy(&temp_list[0], &open_list[0], ii * sizeof(struct_T));
                }
                idx = 997 - ii;
                if (0 <= idx) {
                  memcpy(&temp_list[ii], &open_list[ii + 1],
                         (((idx + ii) - ii) + 1) * sizeof(struct_T));
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
              ii++;
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
