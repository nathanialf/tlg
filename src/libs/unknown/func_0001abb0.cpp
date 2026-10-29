/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* One lane of a vector in every lane (derived name). */
template <int I> static inline Vec4 splat(const Vec4 &v) /* derived name */
{
    return _mm_shuffle_ps(v, v, _MM_SHUFFLE(I, I, I, I));
}

void hkMatrix3::FUN_0001abb0(const hkMatrix3 &a, const hkMatrix3 &b)
{
    const Vec4 b0 = b.col0;
    const Vec4 b1 = b.col1;
    const Vec4 b2 = b.col2;
    const Vec4 a0 = a.col0;
    const Vec4 a1 = a.col1;
    const Vec4 a2 = a.col2;
    col0 = _mm_add_ps(_mm_mul_ps(splat<0>(b2), a2),
                      _mm_add_ps(_mm_mul_ps(splat<0>(b0), a0), _mm_mul_ps(splat<0>(b1), a1)));
    col1 = _mm_add_ps(_mm_mul_ps(splat<1>(b2), a2),
                      _mm_add_ps(_mm_mul_ps(splat<1>(b0), a0), _mm_mul_ps(splat<1>(b1), a1)));
    col2 = _mm_add_ps(_mm_mul_ps(splat<2>(b2), a2),
                      _mm_add_ps(_mm_mul_ps(splat<2>(b0), a0), _mm_mul_ps(splat<2>(b1), a1)));
}
