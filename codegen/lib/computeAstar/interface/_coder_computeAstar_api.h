#ifndef _CODER_COMPUTEASTAR_API_H
#define _CODER_COMPUTEASTAR_API_H

#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  uint16_T obstacle;
  uint16_T status;
  uint16_T g_cost;
  uint16_T h_cost;
  uint16_T score;
  uint16_T parent[2];
} struct0_T;
#endif

#ifndef typedef_emxArray_struct0_T
#define typedef_emxArray_struct0_T
typedef struct {
  struct0_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct0_T;
#endif

extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

void computeAstar(emxArray_struct0_T *map, real_T start[2], real_T goal[2],
                  real_T size_x, real_T size_y, real_T shortcut_course[19998]);

void computeAstar_api(const mxArray *const prhs[5], const mxArray **plhs);

void computeAstar_atexit(void);

void computeAstar_initialize(void);

void computeAstar_terminate(void);

void computeAstar_xil_shutdown(void);

void computeAstar_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
