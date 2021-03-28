#ifndef COMPUTEASTAR_H
#define COMPUTEASTAR_H

#include "computeAstar_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void computeAstar(emxArray_struct0_T *map, const double start[2],
                         const double goal[2], double size_x, double size_y,
                         double shortcut_course[19998]);

#ifdef __cplusplus
}
#endif

#endif
