/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the build over the shape's own vertices first, the
 * shapes' default when it fails. */
void hknpConvexShape::FUN_00045a20(const void *argument1, void *argument2) const
{
    const int numVertices = FUN_001707d0(this);
    if (FUN_00168d90(argument1, vertices.begin(), numVertices, argument2, convexRadius) ==
        HK_FAILURE) {
        FUN_0006fc70(argument1, argument2);
    }
}
