/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: movmean.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 01-Apr-2021 15:30:00
 */

/* Include Files */
#include "movmean.h"
#include "rt_nonfinite.h"

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Function Definitions */
/*
 * Arguments    : const double x[9999]
 *                double y[9999]
 * Return Type  : void
 */
void movmean(const double x[9999], double y[9999])
{
  double b_y;
  double bsum;
  int b_k;
  int firstBlockLength;
  int hi;
  int iLeft;
  int k;
  int lastBlockLength;
  int nblocks;
  int vlen;
  int xblockoffset;
  for (k = 0; k < 9999; k++) {
    if (k + 1 <= 15) {
      iLeft = 0;
    } else {
      iLeft = k - 15;
    }
    if (k + 15 > 9999) {
      b_k = 9999;
    } else {
      b_k = k + 15;
    }
    vlen = b_k - iLeft;
    if (vlen == 0) {
      b_y = 0.0;
    } else {
      if (vlen <= 1024) {
        firstBlockLength = vlen;
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = vlen / 1024;
        lastBlockLength = vlen - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }
      b_y = x[iLeft];
      for (b_k = 2; b_k <= firstBlockLength; b_k++) {
        b_y += x[(iLeft + b_k) - 1];
      }
      for (firstBlockLength = 2; firstBlockLength <= nblocks;
           firstBlockLength++) {
        xblockoffset = iLeft + ((firstBlockLength - 1) << 10);
        bsum = x[xblockoffset];
        if (firstBlockLength == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        for (b_k = 2; b_k <= hi; b_k++) {
          bsum += x[(xblockoffset + b_k) - 1];
        }
        b_y += bsum;
      }
    }
    y[k] = b_y / (double)vlen;
  }
}

/*
 * File trailer for movmean.c
 *
 * [EOF]
 */
