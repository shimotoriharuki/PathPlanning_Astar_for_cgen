#ifndef COMPUTEASTAR_EMXAPI_H
#define COMPUTEASTAR_EMXAPI_H

#include "computeAstar_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern emxArray_struct0_T *emxCreateND_struct0_T(int numDimensions,
                                                 const int *size);

extern emxArray_struct0_T *emxCreateWrapperND_struct0_T(struct0_T *data,
                                                        int numDimensions,
                                                        const int *size);

extern emxArray_struct0_T *emxCreateWrapper_struct0_T(struct0_T *data, int rows,
                                                      int cols);

extern emxArray_struct0_T *emxCreate_struct0_T(int rows, int cols);

extern void emxDestroyArray_struct0_T(emxArray_struct0_T *emxArray);

extern void emxInitArray_struct0_T(emxArray_struct0_T **pEmxArray,
                                   int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
