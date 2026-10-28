/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the shape's local box, transformed into the box it
 * reports. */
void hknpExternMeshShape::FUN_00166370(const Mat4 &transform, hkAabb &aabbOut) const
{
    hkAabb localAabb;
    FUN_000ed580(localAabb);
    FUN_00094060(transform, localAabb, aabbOut);
}
