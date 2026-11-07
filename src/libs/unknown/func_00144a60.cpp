/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BroadPhaseLayers00142a40::FUN_00144a60(const void *argument1, const hknpRayCastQuery &query,
                                            void *argument3, const void *argument4,
                                            const hkIntSpaceUtil &intSpace,
                                            hknpCollisionQueryCollector *collector) const
{
    /* The ray in the broad phase's 16-bit space. */
    const Vec4 origin =
        _mm_mul_ps(_mm_add_ps(query.ray.origin, intSpace.bitOffsetLow), intSpace.bitScale);
    const Vec4 direction = _mm_mul_ps(intSpace.bitScale, query.ray.direction);
    hkcdRay ray;
    ray.setOriginDirection(origin, direction);
    RayCastContext00144a60 context(argument1, query, &ray, argument3, collector);
    for (u8 layer = 0; layer < numLayers; layer++) {
        if (!query.filter || query.filter->FUN_00167ad0(1, layer)) {
            const BroadPhaseTree00142a40 *tree = trees[layer];
            FUN_00144170(tree, tree->root, &query, &ray, &context, collector);
        }
    }
}
