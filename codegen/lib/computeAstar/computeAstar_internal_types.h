#ifndef COMPUTEASTAR_INTERNAL_TYPES_H
#define COMPUTEASTAR_INTERNAL_TYPES_H

#include "computeAstar_types.h"
#include "rtwtypes.h"

#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  double x;
  double y;
  unsigned short score;
  unsigned short g_cost;
  unsigned short h_cost;
} struct_T;
#endif

#endif
