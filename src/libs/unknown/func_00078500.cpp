/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Both arrays' places are read before the first store, and the plane is
 * computed from the points before the vertices are written. */
void hknpTriangleShape::FUN_00078500(const Vec4 &a, const Vec4 &b, const Vec4 &c)
{
    Vec4 *p = planes.beginBytes();
    Vec4 *v = vertices.beginBytes();
    const Vec4 normal = cross3(_mm_sub_ps(b, a), _mm_sub_ps(c, a));
    const Vec4 lengthSquared = _mm_dp_ps(normal, normal, 0x7F);
    const Vec4 e = _mm_rsqrt_ps(lengthSquared);
    const Vec4 invLength =
        _mm_mul_ps(_mm_mul_ps(e, D_14b4360),
                   _mm_sub_ps(D_14b4390, _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e))));
    const Vec4 distance = _mm_sub_ps(_mm_setzero_ps(), _mm_dp_ps(normal, a, 0x7F));
    const Vec4 plane =
        _mm_mul_ps(_mm_blend_ps(normal, distance, 8),
                   _mm_andnot_ps(_mm_cmple_ps(lengthSquared, _mm_setzero_ps()), invLength));

    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = a;
    for (int i = 0; i < 3; i++) {
        reinterpret_cast<int *>(&v[i])[3] = i | 0x3f000000;
    }
    reinterpret_cast<int *>(&v[3])[3] = 0x3f000000;

    p[0] = plane;
    p[1] = _mm_xor_ps(plane, _mm_set1_ps(-0.0f));
    p[2] = plane;
    p[3] = plane;
}
