/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 16 of hknpDecoratorShape's vtable (address point
 * 0x16958e0, kept by hknpMaskedShape) forwards to the same slot of the
 * shape it wraps. */
int hknpDecoratorShape::FUN_0003b1a0(const void *argument1, const void *argument2, void *argument3,
                                     bool argument4, int argument5) const
{
    return coreShape->unknownVirtual16(argument1, argument2, argument3, argument4, argument5);
}
