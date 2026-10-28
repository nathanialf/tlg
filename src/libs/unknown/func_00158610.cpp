/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpCompressedMeshShape's finish constructor: the composite shape's
 * (inline), the bit fields left as loaded, and a finished shape sets up
 * what is not serialized. */
hknpCompressedMeshShape::hknpCompressedMeshShape(hkFinishLoadedObjectFlag flag)
    : hknpCompositeShape(flag), quadIsFlat(flag), triangleIsInterior(flag)
{
    if (flag.finishing) {
        FUN_0010be70();
    }
}
