/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* The cross product of a and b in the first three lanes (derived name). */
static inline Vec4 cross3(const Vec4 &a, const Vec4 &b) /* derived name */
{
    const Vec4 t = _mm_sub_ps(_mm_mul_ps(a, _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1))),
                              _mm_mul_ps(_mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1)), b));
    return _mm_shuffle_ps(t, t, _MM_SHUFFLE(3, 0, 2, 1));
}

/* derived name: v rotated by the inverse of the quaternion q, as twice the sum of v by
 * w * w - 1/2, the imaginary part by its dot product with v and the cross
 * product of v and the imaginary part by w (row 18 of the constant table
 * is one half in each lane). */
void FUN_000110c0(Vec4 &out, const hkQuaternion &q, const Vec4 &v)
{
    const Vec4 real = _mm_shuffle_ps(q.vec, q.vec, _MM_SHUFFLE(3, 3, 3, 3));
    const Vec4 q2minus1 = _mm_sub_ps(_mm_mul_ps(real, real), D_14b2060[18]);
    Vec4 result = _mm_mul_ps(v, q2minus1);
    const Vec4 imagDotDir = _mm_dp_ps(q.vec, v, 0x7f);
    result = _mm_add_ps(result, _mm_mul_ps(q.vec, imagDotDir));
    const Vec4 imagCrossDir = cross3(v, q.vec);
    result = _mm_add_ps(result, _mm_mul_ps(imagCrossDir, real));
    out = _mm_add_ps(result, result);
}
