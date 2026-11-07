/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: whether a and b differ by at most epsilon in every element
 * of their three columns' x, y and z. */
bool FUN_0001add0(const hkMatrix3 &a, const hkMatrix3 &b, const Vec4 &epsilon)
{
    const Vec4 d0 = hkMath::quadFabs(_mm_sub_ps(b.col0, a.col0));
    const Vec4 d1 = hkMath::quadFabs(_mm_sub_ps(b.col1, a.col1));
    const Vec4 d2 = hkMath::quadFabs(_mm_sub_ps(b.col2, a.col2));
    const Vec4 d = _mm_max_ps(_mm_max_ps(d0, d1), d2);
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    return _mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_cmple_ps(d, epsilon), xyz)),
                           _mm_castps_si128(xyz));
}
