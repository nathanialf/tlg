/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpTriangleShape::FUN_00078380(const void *argument1,
                                     void *argument2) const /* derived name */
{
    const int result = isQuad() ? FUN_00168590(argument1, getVertices(), convexRadius, argument2)
                                : FUN_001684a0(argument1, getVertices(), convexRadius, argument2);
    if (result == HK_FAILURE) {
        FUN_0006fc70(argument1, argument2);
    }
}
