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

/* The squared length of x, y and z, in every lane. derived name. */
static inline Vec4 lengthSquared3(const Vec4 &v) /* derived name */
{
    return _mm_dp_ps(v, v, 0x7f);
}

/* a cross b, from the y, z, x rotations of both (hkVector4's setCross).
 * derived name. */
static inline Vec4 cross(const Vec4 &a, const Vec4 &b) /* derived name */
{
    const Vec4 aYzx = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1));
    const Vec4 bYzx = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1));
    const Vec4 c = _mm_sub_ps(_mm_mul_ps(a, bYzx), _mm_mul_ps(aYzx, b));
    return _mm_shuffle_ps(c, c, _MM_SHUFFLE(3, 0, 2, 1));
}

bool hkMatrix3::FUN_0000bde0(float epsilon) const
{
    const Vec4 one = D_14b2060[3];
    const Vec4 e = _mm_set1_ps(epsilon);

    if (_mm_ucomigt_ss(_mm_sub_ps(lengthSquared3(col0), one), e)) {
        return false;
    }
    if (_mm_ucomigt_ss(_mm_sub_ps(lengthSquared3(col1), one), e)) {
        return false;
    }
    if (_mm_ucomigt_ss(_mm_sub_ps(lengthSquared3(col2), one), e)) {
        return false;
    }

    const Vec4 difference = absLanes(_mm_sub_ps(cross(col0, col1), col2));
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    return _mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_cmple_ps(difference, e), xyz)),
                           _mm_castps_si128(xyz));
}
