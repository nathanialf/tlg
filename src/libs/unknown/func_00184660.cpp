/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: an AABB is valid when min <= max in x, y and z and neither
 * corner holds a NaN there. */
bool hkAabb::FUN_00184660() const
{
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    const bool ordered = _mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_cmple_ps(min, max), xyz)),
                                         _mm_castps_si128(xyz));
    const int validMin = _mm_movemask_ps(_mm_cmpord_ps(min, min));
    const int validMax = _mm_movemask_ps(_mm_cmpord_ps(max, max));
    return ordered & ((validMin & validMax & 7) == 7);
}
