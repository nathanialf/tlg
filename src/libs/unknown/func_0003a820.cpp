/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A vector's lanes without their signs (the sign bit shifted out). */
static inline Vec4 absolute(const Vec4 &v) /* derived name */
{
    const __m128i bits = _mm_castps_si128(v);
    return _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
}

void hknpBody::FUN_0003a820(const Vec4 &centerOfMassWorld)
{
    hkAabb aabb;
    shape->unknownVirtual7(identityTransform(), aabb);
    const Vec4 d = _mm_sub_ps(centerOfMassWorld, transform.translation);
    const Vec4 centerOfMassLocal = _mm_or_ps(_mm_or_ps(_mm_dp_ps(d, transform.rotation.col0, 0x71),
                                                       _mm_dp_ps(d, transform.rotation.col1, 0x72)),
                                             _mm_dp_ps(d, transform.rotation.col2, 0x74));
    const Vec4 extent = _mm_max_ps(absolute(_mm_sub_ps(aabb.min, centerOfMassLocal)),
                                   absolute(_mm_sub_ps(aabb.max, centerOfMassLocal)));
    radiusOfComCenteredBoundingSphere.setReal(length3(extent));
}
