/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpBody::FUN_0003a820(const Vec4 &centerOfMassWorld)
{
    hkAabb aabb;
    shape->unknownVirtual7(identityTransform(), aabb);
    const Vec4 d = _mm_sub_ps(centerOfMassWorld, transform.translation);
    const Vec4 centerOfMassLocal = _mm_or_ps(_mm_or_ps(_mm_dp_ps(d, transform.rotation.col0, 0x71),
                                                       _mm_dp_ps(d, transform.rotation.col1, 0x72)),
                                             _mm_dp_ps(d, transform.rotation.col2, 0x74));
    const Vec4 extent = _mm_max_ps(hkMath::quadFabs(_mm_sub_ps(aabb.min, centerOfMassLocal)),
                                   hkMath::quadFabs(_mm_sub_ps(aabb.max, centerOfMassLocal)));
    radiusOfComCenteredBoundingSphere.setReal(length3(extent));
}
