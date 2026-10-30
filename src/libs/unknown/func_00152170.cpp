/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The closest point of a convex hull of planes to a point (0x187750, in
 * func_00188540.cpp). derived name. */
bool FUN_00187750(const Vec4 &point, const Vec4 *planes, int numPlanes,
                  const Vec4 &toleranceSquared, int maxIterations, Vec4 &closestOut,
                  Vec4 &normalOut, Vec4 &distanceOut, int *numIterationsOut);

// NONMATCHING: 40 of 74, 3 bytes over: the frame's four locals at the
// base's places; the preheader computes the planes' base before the
// tolerance's load (the base loads the constant table first), so the two
// spills come out in the other order (a frame 16 bytes larger) and the
// radii's broadcasts and the following registers differ (docs/NOTES.md,
// Round 64A).
void hknpConvexPolytopeShape::unknownVirtual18(const SignedDistanceQuery &query,
                                               SignedDistanceContact *contactsOut) const
{
    for (int i = 0; i < query.numSpheres; i++) {
        int numIterations;
        const Vec4 tolerance = D_14b2060[33];
        Vec4 distance;
        Vec4 closest;
        SignedDistanceContact &contact = contactsOut[i];
        FUN_00187750(query.sphereCenters[i], planes.begin(), faces.getSize(), tolerance, 1, closest,
                     contact.normal, distance, &numIterations);
        const Vec4 sphereRadius = simdFromFloat(query.sphereRadius);
        distance = _mm_add_ps(_mm_sub_ps(sphereRadius, simdFromFloat(convexRadius)), distance);
        contact.sphereIndex = u16(i);
        contact.shapeKey = 0xffffffff;
        contact.shapeTag = 0xffff;
        contact.position = _mm_add_ps(_mm_mul_ps(sphereRadius, contact.normal), closest);
        _mm_store_ss(&contact.distance, distance);
    }
}
