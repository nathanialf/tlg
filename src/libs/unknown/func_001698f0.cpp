/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The convex hull of vertices scaled and offset, as a geometry (derived name; the convex shapes'
 * 0x169330 and the compressed mesh's 0x127b20 call it): in mode 2 with a radius each vertex is
 * expanded by the globals' directions times the radius, in mode 1 the built hull is moved out by
 * it; a failure when no hull is built. */
// NONMATCHING: D21's unswitch shape, 810 bytes against 925: the base holds the expansion's vertex
// loop twice, chosen by `numDirections > 0` before it (0x1699ae: the copy without the direction
// loop at 0x169b46 still grows the array by the count for each vertex), the non-trivial unswitch
// that 3.3 refuses under -O2 (LoopUnswitch.cpp:651, OptimizeForSize); this compile keeps the
// direction loop's guard inside the one vertex loop. The rest is the base's form; registers
// follow from the missing copy.
hkResult FUN_001698f0(const hkVector4 *vertices, int numVertices, int mode, const Vec4 &scale,
                      const Vec4 &offset, hkGeometry *geometryOut, float convexRadius, int material)
{
    hkArray<hkVector4>::Temp points;
    if (mode == 2 && convexRadius > 0.0f) {
        const hknpGlobals *globals = D_57c8818;
        const int numDirections = globals->directions.getSize();
        points.reserve(numDirections * numVertices);
        const Vec4 radius = _mm_set1_ps(convexRadius);
        for (int i = 0; i < numVertices; i++) {
            hkVector4 *expanded = points.expandBy(numDirections);
            for (int k = 0; k < numDirections; k++) {
                expanded[k].quad = _mm_mul_ps(vertices[i].quad, scale);
                expanded[k].quad = _mm_add_ps(expanded[k].quad, offset);
                expanded[k].quad =
                    _mm_add_ps(expanded[k].quad, _mm_mul_ps(radius, globals->directions[k].quad));
            }
        }
    } else {
        points.append(vertices, numVertices);
        for (int i = 0; i < numVertices; i++) {
            points[i].quad = _mm_mul_ps(points[i].quad, scale);
            points[i].quad = _mm_add_ps(points[i].quad, offset);
        }
    }

    hkgpConvexHull hull;
    hkgpConvexHull::BuildConfig config;
    config.flag0 = true;
    hkResult result = HK_FAILURE;
    if (hull.FUN_000b3950(hkStridedVertices(points), config) != -1) {
        if (mode == 1 && convexRadius > 0.0f) {
            hull.FUN_000b8d50(convexRadius);
        }
        hull.FUN_000bcee0(0, *geometryOut, material, true);
        result = HK_SUCCESS;
    }
    return result;
}
