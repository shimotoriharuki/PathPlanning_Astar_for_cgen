#ifndef COMPUTEASTAR_EMXUTIL_H
#define COMPUTEASTAR_EMXUTIL_H

#include "computeAstar_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void emxFree_struct0_T(emxArray_struct0_T **pEmxArray);

extern void emxInit_struct0_T(emxArray_struct0_T **pEmxArray,
                              int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
