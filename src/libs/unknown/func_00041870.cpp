/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hknpCompoundShape's vtable (address point
 * 0x1697910), kept by the dynamic and static compound shapes: its bounds
 * are its AABB at +0x80 under the transform. */
void hknpCompoundShape::unknownVirtual7(const Mat4 &transform,
                                        hkAabb &aabbOut) const /* derived name */
{
    FUN_00094060(transform, aabb, aabbOut);
}
