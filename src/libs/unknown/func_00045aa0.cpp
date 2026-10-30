/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 22 of hknpConvexShape's vtable (address point
 * 0x1697da0): a convex shape answers with itself, bit 3 of the flags
 * cleared and the value 1. */
void hknpConvexShape::FUN_00045aa0(const u32 *keys, int numKeys,
                                   hknpShapeSlot22Output *output) const
{
    output->shape = this;
    output->flags &= ~8;
    output->value = 1;
}
