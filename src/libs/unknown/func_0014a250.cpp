/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: whether a and b overlap in x, y and z (a's min at most b's
 * max and b's min at most a's max); where they do not, the range is pushed
 * out to b: its min raised to b's max and its max lowered to b's min, each
 * only in the lanes that miss. */
hkBool32 FUN_0014a250(const hkAabb &a, const hkAabb &b, hkAabb &range)
{
    const Vec4 belowMax = _mm_cmple_ps(a.min, b.max);
    const Vec4 aboveMin = _mm_cmple_ps(b.min, a.max);
    const Vec4 newMin = _mm_blendv_ps(_mm_max_ps(range.min, b.max), range.min, belowMax);
    const Vec4 newMax = _mm_blendv_ps(_mm_min_ps(range.max, b.min), range.max, aboveMin);
    range.min = newMin;
    range.max = newMax;
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    return _mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_and_ps(belowMax, aboveMin), xyz)),
                           _mm_castps_si128(xyz));
}
