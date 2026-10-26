/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 21 of hknpDecoratorShape's vtable (address point
 * 0x16958e0) forwards to the same slot of the wrapped shape at +0x28. */
int hknpDecoratorShape::FUN_0003b200(void *argument1, int argument2, int argument3,
                                     const void *argument4) const /* derived name */
{
    return coreShape->unknownVirtual21(argument1, argument2, argument3, argument4);
}
