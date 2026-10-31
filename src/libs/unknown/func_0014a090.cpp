/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

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
    float maxDistance;
    Vec4 startDistance;
    if (cache->state.type == 3) {
        const Vec4 plane = shape->planes.begin()[cache->state.planeIndex];
        const Vec4 distance = _mm_add_ps(broadcast<3>(plane), _mm_dp_ps(plane, point, 0x7f));
        maxDistance = query->maxDistance;
        const Vec4 radius = _mm_set1_ps(shape->convexRadius);
        if (_mm_ucomigt_ss(distance, _mm_add_ps(_mm_set1_ps(maxDistance), radius))) {
            return false;
        }
        cache->reset();
        startDistance = _mm_setzero_ps();
    } else {
        startDistance = _mm_set1_ps(cache->distance);
        maxDistance = query->maxDistance;
    }
    ClosestPointOutput00149880 result;
    ClosestPointInput00149880 input;
    input.tolerance = D_14b2060[35];
    input.maxDistance = _mm_set1_ps(maxDistance);
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
