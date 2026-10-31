/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Every lane's magnitude: the sign bit shifted out and back as zero. */
static inline Vec4 absolute(const Vec4 &v)
{
    const __m128i bits = _mm_castps_si128(v);
    return _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
}

/* The core's vertices bounded in a local box (its minimum's merge phi
 * ahead of its maximum's, so Reassociate keeps the minimum on the left of
 * their sum, `vaddps xmm0, xmm1, xmm0`), the box scaled and moved, then
 * transformed as 0x94060 transforms one. */
void hknpScaledConvexShapeBase::FUN_0016a850(const Mat4 &transform, hkAabb &aabbOut) const
{
    hkAabb local;
    local.min = D_14b2060[33];
    local.max = _mm_xor_ps(local.min, _mm_set1_ps(-0.0f));
    const hknpConvexShape *convex = static_cast<const hknpConvexShape *>(coreShape);
    const int numVertices = convex->vertices.getSize();
    if (numVertices) {
        const Vec4 *v = reinterpret_cast<const Vec4 *>(
            reinterpret_cast<const char *>(&convex->vertices) + convex->vertices.offset);
        for (int i = 0; i < numVertices; i += 4) {
            local.min =
                _mm_min_ps(_mm_min_ps(_mm_min_ps(_mm_min_ps(local.min, v[0]), v[1]), v[2]), v[3]);
            local.max =
                _mm_max_ps(_mm_max_ps(_mm_max_ps(_mm_max_ps(local.max, v[0]), v[1]), v[2]), v[3]);
            v += 4;
        }
    }
    const Vec4 halfExtents =
        _mm_mul_ps(_mm_mul_ps(D_14b2060[18], _mm_sub_ps(local.max, local.min)), scale);
    const Vec4 center =
        _mm_add_ps(_mm_mul_ps(_mm_mul_ps(D_14b2060[18], _mm_add_ps(local.min, local.max)), scale),
                   translation);

    const Vec4 col0 = transform.r[0];
    const Vec4 col1 = transform.r[1];
    const Vec4 col2 = transform.r[2];
    const Vec4 rotated = _mm_add_ps(
        _mm_mul_ps(broadcast<2>(center), col2),
        _mm_add_ps(_mm_mul_ps(col0, broadcast<0>(center)), _mm_mul_ps(col1, broadcast<1>(center))));
    const Vec4 worldCenter = _mm_add_ps(rotated, transform.r[3]);
    const Vec4 extent =
        _mm_add_ps(_mm_add_ps(absolute(_mm_mul_ps(broadcast<0>(halfExtents), col0)),
                              absolute(_mm_mul_ps(broadcast<1>(halfExtents), col1))),
                   absolute(_mm_mul_ps(broadcast<2>(halfExtents), col2)));
    aabbOut.max = _mm_add_ps(worldCenter, extent);
    aabbOut.min = _mm_add_ps(worldCenter, _mm_xor_ps(extent, _mm_set1_ps(-0.0f)));

    const Vec4 radius = _mm_set1_ps(convexRadius);
    aabbOut.max = _mm_add_ps(aabbOut.max, radius);
    aabbOut.min = _mm_sub_ps(aabbOut.min, radius);
}
