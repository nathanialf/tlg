/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 79 of 84: the cache's kind cleared through the register that
// holds the search's state argument (`mov byte [rcx], 0`, the compare's
// address shared by GVN) where the base stores through [rbx + 4], and in
// the else path the cached distance broadcast before the maximum is loaded
// (the base loads the maximum first).
/* The query's position brought into the shape's space; when the cache holds
 * a plane the point was outside of, the point still beyond that plane by
 * more than the maximum distance and the radius is no hit, and otherwise
 * the cache is cleared and the search starts at distance 0; else it starts
 * at the cached distance. The search's distance is cached either way. */
bool FUN_0014a090(const PointQuery0014a090 *query, const hknpConvexPolytopeShape *shape,
                  const hkTransform &transform, PointCache0014a090 *cache,
                  ClosestPointOutput00149880 *output) /* derived name */
{
    const Vec4 point = transformPosition(transform, query->position);
    Vec4 maxDistance;
    Vec4 startDistance;
    if (cache->state.type == 3) {
        const Vec4 plane = shape->planes.begin()[cache->state.planeIndex];
        const Vec4 distance = _mm_add_ps(broadcast<3>(plane), _mm_dp_ps(plane, point, 0x7f));
        maxDistance = _mm_set_ss(query->maxDistance);
        const Vec4 radius = _mm_set1_ps(shape->convexRadius);
        if (_mm_ucomigt_ss(distance, _mm_add_ps(broadcast<0>(maxDistance), radius))) {
            return false;
        }
        cache->state.type = 0;
        startDistance = _mm_setzero_ps();
    } else {
        startDistance = _mm_set1_ps(cache->distance);
        maxDistance = _mm_set_ss(query->maxDistance);
    }
    ClosestPointOutput00149880 result;
    ClosestPointInput00149880 input;
    input.tolerance = D_14b2060[35];
    input.maxDistance = broadcast<0>(maxDistance);
    result.distance = startDistance;
    if (FUN_00149880(shape, &point, &input, &cache->state, &result)) {
        output->unknown20 = result.unknown20;
        const Vec4 distance = result.distance;
        output->distance = distance;
        output->unknown0 = result.unknown0;
        output->unknown10 = result.unknown10;
        cache->distance = _mm_cvtss_f32(distance);
        return true;
    }
    cache->distance = _mm_cvtss_f32(result.distance);
    return false;
}
