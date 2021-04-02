/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: generateShortcutPath.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 02-Apr-2021 16:12:11
 */

/* Include Files */
#include "generateShortcutPath.h"
#include "applyToMultipleDims.h"
#include "computeAstar.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "generateShortcutPath_data.h"
#include "generateShortcutPath_emxutil.h"
#include "generateShortcutPath_rtwutil.h"
#include "generateShortcutPath_types.h"
#include "linspace.h"
#include "median.h"
#include "minOrMax.h"
#include "movmean.h"
#include "power.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Custom Source Code */
// SPDX-License-Identifier: GPL-3.0-only
/*
     Copyright (C) 2022  Haruki Shimotori. All right reserved.
*/
/* Type Definitions */
#ifndef typedef_rtEqualityCheckInfo
#define typedef_rtEqualityCheckInfo
typedef struct {
  int nDims;
  int lineNo;
  int colNo;
  const char *fName;
  const char *pName;
} rtEqualityCheckInfo;
#endif /* typedef_rtEqualityCheckInfo */

/* Function Declarations */
static void rtAddSizeString(char *aBuf, const int aDim);

static void rtGenSizeString(const int aNDims, const int *aDims, char *aBuf);

static void rtSizeEqNDCheck(const int *aDims1, const int *aDims2,
                            const rtEqualityCheckInfo *aInfo);

static void rtSubAssignSizeCheck(const int *aDims1, const int aNDims1,
                                 const int *aDims2, const int aNDims2,
                                 const rtEqualityCheckInfo *aInfo);

/* Function Definitions */
/*
 * Arguments    : char *aBuf
 *                const int aDim
 * Return Type  : void
 */
static void rtAddSizeString(char *aBuf, const int aDim)
{
  char b_dimStr[1024];
  char dimStr[1024];
  sprintf(&dimStr[0], "[%d]", aDim);
  if (strlen(&aBuf[0]) + strlen(&dimStr[0]) < 1024) {
    memcpy(&b_dimStr[0], &dimStr[0], 1024U * sizeof(char));
    strcat(aBuf, b_dimStr);
  }
}

/*
 * Arguments    : const int aNDims
 *                const int *aDims
 *                char *aBuf
 * Return Type  : void
 */
static void rtGenSizeString(const int aNDims, const int *aDims, char *aBuf)
{
  int i;
  aBuf[0] = '\x00';
  for (i = 0; i < aNDims; i++) {
    rtAddSizeString(aBuf, aDims[i]);
  }
}

/*
 * Arguments    : const int *aDims1
 *                const int *aDims2
 *                const rtEqualityCheckInfo *aInfo
 * Return Type  : void
 */
static void rtSizeEqNDCheck(const int *aDims1, const int *aDims2,
                            const rtEqualityCheckInfo *aInfo)
{
  int i;
  char b_dims1Str[1024];
  char b_dims2Str[1024];
  char dims1Str[1024];
  char dims2Str[1024];
  for (i = 0; i < aInfo->nDims; i++) {
    if (aDims1[i] != aDims2[i]) {
      rtGenSizeString(aInfo->nDims, aDims1, dims1Str);
      rtGenSizeString(aInfo->nDims, aDims2, dims2Str);
      memcpy(&b_dims1Str[0], &dims1Str[0], 1024U * sizeof(char));
      memcpy(&b_dims2Str[0], &dims2Str[0], 1024U * sizeof(char));
      fprintf(stderr, "Sizes mismatch: %s ~= %s.", b_dims1Str, b_dims2Str);
      fprintf(stderr, "\n");
      rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
      fflush(stderr);
      abort();
    }
  }
}

/*
 * Arguments    : const int *aDims1
 *                const int aNDims1
 *                const int *aDims2
 *                const int aNDims2
 *                const rtEqualityCheckInfo *aInfo
 * Return Type  : void
 */
static void rtSubAssignSizeCheck(const int *aDims1, const int aNDims1,
                                 const int *aDims2, const int aNDims2,
                                 const rtEqualityCheckInfo *aInfo)
{
  int i;
  int j;
  char b_dims1Str[1024];
  char b_dims2Str[1024];
  char dims1Str[1024];
  char dims2Str[1024];
  i = 0;
  j = 0;
  while ((i < aNDims1) && (j < aNDims2)) {
    while ((i < aNDims1) && (aDims1[i] == 1)) {
      i++;
    }
    while ((j < aNDims2) && (aDims2[j] == 1)) {
      j++;
    }
    if (((i < aNDims1) || (j < aNDims2)) &&
        ((i == aNDims1) || ((j == aNDims2) || ((aDims1[i] != -1) &&
                                               ((aDims2[j] != -1) &&
                                                (aDims1[i] != aDims2[j])))))) {
      rtGenSizeString(aNDims1, aDims1, dims1Str);
      rtGenSizeString(aNDims1, aDims2, dims2Str);
      memcpy(&b_dims1Str[0], &dims1Str[0], 1024U * sizeof(char));
      memcpy(&b_dims2Str[0], &dims2Str[0], 1024U * sizeof(char));
      fprintf(stderr, "Subscripted assignment dimension mismatch: %s ~= %s.",
              b_dims1Str, b_dims2Str);
      fprintf(stderr, "\n");
      rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
      fflush(stderr);
      abort();
    }
    i++;
    j++;
  }
}

/*
 * ------------------正の整数にするためにマージンをとる---------------- %
 *
 * Arguments    : const emxArray_real_T *src_course
 *                double range
 *                double shortcut_course[19998]
 * Return Type  : void
 */
