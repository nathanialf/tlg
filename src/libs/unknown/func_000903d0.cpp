/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* v with its sign flipped where s is negative, as hkVector4::setFlipSign
 * takes the sign bit: shifted down and back up. derived name. */
static inline Vec4 flipSign(const Vec4 &v, const Vec4 &s) /* derived name */
{
    const __m128i sign = _mm_slli_epi32(_mm_srli_epi32(_mm_castps_si128(s), 31), 31);
    return _mm_xor_ps(v, _mm_castsi128_ps(sign));
}

bool hkQTransform::FUN_000903d0(const hkQTransform &other, float epsilon) const
{
    const Vec4 eps = simdFromFloat(epsilon);
    const Vec4 dot = _mm_dp_ps(rotation.vec, other.rotation.vec, 0xff);
    const Vec4 rotationDiff =
        hkMath::quadFabs(_mm_sub_ps(rotation.vec, flipSign(other.rotation.vec, dot)));
    const __m128i all = _mm_set1_epi32(-1);
    if (!_mm_testc_si128(_mm_castps_si128(_mm_cmple_ps(rotationDiff, eps)), all)) {
        return false;
    }
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(all), 7);
    const Vec4 translationDiff = hkMath::quadFabs(_mm_sub_ps(translation, other.translation));
    return _mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_cmple_ps(translationDiff, eps), xyz)),
                           _mm_castps_si128(xyz));
}
