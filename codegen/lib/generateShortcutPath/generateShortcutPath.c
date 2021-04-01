/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: generateShortcutPath.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 01-Apr-2021 14:26:53
 */

/* Include Files */
#include "generateShortcutPath.h"
#include "find.h"
#include "flip.h"
#include "generateShortcutPath_emxutil.h"
#include "generateShortcutPath_internal_types.h"
#include "generateShortcutPath_types.h"
#include "linspace.h"
#include "median.h"
#include "minOrMax.h"
#include "movmean.h"
#include "openAroundNodeDP.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * ------------------正の整数にするためにマージンをとる---------------- %
 *
 * Arguments    : const emxArray_real_T *src_course
 *                double shortcut_course[19998]
 * Return Type  : void
 */
void generateShortcutPath(const emxArray_real_T *src_course,
                          double shortcut_course[19998])
{
  static const b_struct_T r2 = {
      1U,      /* obstacle */
      0U,      /* status */
      0U,      /* g_cost */
      0U,      /* h_cost */
      0U,      /* score */
      {0U, 0U} /* parent */
  };
  static double c_shortcut_course[9999];
  static double store_x[9999];
  static double store_y[9999];
  emxArray_boolean_T *b_x;
  emxArray_int32_T *i;
  emxArray_int8_T *flag_table;
  emxArray_real_T *b_index;
  emxArray_real_T *b_src_course;
  emxArray_real_T *course_y;
  emxArray_real_T *diffs;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *remaining_course;
  emxArray_real_T *trimming_course;
  emxArray_struct_T *empty_map;
  struct_T arg_data[999];
  struct_T b_arg_data[999];
  struct_T open_list[999];
  struct_T arg_tmp;
  double scores[999];
  double goal[2];
  double d;
  double goal_x;
  double goal_y;
  double min_x;
  double min_y;
  double ref_position_idx_0;
  double ref_position_idx_1;
  double size_x;
  double size_y;
  double x;
  double y;
  int index_data[999];
  int index_size[2];
  int b_i;
  int b_loop_ub;
  int firstBlockLength;
  int ib;
  int idx;
  int k;
  int lastBlockLength;
  int loop_ub;
  int n;
  int nx;
  unsigned short temp_xy_idx_0;
  unsigned short temp_xy_idx_1;
  short tmp_data;
  bool b_shortcut_course[9999];
  bool b_scores[999];
  bool exitg1;
  emxInit_real_T(&b_index, 2);
  loop_ub = src_course->size[1];
  ib = b_index->size[0] * b_index->size[1];
  b_index->size[0] = 1;
  b_index->size[1] = src_course->size[1];
  emxEnsureCapacity_real_T(b_index, ib);
  for (ib = 0; ib < loop_ub; ib++) {
    b_index->data[ib] = src_course->data[2 * ib];
  }
  emxInit_real_T(&course_y, 2);
  loop_ub = src_course->size[1];
  ib = course_y->size[0] * course_y->size[1];
  course_y->size[0] = 1;
  course_y->size[1] = src_course->size[1];
  emxEnsureCapacity_real_T(course_y, ib);
  for (ib = 0; ib < loop_ub; ib++) {
    course_y->data[ib] = src_course->data[2 * ib + 1];
  }
  emxInit_real_T(&b_src_course, 2);
  /*  ------------------正の整数にするためにマージンをとる---------------- % */
  loop_ub = src_course->size[1];
  ib = b_src_course->size[0] * b_src_course->size[1];
  b_src_course->size[0] = 1;
  b_src_course->size[1] = src_course->size[1];
  emxEnsureCapacity_real_T(b_src_course, ib);
  for (ib = 0; ib < loop_ub; ib++) {
    b_src_course->data[ib] = src_course->data[2 * ib];
  }
  min_x = minimum(b_src_course);
  loop_ub = src_course->size[1];
  ib = b_src_course->size[0] * b_src_course->size[1];
  b_src_course->size[0] = 1;
  b_src_course->size[1] = src_course->size[1];
  emxEnsureCapacity_real_T(b_src_course, ib);
  for (ib = 0; ib < loop_ub; ib++) {
    b_src_course->data[ib] = src_course->data[2 * ib + 1];
  }
  min_y = minimum(b_src_course);
  if (min_x < 0.0) {
    x = fabs(min_x);
    linspace(x, x, src_course->size[1], b_index);
    loop_ub = src_course->size[1];
    ib = b_index->size[0] * b_index->size[1];
    b_index->size[0] = 1;
    b_index->size[1] = src_course->size[1];
    emxEnsureCapacity_real_T(b_index, ib);
    for (ib = 0; ib < loop_ub; ib++) {
      b_index->data[ib] += src_course->data[2 * ib];
    }
  }
  if (min_y < 0.0) {
    ref_position_idx_0 = fabs(min_y);
    linspace(ref_position_idx_0, ref_position_idx_0, src_course->size[1],
             course_y);
    loop_ub = src_course->size[1];
    ib = course_y->size[0] * course_y->size[1];
    course_y->size[0] = 1;
    course_y->size[1] = src_course->size[1];
    emxEnsureCapacity_real_T(course_y, ib);
    for (ib = 0; ib < loop_ub; ib++) {
      course_y->data[ib] += src_course->data[2 * ib + 1];
    }
  }
  emxInit_real_T(&remaining_course, 2);
  ib = remaining_course->size[0] * remaining_course->size[1];
  remaining_course->size[0] = 2;
  remaining_course->size[1] = b_index->size[1];
  emxEnsureCapacity_real_T(remaining_course, ib);
  loop_ub = b_index->size[1];
  for (ib = 0; ib < loop_ub; ib++) {
    remaining_course->data[2 * ib] = b_index->data[ib];
  }
  loop_ub = course_y->size[1];
  for (ib = 0; ib < loop_ub; ib++) {
    remaining_course->data[2 * ib + 1] = course_y->data[ib];
  }
  /*      start_x = course(1, 1) + 1; */
  /*      start_y = course(2, 1) + 1; */
  goal_x = remaining_course->data[2 * (remaining_course->size[1] - 1)] + 1.0;
  goal_y =
      remaining_course->data[2 * (remaining_course->size[1] - 1) + 1] + 1.0;
  /*  必要なマップのサイズを調べる */
  loop_ub = remaining_course->size[1];
  ib = b_src_course->size[0] * b_src_course->size[1];
  b_src_course->size[0] = 1;
  b_src_course->size[1] = remaining_course->size[1];
  emxEnsureCapacity_real_T(b_src_course, ib);
  for (ib = 0; ib < loop_ub; ib++) {
    b_src_course->data[ib] = remaining_course->data[2 * ib];
  }
  loop_ub = remaining_course->size[1];
  ib = course_y->size[0] * course_y->size[1];
  course_y->size[0] = 1;
  course_y->size[1] = remaining_course->size[1];
  emxEnsureCapacity_real_T(course_y, ib);
  for (ib = 0; ib < loop_ub; ib++) {
    course_y->data[ib] = remaining_course->data[2 * ib];
  }
  size_x = (maximum(b_src_course) - minimum(course_y)) + 1.0;
  /*  xのベクトルの最大値-最小値でマップのx方向サイズを計算  */
  loop_ub = remaining_course->size[1];
  ib = b_src_course->size[0] * b_src_course->size[1];
  b_src_course->size[0] = 1;
  b_src_course->size[1] = remaining_course->size[1];
  emxEnsureCapacity_real_T(b_src_course, ib);
  for (ib = 0; ib < loop_ub; ib++) {
    b_src_course->data[ib] = remaining_course->data[2 * ib + 1];
  }
  loop_ub = remaining_course->size[1];
  ib = course_y->size[0] * course_y->size[1];
  course_y->size[0] = 1;
  course_y->size[1] = remaining_course->size[1];
  emxEnsureCapacity_real_T(course_y, ib);
  for (ib = 0; ib < loop_ub; ib++) {
    course_y->data[ib] = remaining_course->data[2 * ib + 1];
  }
  size_y = (maximum(b_src_course) - minimum(course_y)) + 1.0;
  /*  yのベクトルの最大値-最小値でマップのy方向サイズを計算 */
  /*  flag_table = getFlagTable(course, 10, 10); */
  /*      shortcut_course = repmat(-1, 2, length(course(1, :))); */
  for (ib = 0; ib < 19998; ib++) {
    shortcut_course[ib] = -1.0;
  }
  emxInit_int8_T(&flag_table, 2);
  emxInit_real_T(&trimming_course, 2);
  emxInit_struct_T(&empty_map, 2);
  emxInit_real_T(&r, 2);
  emxInit_real_T(&r1, 2);
  /*      for i = 1 : 1 */
  loop_ub = (int)size_y * (int)size_x;
  emxInit_real_T(&diffs, 2);
  emxInit_int32_T(&i, 2);
  emxInit_boolean_T(&b_x, 2);
  do {
    /*  コースを交差点で切る */
    firstBlockLength = remaining_course->size[1];
    if (2 > firstBlockLength) {
      firstBlockLength = 2;
    }
    if (remaining_course->size[1] == 0) {
      n = 0;
    } else {
      n = firstBlockLength;
    }
    ib = flag_table->size[0] * flag_table->size[1];
    flag_table->size[0] = 1;
    flag_table->size[1] = n;
    emxEnsureCapacity_int8_T(flag_table, ib);
    for (ib = 0; ib < n; ib++) {
      flag_table->data[ib] = 0;
    }
    firstBlockLength = remaining_course->size[1];
    if (2 > firstBlockLength) {
      firstBlockLength = 2;
    }
    if (remaining_course->size[1] == 0) {
      n = 0;
    } else {
      n = firstBlockLength;
    }
    for (b_i = 0; b_i < n; b_i++) {
      /*  search_meginから検索することで、同じ交差点を検知することを防ぐ */
      ref_position_idx_0 = remaining_course->data[2 * b_i];
      ref_position_idx_1 = remaining_course->data[2 * b_i + 1];
      ib = diffs->size[0] * diffs->size[1];
      diffs->size[0] = 2;
      diffs->size[1] = remaining_course->size[1];
      emxEnsureCapacity_real_T(diffs, ib);
      nx = remaining_course->size[1] << 1;
      for (ib = 0; ib < nx; ib++) {
        diffs->data[ib] = 0.0;
      }
      ib = remaining_course->size[1] - 1;
      for (idx = 0; idx <= ib; idx++) {
        diffs->data[2 * idx] =
            remaining_course->data[2 * idx] - ref_position_idx_0;
        lastBlockLength = 2 * idx + 1;
        diffs->data[lastBlockLength] =
            remaining_course->data[lastBlockLength] - ref_position_idx_1;
      }
      /*          diffs = src_course - ref_position; */
      /*  すべての点とref_positionとの距離を計算 */
      nx = diffs->size[1];
      ib = course_y->size[0] * course_y->size[1];
      course_y->size[0] = 1;
      course_y->size[1] = diffs->size[1];
      emxEnsureCapacity_real_T(course_y, ib);
      for (ib = 0; ib < nx; ib++) {
        course_y->data[ib] = diffs->data[2 * ib];
      }
      ib = b_src_course->size[0] * b_src_course->size[1];
      b_src_course->size[0] = 1;
      b_src_course->size[1] = course_y->size[1];
      emxEnsureCapacity_real_T(b_src_course, ib);
      nx = course_y->size[1];
      for (k = 0; k < nx; k++) {
        d = diffs->data[2 * k];
        b_src_course->data[k] = d * d;
      }
      nx = diffs->size[1];
      ib = course_y->size[0] * course_y->size[1];
      course_y->size[0] = 1;
      course_y->size[1] = diffs->size[1];
      emxEnsureCapacity_real_T(course_y, ib);
      for (ib = 0; ib < nx; ib++) {
        course_y->data[ib] = diffs->data[2 * ib + 1];
      }
      ib = b_index->size[0] * b_index->size[1];
      b_index->size[0] = 1;
      b_index->size[1] = course_y->size[1];
      emxEnsureCapacity_real_T(b_index, ib);
      nx = course_y->size[1];
      for (k = 0; k < nx; k++) {
        d = diffs->data[2 * k + 1];
        b_index->data[k] = d * d;
      }
      ib = b_src_course->size[0] * b_src_course->size[1];
      b_src_course->size[0] = 1;
      emxEnsureCapacity_real_T(b_src_course, ib);
      nx = b_src_course->size[1] - 1;
      for (ib = 0; ib <= nx; ib++) {
        b_src_course->data[ib] += b_index->data[ib];
      }
      nx = b_src_course->size[1];
      for (k = 0; k < nx; k++) {
        b_src_course->data[k] = sqrt(b_src_course->data[k]);
      }
      ib = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = b_src_course->size[1];
      emxEnsureCapacity_boolean_T(b_x, ib);
      nx = b_src_course->size[1];
      for (ib = 0; ib < nx; ib++) {
        b_x->data[ib] = (b_src_course->data[ib] <= 10.0);
      }
      nx = b_x->size[1];
      idx = 0;
      ib = i->size[0] * i->size[1];
      i->size[0] = 1;
      i->size[1] = b_x->size[1];
      emxEnsureCapacity_int32_T(i, ib);
      firstBlockLength = 0;
      exitg1 = false;
      while ((!exitg1) && (firstBlockLength <= nx - 1)) {
        if (b_x->data[firstBlockLength]) {
          idx++;
          i->data[idx - 1] = firstBlockLength + 1;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            firstBlockLength++;
          }
        } else {
          firstBlockLength++;
        }
      }
      if (b_x->size[1] == 1) {
        if (idx == 0) {
          i->size[0] = 1;
          i->size[1] = 0;
        }
      } else {
        ib = i->size[0] * i->size[1];
        if (1 > idx) {
          i->size[1] = 0;
        } else {
          i->size[1] = idx;
        }
        emxEnsureCapacity_int32_T(i, ib);
      }
      ib = b_index->size[0] * b_index->size[1];
      b_index->size[0] = 1;
      b_index->size[1] = i->size[1];
      emxEnsureCapacity_real_T(b_index, ib);
      nx = i->size[1];
      for (ib = 0; ib < nx; ib++) {
        b_index->data[ib] = i->data[ib];
      }
      /*  距離がrange以下だったインデックスを取得 */
      x = median(b_index);
      ib = course_y->size[0] * course_y->size[1];
      course_y->size[0] = 1;
      course_y->size[1] = b_index->size[1];
      emxEnsureCapacity_real_T(course_y, ib);
      nx = b_index->size[1];
      for (ib = 0; ib < nx; ib++) {
        course_y->data[ib] = b_index->data[ib] - x;
      }
      nx = course_y->size[1];
      ib = b_src_course->size[0] * b_src_course->size[1];
      b_src_course->size[0] = 1;
      b_src_course->size[1] = course_y->size[1];
      emxEnsureCapacity_real_T(b_src_course, ib);
      for (k = 0; k < nx; k++) {
        b_src_course->data[k] = fabs(course_y->data[k]);
      }
      ref_position_idx_0 = 1.4826022185056018 * median(b_src_course);
      ref_position_idx_1 = x - 3.0 * ref_position_idx_0;
      x += 3.0 * ref_position_idx_0;
      /*  外れ値検知　外れ値があったら外れ値の位置に1がたつ */
      /*  すべて足す */
      /*  1以上（1つでも外れ値があったら）だったら交差している */
      ib = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = b_index->size[1];
      emxEnsureCapacity_boolean_T(b_x, ib);
      nx = b_index->size[1];
      for (ib = 0; ib < nx; ib++) {
        d = b_index->data[ib];
        b_x->data[ib] = ((d < ref_position_idx_1) || (d > x));
      }
      if (b_x->size[1] == 0) {
        x = 0.0;
      } else {
        if (b_x->size[1] <= 1024) {
          firstBlockLength = b_x->size[1];
          lastBlockLength = 0;
          nx = 1;
        } else {
          firstBlockLength = 1024;
          nx = b_x->size[1] / 1024;
          lastBlockLength = b_x->size[1] - (nx << 10);
          if (lastBlockLength > 0) {
            nx++;
          } else {
            lastBlockLength = 1024;
          }
        }
        x = b_x->data[0];
        for (k = 2; k <= firstBlockLength; k++) {
          x += (double)b_x->data[k - 1];
        }
        for (ib = 2; ib <= nx; ib++) {
          idx = (ib - 1) << 10;
          ref_position_idx_0 = b_x->data[idx];
          if (ib == nx) {
            firstBlockLength = lastBlockLength;
          } else {
            firstBlockLength = 1024;
          }
          for (k = 2; k <= firstBlockLength; k++) {
            ref_position_idx_0 += (double)b_x->data[(idx + k) - 1];
          }
          x += ref_position_idx_0;
        }
      }
      if (x >= 1.0) {
        /*  交差点だったら */
        flag_table->data[b_i] = 1;
      }
    }
    /*  白線を拡大した分、交差フラグをある程度前後に発生させる */
    ib = flag_table->size[1];
    for (b_i = 0; b_i <= ib - 2; b_i++) {
      /*  0から1か1から0に変わるところに2を置く */
      if (flag_table->data[b_i] != flag_table->data[b_i + 1]) {
        flag_table->data[b_i] = 2;
      }
    }
    ib = flag_table->size[1];
    for (b_i = 0; b_i < ib; b_i++) {
      /*  2がある前後を1にする */
      if (flag_table->data[b_i] == 2) {
        for (idx = 0; idx < 10; idx++) {
          lastBlockLength = (b_i + idx) - 4;
          if (flag_table->data[lastBlockLength] != 2) {
            flag_table->data[lastBlockLength] = 1;
          }
        }
        flag_table->data[b_i] = 1;
      }
    }
    ib = flag_table->size[1];
    for (b_i = 0; b_i <= ib - 2; b_i++) {
      /*  0から1か1から0に変わるところに3を置く */
      if (flag_table->data[b_i] != flag_table->data[b_i + 1]) {
        flag_table->data[b_i] = 3;
      }
    }
    /*  コースを分けるところだけ1にする */
    ib = flag_table->size[1];
    for (b_i = 0; b_i < ib; b_i++) {
      if (flag_table->data[b_i] == 3) {
        flag_table->data[b_i] = 1;
      } else {
        flag_table->data[b_i] = 0;
      }
    }
    ib = trimming_course->size[0] * trimming_course->size[1];
    trimming_course->size[0] = 2;
    trimming_course->size[1] = remaining_course->size[1];
    emxEnsureCapacity_real_T(trimming_course, ib);
    nx = 2 * remaining_course->size[1];
    for (ib = 0; ib < nx; ib++) {
      trimming_course->data[ib] = remaining_course->data[ib];
    }
    b_i = 0;
    exitg1 = false;
    while ((!exitg1) && (b_i <= flag_table->size[1] - 1)) {
      if (flag_table->data[b_i] == 1) {
        ib = trimming_course->size[0] * trimming_course->size[1];
        trimming_course->size[0] = 2;
        trimming_course->size[1] = b_i + 1;
        emxEnsureCapacity_real_T(trimming_course, ib);
        for (ib = 0; ib <= b_i; ib++) {
          trimming_course->data[2 * ib] = remaining_course->data[2 * ib];
        }
        for (ib = 0; ib <= b_i; ib++) {
          lastBlockLength = 2 * ib + 1;
          trimming_course->data[lastBlockLength] =
              remaining_course->data[lastBlockLength];
        }
        if (b_i + 2U > (unsigned int)remaining_course->size[1]) {
          b_i = -1;
          ib = -2;
          lastBlockLength = 0;
          idx = 0;
        } else {
          ib = remaining_course->size[1] - 2;
          lastBlockLength = b_i + 1;
          idx = remaining_course->size[1];
        }
        firstBlockLength = diffs->size[0] * diffs->size[1];
        diffs->size[0] = 2;
        nx = ib - b_i;
        diffs->size[1] = nx + 1;
        emxEnsureCapacity_real_T(diffs, firstBlockLength);
        for (ib = 0; ib <= nx; ib++) {
          diffs->data[2 * ib] = remaining_course->data[2 * ((b_i + ib) + 1)];
        }
        nx = idx - lastBlockLength;
        for (ib = 0; ib < nx; ib++) {
          diffs->data[2 * ib + 1] =
              remaining_course->data[2 * (lastBlockLength + ib) + 1];
        }
        ib = remaining_course->size[0] * remaining_course->size[1];
        remaining_course->size[0] = 2;
        remaining_course->size[1] = diffs->size[1];
        emxEnsureCapacity_real_T(remaining_course, ib);
        nx = 2 * diffs->size[1];
        for (ib = 0; ib < nx; ib++) {
          remaining_course->data[ib] = diffs->data[ib];
        }
        exitg1 = true;
      } else {
        b_i++;
      }
    }
    /*  マップを作成する */
    /* cm 膨張させる大きさ */
    ib = empty_map->size[0] * empty_map->size[1];
    empty_map->size[0] = (int)size_y;
    empty_map->size[1] = (int)size_x;
    emxEnsureCapacity_struct_T(empty_map, ib);
    for (ib = 0; ib < loop_ub; ib++) {
      empty_map->data[ib] = r2;
    }
    /*  行、列　＝　y, x */
    ib = trimming_course->size[1] - 1;
    for (b_i = 0; b_i <= ib; b_i++) {
      d = trimming_course->data[2 * b_i];
      ref_position_idx_0 = trimming_course->data[2 * b_i + 1];
      for (idx = 0; idx < 10; idx++) {
        for (firstBlockLength = 0; firstBlockLength < 10; firstBlockLength++) {
          x = ((d + 1.0) - 5.0) + ((double)idx + 1.0);
          y = ((ref_position_idx_0 + 1.0) - 5.0) +
              ((double)firstBlockLength + 1.0);
          if (x < 1.0) {
            x = 1.0;
          } else if (x > size_x) {
            x = size_x;
          }
          if (y < 1.0) {
            y = 1.0;
          } else if (y > size_y) {
            y = size_y;
          }
          empty_map->data[((int)y + empty_map->size[0] * ((int)x - 1)) - 1]
              .obstacle = 0U;
        }
      }
    }
    /* バイナリマップ */
    /*          size_map = size_x * size_y; */
    /*          plotMap(map) % プロット */
    /*  最短経路を計算 */
    ref_position_idx_0 = trimming_course->data[0] + 1.0;
    ref_position_idx_1 = trimming_course->data[1] + 1.0;
    goal[0] = trimming_course->data[2 * (trimming_course->size[1] - 1)] + 1.0;
    goal[1] =
        trimming_course->data[2 * (trimming_course->size[1] - 1) + 1] + 1.0;
    /*      [shortcut_course] = computeAstar_mex(map, start, goal, size_x,
     * size_y); */
    /*  % -----------A star開始------------ % */
    x = ref_position_idx_0;
    y = ref_position_idx_1;
    /*      pre_x = x; */
    /*      pre_y = y; */
    /*      cost_table = [1, 1, 1; */
    /*                    1, 0, 1; */
    /*                    0, 0, 0]; */
    /*      open_list = []; */
    for (ib = 0; ib < 999; ib++) {
      open_list[ib].x = -1.0;
      open_list[ib].y = -1.0;
      open_list[ib].score = 9999U;
      open_list[ib].g_cost = 9999U;
      open_list[ib].h_cost = 9999U;
    }
    openAroundNodeDP(empty_map, open_list, ref_position_idx_0,
                     ref_position_idx_1, size_x, size_y, goal);
    /*  スタートノードの周りをオープン */
    /*      for i = 1 : 10000  */
    while ((x != goal[0]) || (y != goal[1])) {
      for (b_i = 0; b_i < 999; b_i++) {
        scores[b_i] = open_list[b_i].score;
      }
      x = b_minimum(scores);
      for (ib = 0; ib < 999; ib++) {
        b_scores[ib] = (scores[ib] == x);
      }
      eml_find(b_scores, index_data, index_size);
      /*  最小スコアのインデックスを取得 */
      /*      if length(index) > 1 %最小のコストが複数あったら */
      /*  %           disp('HERE') */
      /*          min_cost = 99999; */
      /*          min_index = []; */
      /*          for j = index */
      /*  %           disp(num2str(open_list(j).x)); */
      /*  %           disp(num2str(open_list(j).y)); */
      /*   */
      /*              if open_list(j).g_cost < min_cost */
      /*                  min_cost = open_list(j).g_cost; */
      /*                  min_index = j; */
      /*              end */
      /*          end      */
      /*      else  */
      /*  %        disp('here') */
      /*          min_index = index; */
      /*      end */
      nx = index_size[1];
      for (ib = 0; ib < nx; ib++) {
        arg_tmp = open_list[index_data[ib] - 1];
        arg_data[ib] = arg_tmp;
        b_arg_data[ib] = arg_tmp;
      }
      x = arg_data[0].x;
      y = b_arg_data[0].y;
      /*  スコアが最も小さいノードのx, yを得る */
      /*          cost_table = getCostTable(x, y, pre_x, pre_y); %
       * コストテーブルを更新  */
      openAroundNodeDP(empty_map, open_list, arg_data[0].x, b_arg_data[0].y,
                       size_x, size_y, goal);
      /*          pre_x = x; */
      /*          pre_y = y; */
    }
    /*      disp(count) */
    /*  % -----------最短経路の座標を取得------------ % */
    /*      map.shorter_path_grid(y, x) = 2; */
    memset(&store_x[0], 0, 9999U * sizeof(double));
    memset(&store_y[0], 0, 9999U * sizeof(double));
    firstBlockLength = 0;
    while ((x != ref_position_idx_0) || (y != ref_position_idx_1)) {
      temp_xy_idx_0 =
          empty_map->data[((int)y + empty_map->size[0] * ((int)x - 1)) - 1]
              .parent[0];
      temp_xy_idx_1 =
          empty_map->data[((int)y + empty_map->size[0] * ((int)x - 1)) - 1]
              .parent[1];
      x = empty_map->data[((int)y + empty_map->size[0] * ((int)x - 1)) - 1]
              .parent[0];
      y = temp_xy_idx_1;
      /*          x = temp_xy(1); */
      /*          y = temp_xy(2); */
      store_x[firstBlockLength] = temp_xy_idx_0;
      store_y[firstBlockLength] = temp_xy_idx_1;
      firstBlockLength++;
    }
    if (1 > firstBlockLength) {
      nx = 0;
      firstBlockLength = 0;
    } else {
      nx = firstBlockLength;
    }
    ib = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = nx;
    emxEnsureCapacity_real_T(r, ib);
    for (ib = 0; ib < nx; ib++) {
      r->data[ib] = store_x[ib];
    }
    flip(r);
    ib = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = firstBlockLength;
    emxEnsureCapacity_real_T(r1, ib);
    for (ib = 0; ib < firstBlockLength; ib++) {
      r1->data[ib] = store_y[ib];
    }
    flip(r1);
    ib = diffs->size[0] * diffs->size[1];
    diffs->size[0] = 2;
    diffs->size[1] = r->size[1];
    emxEnsureCapacity_real_T(diffs, ib);
    nx = r->size[1];
    for (ib = 0; ib < nx; ib++) {
      diffs->data[2 * ib] = r->data[ib];
    }
    nx = r1->size[1];
    for (ib = 0; ib < nx; ib++) {
      diffs->data[2 * ib + 1] = r1->data[ib];
    }
    /*  順序が逆なのでflipでもとに戻す */
    /*  切り取られたコースを連結する */
    for (ib = 0; ib < 9999; ib++) {
      b_shortcut_course[ib] = (shortcut_course[ib << 1] < 0.0);
    }
    b_eml_find(b_shortcut_course, (int *)&idx, index_size);
    ib = diffs->size[1] - 1;
    if (0 <= diffs->size[1] - 1) {
      b_loop_ub = index_size[1];
    }
    for (k = 0; k <= ib; k++) {
      for (lastBlockLength = 0; lastBlockLength < b_loop_ub;
           lastBlockLength++) {
        tmp_data = (short)((short)((double)idx + (double)k) - 1);
      }
      ref_position_idx_0 = diffs->data[2 * k];
      ref_position_idx_1 = diffs->data[2 * k + 1];
      nx = index_size[1];
      for (lastBlockLength = 0; lastBlockLength < nx; lastBlockLength++) {
        firstBlockLength = tmp_data << 1;
        shortcut_course[firstBlockLength] = ref_position_idx_0;
        shortcut_course[firstBlockLength + 1] = ref_position_idx_1;
      }
    }
    /*  ゴールに着いたら処理を終了 */
  } while (!((trimming_course->data[2 * (trimming_course->size[1] - 1)] ==
              goal_x - 1.0) &&
             (trimming_course->data[2 * (trimming_course->size[1] - 1) + 1] ==
              goal_y - 1.0)));
  emxFree_real_T(&b_src_course);
  emxFree_real_T(&r1);
  emxFree_real_T(&r);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&i);
  emxFree_struct_T(&empty_map);
  emxFree_real_T(&b_index);
  emxFree_real_T(&diffs);
  emxFree_real_T(&course_y);
  emxFree_real_T(&trimming_course);
  emxFree_int8_T(&flag_table);
  emxFree_real_T(&remaining_course);
  for (ib = 0; ib < 19998; ib++) {
    shortcut_course[ib]--;
  }
  /* 行列のインデックスにするために1を足していたのを引く */
  x = fabs(min_x);
  ref_position_idx_0 = fabs(min_y);
  b_linspace(x, x, store_x);
  for (ib = 0; ib < 9999; ib++) {
    lastBlockLength = ib << 1;
    d = shortcut_course[lastBlockLength] - store_x[ib];
    store_x[ib] = d;
    shortcut_course[lastBlockLength] = d;
  }
  b_linspace(ref_position_idx_0, ref_position_idx_0, store_x);
  /*  正にマージンしていた分を取り除く */
  for (ib = 0; ib < 9999; ib++) {
    lastBlockLength = ib << 1;
    d = shortcut_course[lastBlockLength + 1] - store_x[ib];
    store_x[ib] = d;
    shortcut_course[lastBlockLength + 1] = d;
    c_shortcut_course[ib] = shortcut_course[lastBlockLength];
  }
  movmean(c_shortcut_course, store_x);
  for (ib = 0; ib < 9999; ib++) {
    firstBlockLength = ib << 1;
    c_shortcut_course[ib] = shortcut_course[firstBlockLength + 1];
    shortcut_course[firstBlockLength] = store_x[ib];
  }
  movmean(c_shortcut_course, store_y);
  for (ib = 0; ib < 9999; ib++) {
    shortcut_course[(ib << 1) + 1] = store_y[ib];
  }
  /*  平滑化のため移動平均を計算 */
}

/*
 * File trailer for generateShortcutPath.c
 *
 * [EOF]
 */
