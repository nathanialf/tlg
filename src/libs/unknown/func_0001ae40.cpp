/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* Every lane's magnitude, the bits doubled and shifted back (as hkMath::fabs
 * does in one lane). derived name. */
static inline Vec4 absolute(const Vec4 &v) /* derived name */
{
    const __m128i bits = _mm_castps_si128(v);
    return _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
}

/* The inverse from the columns' cross products over the determinant, which
 * must exceed the product of the columns' summed magnitudes scaled by the
 * epsilon: the rows the cross products, transposed into columns and scaled
 * by the determinant's refined reciprocal. */
// NONMATCHING: the operations are the base's, the schedule is not: the base
// loads every column in the integer domain (vmovdqa), computes the first
// cross product before the magnitudes and the determinant's dot product
// last, before its compare; here the determinant is taken right after the
// cross product and two loads are vmovaps (docs/NOTES.md, Round 63A).
hkResult hkMatrix3::FUN_0001ae40(const hkMatrix3 &m)
{
    const Vec4 c0 = m.col0;
    const Vec4 c1 = m.col1;
    const Vec4 c2 = m.col2;
    const Vec4 r0 = cross3(c1, c2);
    const Vec4 one = D_14b2060[3];
    const Vec4 size2 = _mm_dp_ps(absolute(c2), one, 0x7f);
    const Vec4 size1 = _mm_dp_ps(absolute(c1), one, 0x7f);
    const Vec4 size0 = _mm_dp_ps(absolute(c0), one, 0x7f);
    const Vec4 tolerance = _mm_mul_ps(_mm_mul_ps(size0, D_14b2060[35]), _mm_mul_ps(size1, size2));
    const Vec4 determinant = _mm_dp_ps(c0, r0, 0x7f);
    if (_mm_ucomigt_ss(absolute(determinant), tolerance)) {
        const Vec4 r1 = cross3(c2, c0);
        const Vec4 r2 = cross3(c0, c1);
        const Vec4 r = _mm_rcp_ps(determinant);
        const Vec4 inverse = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(determinant, r)));
        const Vec4 lo = _mm_unpacklo_ps(r0, r1);
        const Vec4 hi = _mm_unpackhi_ps(r0, r1);
        col0 = _mm_mul_ps(_mm_movelh_ps(lo, r2), inverse);
        col1 =
            _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(lo, lo), r2, _MM_SHUFFLE(3, 1, 1, 0)), inverse);
        col2 = _mm_mul_ps(_mm_shuffle_ps(hi, r2, _MM_SHUFFLE(3, 2, 1, 0)), inverse);
        return HK_SUCCESS;
    }
    setZero();
    return HK_FAILURE;
}