void generateShortcutPath(const emxArray_real_T *src_course, double range,
                          double shortcut_course[19998])
{
  static rtBoundsCheckInfo ab_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      7,              /* lineNo */
      60,             /* colNo */
      "course",       /* aName */
      "courseTrimer", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\courseTrimer.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo b_emlrtBCI = {
      -1,                     /* iFirst */
      -1,                     /* iLast */
      6,                      /* lineNo */
      14,                     /* colNo */
      "course",               /* aName */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo bb_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      7,              /* lineNo */
      64,             /* colNo */
      "course",       /* aName */
      "courseTrimer", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\courseTrimer.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo c_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      5,              /* lineNo */
      25,             /* colNo */
      "src_course",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo cb_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      8,              /* lineNo */
      43,             /* colNo */
      "course",       /* aName */
      "courseTrimer", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\courseTrimer.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo d_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      5,              /* lineNo */
      43,             /* colNo */
      "src_course",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo db_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      8,              /* lineNo */
      51,             /* colNo */
      "course",       /* aName */
      "courseTrimer", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\courseTrimer.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo e_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      9,              /* lineNo */
      27,             /* colNo */
      "src_course",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo eb_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      8,              /* lineNo */
      67,             /* colNo */
      "course",       /* aName */
      "courseTrimer", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\courseTrimer.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo emlrtBCI = {
      -1,                     /* iFirst */
      -1,                     /* iLast */
      5,                      /* lineNo */
      14,                     /* colNo */
      "course",               /* aName */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo f_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      9,              /* lineNo */
      13,             /* colNo */
      "diffs",        /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo fb_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      8,              /* lineNo */
      75,             /* colNo */
      "course",       /* aName */
      "courseTrimer", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\courseTrimer.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo g_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      10,             /* lineNo */
      27,             /* colNo */
      "src_course",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo gb_emlrtBCI = {
      -1,          /* iFirst */
      -1,          /* iLast */
      19,          /* lineNo */
      29,          /* colNo */
      "x_datas",   /* aName */
      "createMap", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\createMap.m", /* pName */
      0                                                  /* checkKind */
  };
  static rtBoundsCheckInfo h_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      10,             /* lineNo */
      13,             /* colNo */
      "diffs",        /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo hb_emlrtBCI = {
      -1,          /* iFirst */
      -1,          /* iLast */
      20,          /* lineNo */
      29,          /* colNo */
      "y_datas",   /* aName */
      "createMap", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\createMap.m", /* pName */
      0                                                  /* checkKind */
  };
  static rtBoundsCheckInfo i_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      22,             /* lineNo */
      13,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo ib_emlrtBCI = {
      -1,          /* iFirst */
      -1,          /* iLast */
      33,          /* lineNo */
      17,          /* colNo */
      "empty_map", /* aName */
      "createMap", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\createMap.m", /* pName */
      0                                                  /* checkKind */
  };
  static rtBoundsCheckInfo j_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      28,             /* lineNo */
      12,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo jb_emlrtBCI = {
      -1,                     /* iFirst */
      -1,                     /* iLast */
      25,                     /* lineNo */
      37,                     /* colNo */
      "trimming_course",      /* aName */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo k_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      28,             /* lineNo */
      29,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo kb_emlrtBCI = {
      -1,                     /* iFirst */
      -1,                     /* iLast */
      26,                     /* lineNo */
      36,                     /* colNo */
      "trimming_course",      /* aName */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo l_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      29,             /* lineNo */
      13,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo lb_emlrtBCI = {
      1,                      /* iFirst */
      9999,                   /* iLast */
      33,                     /* lineNo */
      32,                     /* colNo */
      "shortcut_course",      /* aName */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m", /* pName */
      3 /* checkKind */
  };
  static rtBoundsCheckInfo m_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      34,             /* lineNo */
      12,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo mb_emlrtBCI = {
      -1,                     /* iFirst */
      -1,                     /* iLast */
      33,                     /* lineNo */
      61,                     /* colNo */
      "store_course",         /* aName */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo n_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      36,             /* lineNo */
      20,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo nb_emlrtBCI = {
      -1,                     /* iFirst */
      -1,                     /* iLast */
      37,                     /* lineNo */
      12,                     /* colNo */
      "trimming_course",      /* aName */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo o_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      37,             /* lineNo */
      21,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo ob_emlrtBCI = {
      -1,                     /* iFirst */
      -1,                     /* iLast */
      37,                     /* lineNo */
      53,                     /* colNo */
      "trimming_course",      /* aName */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo p_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      40,             /* lineNo */
      12,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo pb_emlrtBCI = {
      -1,                     /* iFirst */
      -1,                     /* iLast */
      43,                     /* lineNo */
      31,                     /* colNo */
      "end_index",            /* aName */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo q_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      45,             /* lineNo */
      12,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo qb_emlrtBCI = {
      1,                      /* iFirst */
      9999,                   /* iLast */
      44,                     /* lineNo */
      70,                     /* colNo */
      "shortcut_course",      /* aName */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m", /* pName */
      0 /* checkKind */
  };
  static rtBoundsCheckInfo r_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      45,             /* lineNo */
      29,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo s_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      46,             /* lineNo */
      13,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo t_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      52,             /* lineNo */
      12,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo u_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      53,             /* lineNo */
      13,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo v_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      55,             /* lineNo */
      13,             /* colNo */
      "flag_table",   /* aName */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo w_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      6,              /* lineNo */
      12,             /* colNo */
      "flag_table",   /* aName */
      "courseTrimer", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\courseTrimer.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo x_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      7,              /* lineNo */
      42,             /* colNo */
      "course",       /* aName */
      "courseTrimer", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\courseTrimer.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtBoundsCheckInfo y_emlrtBCI = {
      -1,             /* iFirst */
      -1,             /* iLast */
      7,              /* lineNo */
      46,             /* colNo */
      "course",       /* aName */
      "courseTrimer", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\courseTrimer.m", /* pName */
      0                                                     /* checkKind */
  };
  static rtDoubleCheckInfo emlrtDCI = {
      33,          /* lineNo */
      17,          /* colNo */
      "createMap", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\createMap.m", /* pName */
      1                                                  /* checkKind */
  };
  static rtEqualityCheckInfo b_emlrtECI = {
      2,                           /* nDims */
      11,                          /* lineNo */
      20,                          /* colNo */
      "moveCoordinatesPositively", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\moveCoordinatesPositively.m" /* pName
                                                                         */
  };
  static rtEqualityCheckInfo c_emlrtECI = {
      2,              /* nDims */
      13,             /* lineNo */
      26,             /* colNo */
      "getFlagTable", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\getFlagTable.m" /* pName */
  };
  static rtEqualityCheckInfo d_emlrtECI = {
      -1,                     /* nDims */
      33,                     /* lineNo */
      13,                     /* colNo */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m" /* pName */
  };
  static rtEqualityCheckInfo e_emlrtECI = {
      -1,                     /* nDims */
      44,                     /* lineNo */
      5,                      /* colNo */
      "generateShortcutPath", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\generateShortcutPath.m" /* pName */
  };
  static rtEqualityCheckInfo emlrtECI = {
      2,                           /* nDims */
      7,                           /* lineNo */
      20,                          /* colNo */
      "moveCoordinatesPositively", /* fName */
      "C:\\Users\\under\\MATLAB "
      "Drive\\PathPlanning_Astar_for_Cgen\\moveCoordinatesPositively.m" /* pName
                                                                         */
  };
  static double c_shortcut_course[9999];
  static double d_shortcut_course[9999];
  emxArray_boolean_T *b_margin_y;
  emxArray_int32_T *ii;
  emxArray_int8_T *flag_table;
  emxArray_real_T *b_remaining_course;
  emxArray_real_T *b_src_course;
  emxArray_real_T *diffs;
  emxArray_real_T *margin_x;
  emxArray_real_T *margin_y;
  emxArray_real_T *remaining_course;
  emxArray_real_T *store_course;
  emxArray_struct_T *empty_map;
  double ref_position[2];
  double trimming_course[2];
  double amad;
  double d;
  double expantion;
  double goal_x;
  double goal_y;
  double half_expantion;
  double lb;
  double min_x;
  double min_y;
  double size_x;
  double size_y;
  double x;
  int index_size[2];
  int iv[2];
  int iv1[2];
  int b_i;
  int b_loop_ub;
  int c_loop_ub;
  int i;
  int i1;
  int i2;
  int index_data;
  int loop_ub;
  int n;
  int nx;
  short tmp_data;
  bool b_shortcut_course[9999];
  bool exitg1;
  bool p;
  emxInit_real_T(&margin_x, 2);
  loop_ub = src_course->size[1];
  i = margin_x->size[0] * margin_x->size[1];
  margin_x->size[0] = 1;
  margin_x->size[1] = src_course->size[1];
  emxEnsureCapacity_real_T(margin_x, i);
  for (i = 0; i < loop_ub; i++) {
    margin_x->data[i] = src_course->data[2 * i];
  }
  emxInit_real_T(&margin_y, 2);
  loop_ub = src_course->size[1];
  i = margin_y->size[0] * margin_y->size[1];
  margin_y->size[0] = 1;
  margin_y->size[1] = src_course->size[1];
  emxEnsureCapacity_real_T(margin_y, i);
  for (i = 0; i < loop_ub; i++) {
    margin_y->data[i] = src_course->data[2 * i + 1];
  }
  emxInit_real_T(&b_src_course, 2);
  /*  ------------------正の整数にするためにマージンをとる---------------- % */
  loop_ub = src_course->size[1];
  i = b_src_course->size[0] * b_src_course->size[1];
  b_src_course->size[0] = 1;
  b_src_course->size[1] = src_course->size[1];
  emxEnsureCapacity_real_T(b_src_course, i);
  for (i = 0; i < loop_ub; i++) {
    b_src_course->data[i] = src_course->data[2 * i];
  }
  min_x = minimum(b_src_course);
  loop_ub = src_course->size[1];
  i = b_src_course->size[0] * b_src_course->size[1];
  b_src_course->size[0] = 1;
  b_src_course->size[1] = src_course->size[1];
  emxEnsureCapacity_real_T(b_src_course, i);
  for (i = 0; i < loop_ub; i++) {
    b_src_course->data[i] = src_course->data[2 * i + 1];
  }
  min_y = minimum(b_src_course);
  if (min_x < 0.0) {
    x = fabs(min_x);
    linspace(x, x, src_course->size[1], margin_x);
    loop_ub = src_course->size[1];
    i = b_src_course->size[0] * b_src_course->size[1];
    b_src_course->size[0] = 1;
    b_src_course->size[1] = src_course->size[1];
    emxEnsureCapacity_real_T(b_src_course, i);
    for (i = 0; i < loop_ub; i++) {
      b_src_course->data[i] = src_course->data[2 * i];
    }
    index_size[0] = (*(int(*)[2])b_src_course->size)[0];
    index_size[1] = (*(int(*)[2])b_src_course->size)[1];
    iv[0] = (*(int(*)[2])margin_x->size)[0];
    iv[1] = (*(int(*)[2])margin_x->size)[1];
    rtSizeEqNDCheck(&index_size[0], &iv[0], &emlrtECI);
    loop_ub = src_course->size[1];
    i = margin_x->size[0] * margin_x->size[1];
    margin_x->size[0] = 1;
    margin_x->size[1] = src_course->size[1];
    emxEnsureCapacity_real_T(margin_x, i);
    for (i = 0; i < loop_ub; i++) {
      margin_x->data[i] += src_course->data[2 * i];
    }
  }
  if (min_y < 0.0) {
    amad = fabs(min_y);
    linspace(amad, amad, src_course->size[1], margin_y);
    loop_ub = src_course->size[1];
    i = b_src_course->size[0] * b_src_course->size[1];
    b_src_course->size[0] = 1;
    b_src_course->size[1] = src_course->size[1];
    emxEnsureCapacity_real_T(b_src_course, i);
    for (i = 0; i < loop_ub; i++) {
      b_src_course->data[i] = src_course->data[2 * i + 1];
    }
    index_size[0] = (*(int(*)[2])b_src_course->size)[0];
    index_size[1] = (*(int(*)[2])b_src_course->size)[1];
    iv[0] = (*(int(*)[2])margin_y->size)[0];
    iv[1] = (*(int(*)[2])margin_y->size)[1];
    rtSizeEqNDCheck(&index_size[0], &iv[0], &b_emlrtECI);
    loop_ub = src_course->size[1];
    i = margin_y->size[0] * margin_y->size[1];
    margin_y->size[0] = 1;
    margin_y->size[1] = src_course->size[1];
    emxEnsureCapacity_real_T(margin_y, i);
    for (i = 0; i < loop_ub; i++) {
      margin_y->data[i] += src_course->data[2 * i + 1];
    }
  }
  if (margin_y->size[1] != margin_x->size[1]) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  emxInit_real_T(&remaining_course, 2);
  i = remaining_course->size[0] * remaining_course->size[1];
  remaining_course->size[0] = 2;
  remaining_course->size[1] = margin_x->size[1];
  emxEnsureCapacity_real_T(remaining_course, i);
  loop_ub = margin_x->size[1];
  for (i = 0; i < loop_ub; i++) {
    remaining_course->data[2 * i] = margin_x->data[i];
  }
  loop_ub = margin_y->size[1];
  for (i = 0; i < loop_ub; i++) {
    remaining_course->data[2 * i + 1] = margin_y->data[i];
  }
  if (remaining_course->size[1] < 1) {
    rtDynamicBoundsError(remaining_course->size[1], 1,
                         remaining_course->size[1], &emlrtBCI);
  }
  goal_x = remaining_course->data[2 * (remaining_course->size[1] - 1)] + 1.0;
  if (remaining_course->size[1] < 1) {
    rtDynamicBoundsError(remaining_course->size[1], 1,
                         remaining_course->size[1], &b_emlrtBCI);
  }
  goal_y =
      remaining_course->data[2 * (remaining_course->size[1] - 1) + 1] + 1.0;
  /*  必要なマップのサイズを調べる */
  loop_ub = remaining_course->size[1];
  i = b_src_course->size[0] * b_src_course->size[1];
  b_src_course->size[0] = 1;
  b_src_course->size[1] = remaining_course->size[1];
  emxEnsureCapacity_real_T(b_src_course, i);
  for (i = 0; i < loop_ub; i++) {
    b_src_course->data[i] = remaining_course->data[2 * i];
  }
  x = maximum(b_src_course);
  loop_ub = remaining_course->size[1];
  i = b_src_course->size[0] * b_src_course->size[1];
  b_src_course->size[0] = 1;
  b_src_course->size[1] = remaining_course->size[1];
  emxEnsureCapacity_real_T(b_src_course, i);
  for (i = 0; i < loop_ub; i++) {
    b_src_course->data[i] = remaining_course->data[2 * i];
  }
  amad = minimum(b_src_course);
  size_x = (x - amad) + 1.0;
  /*  xのベクトルの最大値-最小値でマップのx方向サイズを計算  */
  loop_ub = remaining_course->size[1];
  i = b_src_course->size[0] * b_src_course->size[1];
  b_src_course->size[0] = 1;
  b_src_course->size[1] = remaining_course->size[1];
  emxEnsureCapacity_real_T(b_src_course, i);
  for (i = 0; i < loop_ub; i++) {
    b_src_course->data[i] = remaining_course->data[2 * i + 1];
  }
  x = maximum(b_src_course);
  loop_ub = remaining_course->size[1];
  i = b_src_course->size[0] * b_src_course->size[1];
  b_src_course->size[0] = 1;
  b_src_course->size[1] = remaining_course->size[1];
  emxEnsureCapacity_real_T(b_src_course, i);
  for (i = 0; i < loop_ub; i++) {
    b_src_course->data[i] = remaining_course->data[2 * i + 1];
  }
  amad = minimum(b_src_course);
  size_y = (x - amad) + 1.0;
  /*  yのベクトルの最大値-最小値でマップのy方向サイズを計算 */
  for (i = 0; i < 19998; i++) {
    shortcut_course[i] = -1.0;
  }
  emxInit_int8_T(&flag_table, 2);
  expantion = rt_roundd_snf(range);
  half_expantion = rt_roundd_snf(expantion / 2.0);
  emxInit_real_T(&store_course, 2);
  emxInit_real_T(&diffs, 2);
  emxInit_int32_T(&ii, 2);
  emxInit_struct_T(&empty_map, 2);
  emxInit_boolean_T(&b_margin_y, 2);
  emxInit_real_T(&b_remaining_course, 2);
  do {
    do {
      /*  コースを交差点で切る */
      nx = remaining_course->size[1];
      if (2 > nx) {
        nx = 2;
      }
      if (remaining_course->size[1] == 0) {
        n = 0;
      } else {
        n = nx;
      }
      i = flag_table->size[0] * flag_table->size[1];
      flag_table->size[0] = 1;
      flag_table->size[1] = n;
      emxEnsureCapacity_int8_T(flag_table, i);
      for (i = 0; i < n; i++) {
        flag_table->data[i] = 0;
      }
      nx = remaining_course->size[1];
      if (2 > nx) {
        nx = 2;
      }
      if (remaining_course->size[1] == 0) {
        n = 0;
      } else {
        n = nx;
      }
      for (b_i = 0; b_i < n; b_i++) {
        /*  search_meginから検索することで、同じ交差点を検知することを防ぐ */
        if (b_i + 1 > remaining_course->size[1]) {
          rtDynamicBoundsError(b_i + 1, 1, remaining_course->size[1],
                               &c_emlrtBCI);
        }
        ref_position[0] = remaining_course->data[2 * b_i];
        if (b_i + 1 > remaining_course->size[1]) {
          rtDynamicBoundsError(b_i + 1, 1, remaining_course->size[1],
                               &d_emlrtBCI);
        }
        ref_position[1] = remaining_course->data[2 * b_i + 1];
        i = diffs->size[0] * diffs->size[1];
        diffs->size[0] = 2;
        diffs->size[1] = remaining_course->size[1];
        emxEnsureCapacity_real_T(diffs, i);
        loop_ub = remaining_course->size[1] << 1;
        for (i = 0; i < loop_ub; i++) {
          diffs->data[i] = 0.0;
        }
        i = remaining_course->size[1] - 1;
        for (nx = 0; nx <= i; nx++) {
          if (nx + 1 > remaining_course->size[1]) {
            rtDynamicBoundsError(nx + 1, 1, remaining_course->size[1],
                                 &e_emlrtBCI);
          }
          if (nx + 1 > diffs->size[1]) {
            rtDynamicBoundsError(nx + 1, 1, diffs->size[1], &f_emlrtBCI);
          }
          diffs->data[2 * nx] =
              remaining_course->data[2 * nx] - ref_position[0];
          if (nx + 1 > remaining_course->size[1]) {
            rtDynamicBoundsError(nx + 1, 1, remaining_course->size[1],
                                 &g_emlrtBCI);
          }
          if (nx + 1 > diffs->size[1]) {
            rtDynamicBoundsError(nx + 1, 1, diffs->size[1], &h_emlrtBCI);
          }
          i1 = 2 * nx + 1;
          diffs->data[i1] = remaining_course->data[i1] - ref_position[1];
        }
        loop_ub = diffs->size[1];
        i = b_src_course->size[0] * b_src_course->size[1];
        b_src_course->size[0] = 1;
        b_src_course->size[1] = diffs->size[1];
        emxEnsureCapacity_real_T(b_src_course, i);
        for (i = 0; i < loop_ub; i++) {
          b_src_course->data[i] = diffs->data[2 * i];
        }
        power(b_src_course, margin_y);
        loop_ub = diffs->size[1];
        i = b_src_course->size[0] * b_src_course->size[1];
        b_src_course->size[0] = 1;
        b_src_course->size[1] = diffs->size[1];
        emxEnsureCapacity_real_T(b_src_course, i);
        for (i = 0; i < loop_ub; i++) {
          b_src_course->data[i] = diffs->data[2 * i + 1];
        }
        power(b_src_course, margin_x);
        index_size[0] = (*(int(*)[2])margin_y->size)[0];
        index_size[1] = (*(int(*)[2])margin_y->size)[1];
        iv[0] = (*(int(*)[2])margin_x->size)[0];
        iv[1] = (*(int(*)[2])margin_x->size)[1];
        rtSizeEqNDCheck(&index_size[0], &iv[0], &c_emlrtECI);
        i = margin_y->size[0] * margin_y->size[1];
        margin_y->size[0] = 1;
        emxEnsureCapacity_real_T(margin_y, i);
        loop_ub = margin_y->size[1] - 1;
        for (i = 0; i <= loop_ub; i++) {
          margin_y->data[i] += margin_x->data[i];
        }
        p = false;
        i = margin_y->size[1];
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          if (p || (margin_y->data[loop_ub] < 0.0)) {
            p = true;
          }
        }
        if (p) {
          b_rtErrorWithMessageID(4, "sqrt", b_emlrtRTEI.fName,
                                 b_emlrtRTEI.lineNo);
        }
        nx = margin_y->size[1];
        if ((1 <= margin_y->size[1]) && (margin_y->size[1] > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (loop_ub = 0; loop_ub < nx; loop_ub++) {
          margin_y->data[loop_ub] = sqrt(margin_y->data[loop_ub]);
        }
        /*  すべての点とref_positionとの距離を計算 */
        i = b_margin_y->size[0] * b_margin_y->size[1];
        b_margin_y->size[0] = 1;
        b_margin_y->size[1] = margin_y->size[1];
        emxEnsureCapacity_boolean_T(b_margin_y, i);
        loop_ub = margin_y->size[1];
        for (i = 0; i < loop_ub; i++) {
          b_margin_y->data[i] = (margin_y->data[i] <= 10.0);
        }
        eml_find(b_margin_y, ii);
        i = margin_x->size[0] * margin_x->size[1];
        margin_x->size[0] = 1;
        margin_x->size[1] = ii->size[1];
        emxEnsureCapacity_real_T(margin_x, i);
        loop_ub = ii->size[1];
        for (i = 0; i < loop_ub; i++) {
          margin_x->data[i] = ii->data[i];
        }
        /*  距離がrange以下だったインデックスを取得 */
        x = median(margin_x);
        i = margin_y->size[0] * margin_y->size[1];
        margin_y->size[0] = 1;
        margin_y->size[1] = margin_x->size[1];
        emxEnsureCapacity_real_T(margin_y, i);
        loop_ub = margin_x->size[1];
        for (i = 0; i < loop_ub; i++) {
          margin_y->data[i] = margin_x->data[i] - x;
        }
        nx = margin_y->size[1];
        i = b_src_course->size[0] * b_src_course->size[1];
        b_src_course->size[0] = 1;
        b_src_course->size[1] = margin_y->size[1];
        emxEnsureCapacity_real_T(b_src_course, i);
        if ((1 <= margin_y->size[1]) && (margin_y->size[1] > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (loop_ub = 0; loop_ub < nx; loop_ub++) {
          b_src_course->data[loop_ub] = fabs(margin_y->data[loop_ub]);
        }
        amad = 1.4826022185056018 * median(b_src_course);
        lb = x - 3.0 * amad;
        x += 3.0 * amad;
        /*  外れ値検知　外れ値があったら外れ値の位置に1がたつ */
        /*  すべて足す */
        /*  1以上（1つでも外れ値があったら）だったら交差している */
        i = b_margin_y->size[0] * b_margin_y->size[1];
        b_margin_y->size[0] = 1;
        b_margin_y->size[1] = margin_x->size[1];
        emxEnsureCapacity_boolean_T(b_margin_y, i);
        loop_ub = margin_x->size[1];
        for (i = 0; i < loop_ub; i++) {
          d = margin_x->data[i];
          b_margin_y->data[i] = ((d < lb) || (d > x));
        }
        if (applyToMultipleDims(b_margin_y) >= 1.0) {
          /*  交差点だったら */
          if (b_i + 1 > flag_table->size[1]) {
            rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &i_emlrtBCI);
          }
          flag_table->data[b_i] = 1;
        }
      }
      /*  白線を拡大した分、交差フラグをある程度前後に発生させる */
      i = flag_table->size[1];
      for (b_i = 0; b_i <= i - 2; b_i++) {
        /*  0から1か1から0に変わるところに2を置く */
        if (b_i + 1 > flag_table->size[1]) {
          rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &j_emlrtBCI);
        }
        if (b_i + 2 > flag_table->size[1]) {
          rtDynamicBoundsError(b_i + 2, 1, flag_table->size[1], &k_emlrtBCI);
        }
        if (flag_table->data[b_i] != flag_table->data[b_i + 1]) {
          if (b_i + 1 > flag_table->size[1]) {
            rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &l_emlrtBCI);
          }
          flag_table->data[b_i] = 2;
        }
      }
      i = flag_table->size[1];
      for (b_i = 0; b_i < i; b_i++) {
        /*  2がある前後を1にする */
        if (b_i + 1 > flag_table->size[1]) {
          rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &m_emlrtBCI);
        }
        if (flag_table->data[b_i] == 2) {
          for (nx = 0; nx < 10; nx++) {
            i1 = (b_i + nx) - 3;
            if ((i1 < 1) || (i1 > flag_table->size[1])) {
              rtDynamicBoundsError(i1, 1, flag_table->size[1], &n_emlrtBCI);
            }
            if (flag_table->data[i1 - 1] != 2) {
              if (i1 > flag_table->size[1]) {
                rtDynamicBoundsError(i1, 1, flag_table->size[1], &o_emlrtBCI);
              }
              flag_table->data[i1 - 1] = 1;
            }
          }
          if (b_i + 1 > flag_table->size[1]) {
            rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &p_emlrtBCI);
          }
          flag_table->data[b_i] = 1;
        }
      }
      i = flag_table->size[1];
      for (b_i = 0; b_i <= i - 2; b_i++) {
        /*  0から1か1から0に変わるところに3を置く */
        if (b_i + 1 > flag_table->size[1]) {
          rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &q_emlrtBCI);
        }
        if (b_i + 2 > flag_table->size[1]) {
          rtDynamicBoundsError(b_i + 2, 1, flag_table->size[1], &r_emlrtBCI);
        }
        if (flag_table->data[b_i] != flag_table->data[b_i + 1]) {
          if (b_i + 1 > flag_table->size[1]) {
            rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &s_emlrtBCI);
          }
          flag_table->data[b_i] = 3;
        }
      }
      /*  コースを分けるところだけ1にする */
      i = flag_table->size[1];
      for (b_i = 0; b_i < i; b_i++) {
        if (b_i + 1 > flag_table->size[1]) {
          rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &t_emlrtBCI);
        }
        if (flag_table->data[b_i] == 3) {
          if (b_i + 1 > flag_table->size[1]) {
            rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &u_emlrtBCI);
          }
          flag_table->data[b_i] = 1;
        } else {
          if (b_i + 1 > flag_table->size[1]) {
            rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &v_emlrtBCI);
          }
          flag_table->data[b_i] = 0;
        }
      }
      i = diffs->size[0] * diffs->size[1];
      diffs->size[0] = 2;
      diffs->size[1] = remaining_course->size[1];
      emxEnsureCapacity_real_T(diffs, i);
      loop_ub = 2 * remaining_course->size[1];
      for (i = 0; i < loop_ub; i++) {
        diffs->data[i] = remaining_course->data[i];
      }
      b_i = 0;
      exitg1 = false;
      while ((!exitg1) && (b_i <= flag_table->size[1] - 1)) {
        if (b_i + 1 > flag_table->size[1]) {
          rtDynamicBoundsError(b_i + 1, 1, flag_table->size[1], &w_emlrtBCI);
        }
        if (flag_table->data[b_i] == 1) {
          if (1 > remaining_course->size[1]) {
            rtDynamicBoundsError(1, 1, remaining_course->size[1], &x_emlrtBCI);
          }
          if (b_i + 1 > remaining_course->size[1]) {
            rtDynamicBoundsError(b_i + 1, 1, remaining_course->size[1],
                                 &y_emlrtBCI);
          }
          if (1 > remaining_course->size[1]) {
            rtDynamicBoundsError(1, 1, remaining_course->size[1], &ab_emlrtBCI);
          }
          if (b_i + 1 > remaining_course->size[1]) {
            rtDynamicBoundsError(b_i + 1, 1, remaining_course->size[1],
                                 &bb_emlrtBCI);
          }
          i = diffs->size[0] * diffs->size[1];
          diffs->size[0] = 2;
          diffs->size[1] = b_i + 1;
          emxEnsureCapacity_real_T(diffs, i);
          for (i = 0; i <= b_i; i++) {
            diffs->data[2 * i] = remaining_course->data[2 * i];
          }
          for (i = 0; i <= b_i; i++) {
            i1 = 2 * i + 1;
            diffs->data[i1] = remaining_course->data[i1];
          }
          if (b_i + 2U > (unsigned int)remaining_course->size[1]) {
            b_i = -1;
            i = -1;
            i1 = 0;
            nx = -1;
          } else {
            if (((int)(b_i + 2U) < 1) ||
                ((int)(b_i + 2U) > remaining_course->size[1])) {
              rtDynamicBoundsError((int)(b_i + 2U), 1,
                                   remaining_course->size[1], &cb_emlrtBCI);
            }
            if (remaining_course->size[1] < 1) {
              rtDynamicBoundsError(remaining_course->size[1], 1,
                                   remaining_course->size[1], &db_emlrtBCI);
            }
            i = remaining_course->size[1] - 1;
            if (((int)(b_i + 2U) < 1) ||
                ((int)(b_i + 2U) > remaining_course->size[1])) {
              rtDynamicBoundsError((int)(b_i + 2U), 1,
                                   remaining_course->size[1], &eb_emlrtBCI);
            }
            i1 = b_i + 1;
            if (remaining_course->size[1] < 1) {
              rtDynamicBoundsError(remaining_course->size[1], 1,
                                   remaining_course->size[1], &fb_emlrtBCI);
            }
            nx = remaining_course->size[1] - 1;
          }
          loop_ub = i - b_i;
          nx -= i1;
          if (nx + 1 != loop_ub) {
            rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
          }
          i = b_remaining_course->size[0] * b_remaining_course->size[1];
          b_remaining_course->size[0] = 2;
          b_remaining_course->size[1] = loop_ub;
          emxEnsureCapacity_real_T(b_remaining_course, i);
          for (i = 0; i < loop_ub; i++) {
            b_remaining_course->data[2 * i] =
                remaining_course->data[2 * ((b_i + i) + 1)];
          }
          for (i = 0; i <= nx; i++) {
            b_remaining_course->data[2 * i + 1] =
                remaining_course->data[2 * (i1 + i) + 1];
          }
          i = remaining_course->size[0] * remaining_course->size[1];
          remaining_course->size[0] = 2;
          remaining_course->size[1] = b_remaining_course->size[1];
          emxEnsureCapacity_real_T(remaining_course, i);
          loop_ub = 2 * b_remaining_course->size[1];
          for (i = 0; i < loop_ub; i++) {
            remaining_course->data[i] = b_remaining_course->data[i];
          }
          exitg1 = true;
        } else {
          b_i++;
        }
      }
      /*  マップを作成する */
      /* cm 膨張させる大きさ */
      repmat(size_y, size_x, empty_map);
      /*  行、列　＝　y, x */
      i = diffs->size[1] - 1;
      for (b_i = 0; b_i <= i; b_i++) {
        i1 = (int)expantion;
        for (nx = 0; nx < i1; nx++) {
          for (index_data = 0; index_data < i1; index_data++) {
            if (b_i + 1 > diffs->size[1]) {
              rtDynamicBoundsError(b_i + 1, 1, diffs->size[1], &gb_emlrtBCI);
            }
            x = ((diffs->data[2 * b_i] + 1.0) - half_expantion) +
                ((double)nx + 1.0);
            if (b_i + 1 > diffs->size[1]) {
              rtDynamicBoundsError(b_i + 1, 1, diffs->size[1], &hb_emlrtBCI);
            }
            amad = ((diffs->data[2 * b_i + 1] + 1.0) - half_expantion) +
                   ((double)index_data + 1.0);
            if (x < 1.0) {
              x = 1.0;
            } else if (x > size_x) {
              x = size_x;
            }
            if (amad < 1.0) {
              amad = 1.0;
            } else if (amad > size_y) {
              amad = size_y;
            }
            if (amad != (int)floor(amad)) {
              rtIntegerError(amad, &emlrtDCI);
            }
            if (((int)amad < 1) || ((int)amad > empty_map->size[0])) {
              rtDynamicBoundsError((int)amad, 1, empty_map->size[0],
                                   &ib_emlrtBCI);
            }
            if (x != (int)floor(x)) {
              rtIntegerError(x, &emlrtDCI);
            }
            if (((int)x < 1) || ((int)x > empty_map->size[1])) {
              rtDynamicBoundsError((int)x, 1, empty_map->size[1], &ib_emlrtBCI);
            }
            empty_map->data[((int)amad + empty_map->size[0] * ((int)x - 1)) - 1]
                .obstacle = 0U;
          }
        }
      }
      /* バイナリマップ */
      /*  最短経路を計算 */
      if (1 > diffs->size[1]) {
        rtDynamicBoundsError(1, 1, diffs->size[1], &jb_emlrtBCI);
      }
      if (diffs->size[1] < 1) {
        rtDynamicBoundsError(diffs->size[1], 1, diffs->size[1], &kb_emlrtBCI);
      }
      ref_position[0] = diffs->data[0] + 1.0;
      ref_position[1] = diffs->data[1] + 1.0;
      trimming_course[0] = diffs->data[2 * (diffs->size[1] - 1)] + 1.0;
      trimming_course[1] = diffs->data[2 * (diffs->size[1] - 1) + 1] + 1.0;
      computeAstar(empty_map, ref_position, trimming_course, size_x, size_y,
                   store_course);
      /*  切り取られたコースを連結する */
      for (i = 0; i < 9999; i++) {
        b_shortcut_course[i] = (shortcut_course[i << 1] < 0.0);
      }
      b_eml_find(b_shortcut_course, (int *)&index_data, index_size);
      i = store_course->size[1] - 1;
      if (0 <= store_course->size[1] - 1) {
        b_loop_ub = index_size[1];
        i2 = 2;
      }
      if (0 <= i) {
        c_loop_ub = index_size[1];
      }
      for (loop_ub = 0; loop_ub <= i; loop_ub++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          nx = (short)((double)index_data + (double)loop_ub);
          if ((nx < 1) || (nx > 9999)) {
            rtDynamicBoundsError(nx, 1, 9999, &lb_emlrtBCI);
          }
          tmp_data = (short)(nx - 1);
        }
        iv1[0] = 2;
        iv1[1] = index_size[1];
        rtSubAssignSizeCheck(&iv1[0], 2, &i2, 1, &d_emlrtECI);
        if (loop_ub + 1 > store_course->size[1]) {
          rtDynamicBoundsError(loop_ub + 1, 1, store_course->size[1],
                               &mb_emlrtBCI);
        }
        ref_position[0] = store_course->data[2 * loop_ub];
        ref_position[1] = store_course->data[2 * loop_ub + 1];
        for (i1 = 0; i1 < c_loop_ub; i1++) {
          nx = tmp_data << 1;
          shortcut_course[nx] = ref_position[0];
          shortcut_course[nx + 1] = ref_position[1];
        }
      }
      /*  ゴールに着いたら処理を終了 */
      if (diffs->size[1] < 1) {
        rtDynamicBoundsError(diffs->size[1], 1, diffs->size[1], &nb_emlrtBCI);
      }
    } while (!(diffs->data[2 * (diffs->size[1] - 1)] == goal_x - 1.0));
    if (diffs->size[1] < 1) {
      rtDynamicBoundsError(diffs->size[1], 1, diffs->size[1], &ob_emlrtBCI);
    }
  } while (!(diffs->data[2 * (diffs->size[1] - 1) + 1] == goal_y - 1.0));
  emxFree_real_T(&b_remaining_course);
  emxFree_boolean_T(&b_margin_y);
  emxFree_real_T(&b_src_course);
  emxFree_struct_T(&empty_map);
  emxFree_int32_T(&ii);
  emxFree_real_T(&diffs);
  emxFree_real_T(&margin_y);
  emxFree_real_T(&margin_x);
  emxFree_int8_T(&flag_table);
  emxFree_real_T(&remaining_course);
  for (i = 0; i < 9999; i++) {
    b_shortcut_course[i] = (shortcut_course[i << 1] < 0.0);
  }
  b_eml_find(b_shortcut_course, (int *)&index_data, index_size);
  if (1 > index_size[1]) {
    rtDynamicBoundsError(1, 1, index_size[1], &pb_emlrtBCI);
  }
  if (10000 - index_data == 0) {
    n = 0;
  } else if (2 > 10000 - index_data) {
    n = 2;
  } else {
    n = 10000 - index_data;
  }
  if ((index_data - 1 < 1) || (index_data - 1 > 9999)) {
    rtDynamicBoundsError(index_data - 1, 1, 9999, &qb_emlrtBCI);
  }
  b_repmat(*(double(*)[2]) & shortcut_course[(index_data - 2) << 1], n,
           store_course);
  iv1[0] = 2;
  iv1[1] = 10000 - index_data;
  rtSubAssignSizeCheck(&iv1[0], 2, &store_course->size[0], 2, &e_emlrtECI);
  loop_ub = store_course->size[1];
  for (i = 0; i < loop_ub; i++) {
    nx = ((index_data + i) - 1) << 1;
    shortcut_course[nx] = store_course->data[2 * i];
    shortcut_course[nx + 1] = store_course->data[2 * i + 1];
  }
  emxFree_real_T(&store_course);
  /* 使ってない要素を最後のコース情報で埋める */
  for (i = 0; i < 19998; i++) {
    shortcut_course[i]--;
  }
  /* 行列のインデックスにするために1を足していたのを引く */
  x = fabs(min_x);
  amad = fabs(min_y);
  b_linspace(x, x, c_shortcut_course);
  for (i = 0; i < 9999; i++) {
    i1 = i << 1;
    d = shortcut_course[i1] - c_shortcut_course[i];
    c_shortcut_course[i] = d;
    shortcut_course[i1] = d;
  }
  b_linspace(amad, amad, c_shortcut_course);
  /*  正にマージンしていた分を取り除く */
  for (i = 0; i < 9999; i++) {
    i1 = i << 1;
    d = shortcut_course[i1 + 1] - c_shortcut_course[i];
    c_shortcut_course[i] = d;
    shortcut_course[i1 + 1] = d;
    d_shortcut_course[i] = shortcut_course[i1];
  }
  movmean(d_shortcut_course, c_shortcut_course);
  for (i = 0; i < 9999; i++) {
    nx = i << 1;
    d_shortcut_course[i] = shortcut_course[nx + 1];
    shortcut_course[nx] = c_shortcut_course[i];
  }
  movmean(d_shortcut_course, c_shortcut_course);
  for (i = 0; i < 9999; i++) {
    shortcut_course[(i << 1) + 1] = c_shortcut_course[i];
  }
  /*  平滑化のため移動平均を計算 */
}

/*
 * File trailer for generateShortcutPath.c
 *
 * [EOF]
 */
