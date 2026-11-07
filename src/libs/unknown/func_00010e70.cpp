/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

hkBool32 hkTransform::FUN_00010e70(const hkTransform &other, const Vec4 &epsilon) const
{
    const Vec4 d0 = hkMath::quadFabs(_mm_sub_ps(other.rotation.col0, rotation.col0));
    const Vec4 d1 = hkMath::quadFabs(_mm_sub_ps(other.rotation.col1, rotation.col1));
    const Vec4 d2 = hkMath::quadFabs(_mm_sub_ps(other.rotation.col2, rotation.col2));
    const Vec4 d3 = hkMath::quadFabs(_mm_sub_ps(other.translation, translation));
    const Vec4 maxDiff = _mm_max_ps(_mm_max_ps(d0, d1), _mm_max_ps(d2, d3));
    const __m128i all = _mm_set1_epi32(-1);
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(all), 7);
    return _mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_cmple_ps(maxDiff, epsilon), xyz)),
                           _mm_castps_si128(xyz));
}
