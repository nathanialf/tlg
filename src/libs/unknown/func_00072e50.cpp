/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The convex polytope shape's destructor (the capsule and the triangle
 * keep it): the connectivity released, then the shape's. */
hknpConvexPolytopeShape::~hknpConvexPolytopeShape() {}

/* hknpConvexPolytopeShape's finish constructor, then the capsule's flags
 * when the object is being finished (0x730d0). The capsule's vtable comes
 * with it, and its deleting destructor (0x72ec0, the polytope's destructor
 * inline and the capsule's 0x60 bytes freed). */
hknpCapsuleShape::hknpCapsuleShape(hkFinishLoadedObjectFlag flag) : hknpConvexPolytopeShape(flag)
{
    if (flag.finishing) {
        flags |= IS_CONVEX_SHAPE | IS_CONVEX_POLYTOPE_SHAPE |
                 SUPPORTS_COLLISIONS_WITH_INTERIOR_TRIANGLES | USE_NORMAL_TO_FIND_SUPPORT_PLANE |
                 USE_SMALL_FACE_INDICES;
    }
}

/* hknpConvexPolytopeShape's finish constructor, then the triangle's flags
 * when the object is being finished (0x78230). The triangle's vtable comes
 * with it, and its deleting destructor (0x780a0, the polytope's destructor
 * inline and the triangle's 0x40 bytes freed; the polytope's vtable cites
 * the same body). */
hknpTriangleShape::hknpTriangleShape(hkFinishLoadedObjectFlag flag) : hknpConvexPolytopeShape(flag)
{
    if (flag.finishing) {
        flags |= IS_CONVEX_SHAPE | IS_CONVEX_POLYTOPE_SHAPE |
                 SUPPORTS_COLLISIONS_WITH_INTERIOR_TRIANGLES | USE_NORMAL_TO_FIND_SUPPORT_PLANE |
                 USE_SMALL_FACE_INDICES | IS_TRIANGLE_OR_QUAD_SHAPE;
    }
}

/* The capsule's slot 18 (0x73950), its first out-of-line virtual: the file
 * emits the capsule's vtable and its deleting destructor (0x72ec0). */
// NONMATCHING: 62 of 64, same size: every operation and operand order the
// base's (the projection's dot taken before the reciprocal and the sphere's
// radius read before the capsule's, Reassociate's ranks); left: the
// latch's two steps, `add r9, 0x10` before `lea r8, [rdx + 0x50]` in the
// base (docs/NOTES.md, Round 70A).
void hknpCapsuleShape::unknownVirtual18(const SignedDistanceQuery &query,
                                        SignedDistanceContact *contactsOut) const
{
    for (int i = 0; i < query.numSpheres; i++) {
        /* The sphere's closest point on the segment: its projection on
         * the segment, the parameter clamped to the ends and kept in w. */
        const Vec4 ab = _mm_sub_ps(a, b);
        const Vec4 lengthSquared = _mm_dp_ps(ab, ab, 0x7f);
        const Vec4 center = query.sphereCenters[i];
        const Vec4 toA = _mm_sub_ps(a, center);
        const Vec4 projection = _mm_dp_ps(ab, toA, 0x7f);
        const Vec4 r = _mm_rcp_ps(lengthSquared);
        const Vec4 invLengthSquared =
            _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(lengthSquared, r)));
        Vec4 t = _mm_mul_ps(projection, invLengthSquared);
        t = _mm_blendv_ps(D_14b2060[3], t, _mm_cmplt_ps(t, D_14b2060[3]));
        t = _mm_max_ps(_mm_setzero_ps(), t);
        Vec4 closest = _mm_add_ps(center, _mm_sub_ps(toA, _mm_mul_ps(ab, t)));
        closest = _mm_blend_ps(closest, t, 8);

        const Vec4 sphereRadius = simdFromFloat(query.sphereRadius);
        const Vec4 radius = simdFromFloat(convexRadius);
        const Vec4 radiusSum = _mm_add_ps(sphereRadius, radius);
        const Vec4 d = _mm_sub_ps(center, closest);
        const Vec4 dSquared = _mm_dp_ps(d, d, 0x7f);
        const Vec4 invLength = lengthInverse3(d);
        SignedDistanceContact &contact = contactsOut[i];
        _mm_store_ss(&contact.distance, _mm_sub_ps(_mm_mul_ps(dSquared, invLength), radiusSum));
        const Vec4 normal = _mm_mul_ps(d, invLength);
        contact.position = _mm_add_ps(closest, _mm_mul_ps(radius, normal));
        contact.normal = normal;
        contact.shapeTag = 0xffff;
        contact.shapeKey = 0xffffffff;
    }
}
