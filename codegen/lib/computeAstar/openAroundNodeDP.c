#include "openAroundNodeDP.h"
#include "computeAstar_internal_types.h"
#include "computeAstar_types.h"
#include <math.h>

// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2021 Haruki Shimotor. All right reserved.
*/
static double rt_roundd_snf(double u);

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

void openAroundNodeDP(emxArray_struct0_T *map, struct_T open_list[999],
                      double ref_x, double ref_y, double size_x, double size_y,
                      const double goal[2])
{
  static const signed char iv[4] = {0, -1, 1, 0};
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
            map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].status = 1U;
            u = map->data[((int)ref_y + map->size[0] * ((int)ref_x - 1)) - 1]
                    .g_cost +
                1U;
            if (u > 65535U) {
              u = 65535U;
            }
            map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].g_cost =
                (unsigned short)u;
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
            u = (unsigned int)map
                    ->data[((int)y + map->size[0] * ((int)x - 1)) - 1]
                    .g_cost +
                map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].h_cost;
            if (u > 65535U) {
              u = 65535U;
            }
            map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].score =
                (unsigned short)u;
            temp_node.x = x;
            temp_node.y = y;
            temp_node.score =
                map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].score;
            temp_node.g_cost =
                map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].g_cost;
            temp_node.h_cost =
                map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].h_cost;
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
          }
          map->data[((int)ref_y + map->size[0] * ((int)ref_x - 1)) - 1].status =
              2U;
          idx = 0;
          exitg1 = false;
          while ((!exitg1) && (idx < 999)) {
            if ((open_list[idx].x == ref_x) && (open_list[idx].y == ref_y)) {
              open_list[idx].x = -1.0;
              open_list[idx].y = -1.0;
              open_list[idx].score = 9999U;
              open_list[idx].g_cost = 9999U;
              open_list[idx].h_cost = 9999U;
              exitg1 = true;
            } else {
              idx++;
            }
          }
        }
      }
    }
  }
}
