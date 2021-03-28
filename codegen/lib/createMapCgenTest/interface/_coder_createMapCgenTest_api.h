/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_createMapCgenTest_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 26-Mar-2021 19:12:49
 */

#ifndef _CODER_CREATEMAPCGENTEST_API_H
#define _CODER_CREATEMAPCGENTEST_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  uint16_T obstacle;
  uint16_T status;
  uint8_T parent[2];
} struct0_T;
#endif /* typedef_struct0_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void createMapCgenTest(struct0_T ret[9]);

void createMapCgenTest_api(const mxArray **plhs);

void createMapCgenTest_atexit(void);

void createMapCgenTest_initialize(void);

void createMapCgenTest_terminate(void);

void createMapCgenTest_xil_shutdown(void);

void createMapCgenTest_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_createMapCgenTest_api.h
 *
 * [EOF]
 */
