/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpCapsuleShape::FUN_00073110(const void *argument1, void *argument2) const /* derived name */
{
    if (FUN_001683d0(argument1, a, b, convexRadius, argument2) == HK_FAILURE) {
        FUN_0006fc70(argument1, argument2);
    }
}
