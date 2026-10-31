/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpTriangleShape *hknpShapeSlot22Output::FUN_00040c10(int quadIndex,
                                                       hknpTriangleShape *shapeOut) const
{
    const Vec4 *quad = &quadVertices[quadIndex * 4];
    const u16 flags = quadFlags[quadIndex];
    const Vec4 a = quad[0];
    const Vec4 b = quad[1];
    const Vec4 c = quad[2];
    Vec4 *p = shapeOut->planes.beginBytes();
    Vec4 *v = shapeOut->vertices.beginBytes();
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = quad[3];
    for (int i = 0; i < 4; i++) {
        reinterpret_cast<int *>(&v[i])[3] = i | 0x3f000000;
    }
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
    p[0] = plane;
    p[1] = _mm_xor_ps(plane, _mm_set1_ps(-0.0f));
    p[2] = plane;
    p[3] = plane;
    shapeOut->flags = flags;
    shapeOut->convexRadius = convexRadius;
    shapeOut->userData = leafShape->userData;
    if (!(flags & 0x1000)) {
        shapeOut->vertices.beginBytes()[3] = shapeOut->vertices.beginBytes()[0];
    }
    return shapeOut;
}
