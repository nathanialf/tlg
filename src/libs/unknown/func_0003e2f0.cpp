/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_hk_reflect.h"

void hknpDummyShape::unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const
{
    FUN_00094060(transform, aabb, aabbOut);
    const Vec4 radius = _mm_set1_ps(convexRadius);
    aabbOut.max = _mm_add_ps(aabbOut.max, radius);
    aabbOut.min = _mm_sub_ps(aabbOut.min, radius);
}
