#ifndef OPENAROUNDNODEDP_H
#define OPENAROUNDNODEDP_H

#include "computeAstar_internal_types.h"
#include "computeAstar_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

void openAroundNodeDP(emxArray_struct0_T *map, struct_T open_list[999],
                      double ref_x, double ref_y, double size_x, double size_y,
                      const double goal[2]);

#ifdef __cplusplus
}
#endif

#endif
