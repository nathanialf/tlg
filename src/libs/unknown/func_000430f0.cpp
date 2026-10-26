/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 29 of hknpConvexShape's vtable (address point
 * 0x1697da0; also the triangle, convex polytope and scaled convex shapes'):
 * the shared vertex pass over every vertex. */
void hknpConvexShape::FUN_000430f0(const hknpShapeSlot29Input &input, void *output) const
{
    FUN_00169330(this, input.mode, input.scale, input.offset, output, 0xffff);
}
