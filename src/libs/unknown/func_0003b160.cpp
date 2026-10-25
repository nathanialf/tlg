/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 12 of hknpDecoratorShape's vtable (address point
 * 0x16958e0) forwards to the same slot of the wrapped shape at +0x28. */
void hknpDecoratorShape::FUN_0003b160(const u8 *ids, int numIds,
                                      Vec4 *verticesOut) const /* derived name */
{
    coreShape->unknownVirtual12(ids, numIds, verticesOut);
}
