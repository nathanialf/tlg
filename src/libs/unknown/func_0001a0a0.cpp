/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* The arc sine in every lane, Cephes' single precision approximation
 * (its five coefficients): above one half from the square root of half of
 * one minus the magnitude, below 1e-4 the magnitude itself, the sign put
 * back last. derived name. */
static inline Vec4 quadAsin(const Vec4 &x) /* derived name */
{
    const Vec4 sign = _mm_and_ps(D_14b41d0, x);
    const Vec4 a = _mm_min_ps(D_14b4370, _mm_andnot_ps(D_14b41d0, x));
    const Vec4 big = _mm_cmplt_ps(D_14b4360, a);
    const Vec4 zBig = _mm_mul_ps(_mm_sub_ps(D_14b4370, a), D_14b4360);
    const Vec4 z = _mm_blendv_ps(_mm_mul_ps(a, a), zBig, big);
    Vec4 p =
        _mm_add_ps(_mm_mul_ps(z, _mm_set1_ps(4.2163199048E-2f)), _mm_set1_ps(2.4181311049E-2f));
    p = _mm_add_ps(_mm_mul_ps(z, p), _mm_set1_ps(4.5470025998E-2f));
    p = _mm_add_ps(_mm_mul_ps(z, p), _mm_set1_ps(7.4953002686E-2f));
    p = _mm_add_ps(_mm_mul_ps(z, p), _mm_set1_ps(1.6666752422E-1f));
    p = _mm_mul_ps(z, p);
    const Vec4 s = _mm_blendv_ps(a, _mm_sqrt_ps(zBig), big);
    const Vec4 r = _mm_add_ps(s, _mm_mul_ps(s, p));
    const Vec4 rBig = _mm_sub_ps(D_14b4310, _mm_add_ps(r, r));
    const Vec4 result =
        _mm_blendv_ps(_mm_blendv_ps(r, rBig, big), a, _mm_cmplt_ps(a, _mm_set1_ps(1e-4f)));
    return _mm_xor_ps(result, sign);
}

float hkQuaternion::FUN_0001a0a0() const /* derived name */
{
    const __m128i w = _mm_castps_si128(_mm_shuffle_ps(vec, vec, _MM_SHUFFLE(3, 3, 3, 3)));
    const Vec4 absW = _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(w, w), 1));
    const Vec4 acos = _mm_sub_ps(D_14b4310, quadAsin(absW));
    return _mm_cvtss_f32(_mm_add_ps(acos, acos));
}
