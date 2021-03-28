#include "computeAstar.h"
#include "computeAstar_internal_types.h"
#include "computeAstar_types.h"
#include "openAroundNodeDP.h"
#include <string.h>

// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2021 Haruki Shimotor. All right reserved.
*/
void computeAstar(emxArray_struct0_T *map, const double start[2],
                  const double goal[2], double size_x, double size_y,
                  double shortcut_course[19998])
{
  struct_T arg_data[999];
  struct_T b_arg_data[999];
  struct_T open_list[999];
  double x;
  double y;
  int cnt;
  int temp_xy_idx_0_tmp;
  int temp_xy_idx_0_tmp_tmp;
  unsigned short store_x[9999];
  unsigned short store_y[9999];
  short ii_data[999];
  unsigned short scores[999];
  unsigned short temp_xy_idx_1;
  bool exitg1;
  x = start[0];
  y = start[1];
  for (temp_xy_idx_0_tmp = 0; temp_xy_idx_0_tmp < 999; temp_xy_idx_0_tmp++) {
    open_list[temp_xy_idx_0_tmp].x = -1.0;
    open_list[temp_xy_idx_0_tmp].y = -1.0;
    open_list[temp_xy_idx_0_tmp].score = 9999U;
    open_list[temp_xy_idx_0_tmp].g_cost = 9999U;
    open_list[temp_xy_idx_0_tmp].h_cost = 9999U;
  }
  openAroundNodeDP(map, open_list, start[0], start[1], size_x, size_y, goal);
  while ((x != goal[0]) || (y != goal[1])) {
    for (cnt = 0; cnt < 999; cnt++) {
      scores[cnt] = open_list[cnt].score;
    }
    temp_xy_idx_0_tmp_tmp = scores[0];
    for (cnt = 0; cnt < 998; cnt++) {
      temp_xy_idx_0_tmp = scores[cnt + 1];
      if (temp_xy_idx_0_tmp_tmp > temp_xy_idx_0_tmp) {
        temp_xy_idx_0_tmp_tmp = temp_xy_idx_0_tmp;
      }
    }
    cnt = 0;
    temp_xy_idx_0_tmp = 0;
    exitg1 = false;
    while ((!exitg1) && (temp_xy_idx_0_tmp < 999)) {
      if (scores[temp_xy_idx_0_tmp] == temp_xy_idx_0_tmp_tmp) {
        cnt++;
        ii_data[cnt - 1] = (short)(temp_xy_idx_0_tmp + 1);
        if (cnt >= 999) {
          exitg1 = true;
        } else {
          temp_xy_idx_0_tmp++;
        }
      } else {
        temp_xy_idx_0_tmp++;
      }
    }
    if (1 > cnt) {
      cnt = 0;
    }
    for (temp_xy_idx_0_tmp = 0; temp_xy_idx_0_tmp < cnt; temp_xy_idx_0_tmp++) {
      arg_data[temp_xy_idx_0_tmp] = open_list[ii_data[temp_xy_idx_0_tmp] - 1];
    }
    for (temp_xy_idx_0_tmp = 0; temp_xy_idx_0_tmp < cnt; temp_xy_idx_0_tmp++) {
      b_arg_data[temp_xy_idx_0_tmp] = open_list[ii_data[temp_xy_idx_0_tmp] - 1];
    }
    x = arg_data[0].x;
    y = b_arg_data[0].y;
    openAroundNodeDP(map, open_list, arg_data[0].x, b_arg_data[0].y, size_x,
                     size_y, goal);
  }
  memset(&store_x[0], 0, 9999U * sizeof(unsigned short));
  memset(&store_y[0], 0, 9999U * sizeof(unsigned short));
  cnt = 0;
  while ((x != start[0]) || (y != start[1])) {
    temp_xy_idx_0_tmp = (int)y - 1;
    temp_xy_idx_0_tmp_tmp = (int)x - 1;
    temp_xy_idx_1 =
        map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].parent[1];
    x = map->data[((int)y + map->size[0] * ((int)x - 1)) - 1].parent[0];
    y = temp_xy_idx_1;
    store_x[cnt] =
        map->data[temp_xy_idx_0_tmp + map->size[0] * temp_xy_idx_0_tmp_tmp]
            .parent[0];
    store_y[cnt] = temp_xy_idx_1;
    cnt++;
  }
  for (temp_xy_idx_0_tmp = 0; temp_xy_idx_0_tmp < 9999; temp_xy_idx_0_tmp++) {
    cnt = temp_xy_idx_0_tmp << 1;
    shortcut_course[cnt] = store_x[temp_xy_idx_0_tmp];
    shortcut_course[cnt + 1] = store_y[temp_xy_idx_0_tmp];
  }
}
