/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A sphere as a geometry (derived reading; 0x127b20 calls it with 12): the
 * directions of an n by n grid of coordinates from 0 to 1, each scaled by
 * the radius about the centre, then the convex hull of those points
 * written as the geometry with the material given. The radius is the
 * second parameter: the argument copies are made in the reverse of the
 * parameters' order (esi before xmm0). */
void FUN_00188ed0(const Vec4 &center, float radius, int n, hkGeometry *geometryOut,
                  int material) /* derived name */
{
    hkArray<hkVector4, hkContainerTempAllocator> points;
    points.reserve(hkContainerTempAllocator::get(), n * n);
    const Vec4 radiusV = _mm_set1_ps(radius);
    const float step = 1.0f / float(n - 1);
    for (int i = 0; i < n; i++) {
        const float u = float(i) * step;
        for (int j = 0; j < n; j++) {
            hkVector4 coordinates;
            coordinates.quad = _mm_setr_ps(u, float(j) * step, 0.0f, 0.0f);
            hkVector4 &point = points.expandOne(hkContainerTempAllocator::get());
            FUN_000c05b0(coordinates, point);
            point.quad = _mm_mul_ps(radiusV, point.quad);
            point.quad = _mm_add_ps(point.quad, center);
        }
    }

    hkgpConvexHull hull;
    hkStridedVertices stridedVertices(points);
    hkgpConvexHull::BuildConfig config;
    hull.FUN_000b3950(stridedVertices, config);
    hull.FUN_000bcee0(0, *geometryOut, material, true);
}
