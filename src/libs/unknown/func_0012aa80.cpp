/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_0012aa80(const hknpHeightFieldShape *self, const Mat4 &transform,
                  hkAabb &aabbOut) /* derived name */
{
    const Vec4 radius = D_14b2060[2];
    FUN_00093fa0(transform, self->aabb, radius, aabbOut);
}
