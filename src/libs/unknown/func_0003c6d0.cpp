/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The directions of a 16 by 16 grid of coordinates from 0 to 1 in
 * fifteenths, each scaled by the convex radius about the centre, then the
 * convex hull of those points written as the geometry when it is solid. */
hkResult hknpSphereShape::FUN_0003c6d0(const hknpShapeSlot29Input &input,
                                       hkGeometry *geometryOut) const
{
    const Vec4 &center = *vertices.begin();
    const Vec4 radius = _mm_set1_ps(convexRadius);
    hkArray<hkVector4> points;
    points.reserve(hkContainerHeapAllocator::get(), 16 * 16);
    for (int i = 0; i < 16; i++) {
        hkVector4 coordinates;
        coordinates.quad = _mm_setzero_ps();
        lane(coordinates.quad, 0) = float(i) * (1.0f / 15.0f);
        for (int j = 0; j < 16; j++) {
            lane(coordinates.quad, 1) = float(j) * (1.0f / 15.0f);
            hkVector4 direction;
            FUN_000c05b0(coordinates, direction);
            direction.quad = _mm_add_ps(_mm_mul_ps(radius, direction.quad), center);
            points.pushBackUnchecked(direction);
        }
    }

    hkgpConvexHull hull;
    hkStridedVertices stridedVertices(points);
    hkgpConvexHull::BuildConfig config;
    hkResult result = HK_FAILURE;
    if (hull.FUN_000b3950(stridedVertices, config) == 3) {
        result = HK_SUCCESS;
        hull.FUN_000bcee0(0, *geometryOut, -1, true);
    }
    return result;
}
