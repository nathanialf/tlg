/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 27 of hknpDecoratorShape's vtable (address point
 * 0x16958e0) forwards to the same slot of the wrapped shape at +0x28. */
int hknpDecoratorShape::FUN_0003b210(const LodContext000426b0 &context,
                                     const LodQuery000426b0 &query,
                                     int currentLod) const /* derived name */
{
    return coreShape->unknownVirtual27(context, query, currentLod);
}
