/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the box of half extents about the origin, its AABB from
 * the extents negated to the extents, built by 0x451e0. */
hknpConvexShape *FUN_00045190(const Vec4 &halfExtents, float convexRadius,
                              const ConvexBuildConfig000451e0 &config)
{
    hkAabb aabb;
    aabb.min = _mm_xor_ps(halfExtents, _mm_set1_ps(-0.0f));
    aabb.max = halfExtents;
    return FUN_000451e0(aabb, convexRadius, config);
}
