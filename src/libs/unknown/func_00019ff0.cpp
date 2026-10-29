/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* The magnitude of each lane, as FUN_0001add0's file spells it (cookbook
 * 70). derived name. */
static inline Vec4 absLanes(const Vec4 &v) /* derived name */
{
    const __m128i bits = _mm_castps_si128(v);
    return _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
}

/* The rotation about an axis by an angle, its sine and cosine taken by the
 * parabola approximation: the half angle and, a quarter turn on, the
 * cosine's, wrapped below pi, then 4/pi x - 4/pi^2 x|x| refined by
 * 0.225 (y|y| - y). */
// NONMATCHING: the two products of a value and its magnitude come out
// magnitude first (`vmulps xmm1, xmm1, xmm0`), the base's value first:
// Reassociate ranks the magnitude by its psrli call, an unmovable
// instruction, where the base's ranks are those of an IR lshr (LLVM 3.5's
// InstCombine folds a constant-count psrli into lshr; 3.3 and 3.4.2 keep the
// call). A region question (docs/NOTES.md, Round 51); 26 of 28 instructions.
void hkQuaternion::FUN_00019ff0(const Vec4 &axis, const Vec4 &angle)
{
    Vec4 x = _mm_add_ps(_mm_mul_ps(D_14b2060[18], angle),
                        _mm_setr_ps(0.0f, HK_REAL_PI * 0.5f, 0.0f, HK_REAL_PI * 0.5f));
    x = _mm_sub_ps(x, _mm_and_ps(_mm_cmpnlt_ps(x, D_14b4300), D_14b42f0));
    Vec4 sinCos = _mm_add_ps(_mm_mul_ps(x, D_14b4320),
                             _mm_mul_ps(_mm_mul_ps(x, absLanes(x)), _mm_set1_ps(-0.405284735f)));
    sinCos = _mm_add_ps(sinCos, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(sinCos, absLanes(sinCos)), sinCos),
                                           _mm_set1_ps(0.225f)));
    const Vec4 s = _mm_shuffle_ps(sinCos, sinCos, _MM_SHUFFLE(0, 0, 0, 0));
    const Vec4 c = _mm_shuffle_ps(sinCos, sinCos, _MM_SHUFFLE(1, 1, 1, 1));
    vec = _mm_blend_ps(_mm_mul_ps(s, axis), c, 8);
}
