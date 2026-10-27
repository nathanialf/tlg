/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpSphereShape::FUN_0003c670(const void *argument1, void *argument2) const /* derived name */
{
    if (FUN_00168340(argument1, *vertices.begin(), convexRadius, argument2) == HK_FAILURE) {
        FUN_0006fc70(argument1, argument2);
    }
}
