/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

void FUN_00093f30(const Vec4 *points, int numPoints, hkAabb &aabbOut)
{
    aabbOut.setEmpty();
    if (numPoints <= 0) {
        return;
    }
    for (int i = 0; i < numPoints; i++) {
        aabbOut.includePoint(points[i]);
    }
    aabbOut.min = _mm_blend_ps(aabbOut.min, _mm_setzero_ps(), 8);
    aabbOut.max = _mm_blend_ps(aabbOut.max, _mm_setzero_ps(), 8);
}
