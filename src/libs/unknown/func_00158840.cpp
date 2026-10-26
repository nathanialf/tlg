/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hknpCompressedMeshShape's vtable (address point
 * 0x16a49a0): the AABB of the shape under a transform, the mesh tree's
 * domain transformed. */
void hknpCompressedMeshShape::FUN_00158840(const Mat4 &transform,
                                           hkAabb &aabbOut) const /* derived name */
{
    FUN_00094060(transform, *FUN_0010bf40(), aabbOut);
}
