#ifndef COMPUTEASTAR_TYPES_H
#define COMPUTEASTAR_TYPES_H

#include "rtwtypes.h"

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  unsigned short obstacle;
  unsigned short status;
  unsigned short g_cost;
  unsigned short h_cost;
  unsigned short score;
  unsigned short parent[2];
} struct0_T;
#endif

#ifndef typedef_emxArray_struct0_T
#define typedef_emxArray_struct0_T
typedef struct {
  struct0_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
} emxArray_struct0_T;
#endif

#endif
