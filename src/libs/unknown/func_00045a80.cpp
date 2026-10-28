/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 21 of hknpConvexShape's vtable (address point
 * 0x1697da0), kept by hknpSphereShape, hknpCapsuleShape, hknpTriangleShape
 * and hknpConvexPolytopeShape: only when the third argument is -1 is the
 * value the fourth points to copied to the first, and 1 returned; else 0. */
int hknpConvexShape::FUN_00045a80(u32 *argument1, int argument2, int argument3,
                                  const ShapeKeyQuery000380b0 &argument4) const
{
    if (argument3 == -1) {
        *argument1 = argument4.key;
        return 1;
    }
    return 0;
}
