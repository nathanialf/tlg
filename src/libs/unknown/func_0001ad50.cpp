/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* The magnitude of each lane (hkMath::fabs's form, cookbook 70). derived
 * name. */
static inline Vec4 absLanes(const Vec4 &v) /* derived name */
{
    const __m128i bits = _mm_castps_si128(v);
    return _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
}

/* Whether a and b differ by at most epsilon in each of x, y and z.
 * derived name. */
static inline bool allEqual3(const Vec4 &a, const Vec4 &b, const Vec4 &epsilon) /* derived name */
{
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    return _mm_testc_si128(
        _mm_castps_si128(_mm_and_ps(_mm_cmple_ps(absLanes(_mm_sub_ps(a, b)), epsilon), xyz)),
        _mm_castps_si128(xyz));
}

bool hkMatrix3::FUN_0001ad50(const hkMatrix3 &m, float epsilon) const
{
    const Vec4 e = _mm_set1_ps(epsilon);
    return allEqual3(col0, m.col0, e) && allEqual3(col1, m.col1, e) && allEqual3(col2, m.col2, e);
}
