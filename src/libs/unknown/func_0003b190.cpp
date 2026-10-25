/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 15 of hknpDecoratorShape's vtable (address point
 * 0x16958e0) forwards to the same slot of the wrapped shape at +0x28. */
int hknpDecoratorShape::FUN_0003b190(int faceIndex, Vec4 *planeOut,
                                     Vec4 *verticesOut) const /* derived name */
{
    return coreShape->unknownVirtual15(faceIndex, planeOut, verticesOut);
}
