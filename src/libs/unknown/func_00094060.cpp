/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Every lane's magnitude: the sign bit shifted out and back as zero. */
static inline Vec4 absolute(const Vec4 &v)
{
    const __m128i bits = _mm_castps_si128(v);
    return _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
}

void FUN_00094060(const Mat4 &transform, const hkAabb &aabb, hkAabb &aabbOut) /* derived name */
{
    const Vec4 sum = _mm_add_ps(aabb.min, aabb.max);
    const Vec4 center = _mm_mul_ps(D_14b2060[18], sum);
    const Vec4 difference = _mm_sub_ps(aabb.max, aabb.min);
    const Vec4 halfExtents = _mm_mul_ps(D_14b2060[18], difference);

    const Vec4 col0 = transform.r[0];
    const Vec4 col1 = transform.r[1];
    const Vec4 col2 = transform.r[2];
    const Vec4 rotated = _mm_add_ps(
        _mm_mul_ps(broadcast<2>(center), col2),
        _mm_add_ps(_mm_mul_ps(col0, broadcast<0>(center)), _mm_mul_ps(col1, broadcast<1>(center))));
    const Vec4 worldCenter = _mm_add_ps(rotated, transform.r[3]);

    const Vec4 extent =
        _mm_add_ps(_mm_add_ps(absolute(_mm_mul_ps(col0, broadcast<0>(halfExtents))),
                              absolute(_mm_mul_ps(broadcast<1>(halfExtents), col1))),
                   absolute(_mm_mul_ps(broadcast<2>(halfExtents), col2)));

    aabbOut.max = _mm_add_ps(worldCenter, extent);
    aabbOut.min = _mm_add_ps(worldCenter, _mm_xor_ps(extent, _mm_set1_ps(-0.0f)));
}
