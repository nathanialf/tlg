/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

bool hkTransform::FUN_00010de0(const hkTransform &other, float epsilon) const
{
    const Vec4 tolerance = _mm_set1_ps(epsilon);
    if (!FUN_0001add0(rotation, other.rotation, tolerance)) {
        return false;
    }
    const Vec4 d = hkMath::quadFabs(_mm_sub_ps(translation, other.translation));
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    return _mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_cmple_ps(d, tolerance), xyz)),
                           _mm_castps_si128(xyz));
}
