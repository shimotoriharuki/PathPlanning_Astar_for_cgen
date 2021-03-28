//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CalcShorterCourse.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 26-Mar-2021 19:00:14
//

// Include Files
#include "CalcShorterCourse.h"
#include "createMapCgenTest_types.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
CalcShorterCourse::CalcShorterCourse()
{
}

//
// Arguments    : void
// Return Type  : void
//
CalcShorterCourse::~CalcShorterCourse()
{
  // (no terminate code required)
}

//
// Arguments    : struct0_T ret[9]
// Return Type  : void
//
void CalcShorterCourse::createMapCgenTest(struct0_T ret[9])
{
  for (int i{0}; i < 9; i++) {
    ret[i].obstacle = 0.0;
    ret[i].status = 1.0;
  }
}

//
// File trailer for CalcShorterCourse.cpp
//
// [EOF]
//
