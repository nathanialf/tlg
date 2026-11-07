/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* The lanes rotated by one, two and three places (derived names). */
static inline Vec4 rotate1(const Vec4 &v)
{
    return _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 3, 2, 1));
}

static inline Vec4 rotate2(const Vec4 &v)
{
    return _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 0, 3, 2));
}

static inline Vec4 rotate3(const Vec4 &v)
{
    return _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 1, 0, 3));
}

/* The two-by-two determinants of two rows, three vectors of them. derived
 * name. */
static inline void minors(const Vec4 &x, const Vec4 &y, Vec4 &m0, Vec4 &m1, Vec4 &m2)
{
    const Vec4 x1 = rotate1(x);
    const Vec4 p2 = _mm_mul_ps(rotate2(y), x1);
    const Vec4 p0 = _mm_mul_ps(y, x1);
    const Vec4 p3 = _mm_mul_ps(rotate3(y), x1);
    m0 = _mm_sub_ps(rotate2(p3), p3);
    m1 = _mm_sub_ps(p2, rotate1(p0));
    m2 = _mm_sub_ps(rotate1(p2), rotate2(p0));
}

/* A row's cofactors from the other rows' minors, signs not yet applied.
 * derived name. */
static inline Vec4 cofactors(const Vec4 &v, const Vec4 &m0, const Vec4 &m1, const Vec4 &m2)
{
    const Vec4 v1 = rotate1(v);
    const Vec4 v2 = rotate1(v1);
    const Vec4 v3 = rotate1(v2);
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(v1, m2), _mm_mul_ps(v2, m0)), _mm_mul_ps(v3, m1));
}

/* The sign bits of the lanes a mask selects. derived name. */
static inline Vec4 signsOf(const Vec4 &mask)
{
    return _mm_castsi128_ps(_mm_slli_epi32(_mm_srli_epi32(_mm_castps_si128(mask), 31), 31));
}

// NONMATCHING: 102 of 103 instructions in the base's operations, products and
// sums (474 bytes against 478): the pre-RA list-ilp scheduler (ScheduleDAGRRList,
// ilp_ls_rr_sort's critical-path rule: nodes whose depths differ by more than
// MaxReorderWindow are taken deepest first, bottom-up) leaves the XZ sign
// mask's blend, whose operands are the constants zero and all-ones (depth 1),
// to the top of the entry block, where the base computes it after the
// minors; the minors' spills and every register below follow from that
// (docs/NOTES.md, Round 76A). The three placements of the masks in the
// source compile the same (InstCombine sinks the YW mask into the inverting
// block).

/* derived name: the 4x4 matrix m inverted into out by cofactors, a failure
 * (out untouched) when the determinant's magnitude is below the tolerance's
 * first lane. */
hkResult FUN_00017b20(const Mat4 &m, Mat4 &out, const Vec4 &tolerance)
{
    const Vec4 d = m.r[3];
    const Vec4 c = m.r[2];
    const Vec4 b = m.r[1];
    const Vec4 a = m.r[0];

    Vec4 cd0, cd1, cd2;
    minors(c, d, cd0, cd1, cd2);
    const Vec4 cof0 =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(rotate1(b), cd2), _mm_mul_ps(rotate2(b), cd0)),
                   _mm_mul_ps(rotate3(b), cd1));

    const Vec4 allSet = _mm_castsi128_ps(_mm_set1_epi32(-1));
    const Vec4 signsXZ = signsOf(_mm_blend_ps(_mm_setzero_ps(), allSet, 5));
    const Vec4 signsYW = signsOf(_mm_blend_ps(_mm_setzero_ps(), allSet, 10));
    Vec4 det = _mm_xor_ps(_mm_mul_ps(a, cof0), signsXZ);
    det = _mm_hadd_ps(det, det);
    det = _mm_hadd_ps(det, det);
    const __m128i detBits = _mm_castps_si128(det);
    const Vec4 magnitude = _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(detBits, detBits), 1));
    if (_mm_cvtss_f32(magnitude) < _mm_cvtss_f32(tolerance)) {
        return HK_FAILURE;
    }

    Vec4 ab0, ab1, ab2;
    minors(a, b, ab0, ab1, ab2);
    const Vec4 invDet = _mm_div_ps(D_14b2060[3], det);
    Vec4 col0 = _mm_mul_ps(_mm_xor_ps(cof0, signsXZ), invDet);
    Vec4 col1 = _mm_mul_ps(_mm_xor_ps(cofactors(a, cd0, cd1, cd2), signsYW), invDet);
    Vec4 col2 = _mm_mul_ps(_mm_xor_ps(cofactors(d, ab0, ab1, ab2), signsXZ), invDet);
    Vec4 col3 = _mm_mul_ps(_mm_xor_ps(cofactors(c, ab0, ab1, ab2), signsYW), invDet);
    _MM_TRANSPOSE4_PS(col0, col1, col2, col3);
    out.r[0] = col0;
    out.r[1] = col1;
    out.r[2] = col2;
    out.r[3] = col3;
    return HK_SUCCESS;
}
