/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The triangles of the keys as quads under a scale, the fourth vertex the
 * first, the second and third swapped when the scale mirrors (one copy of
 * the walk for each winding). derived name. */
template <bool MIRRORED>
static inline void getTriangleQuads(const hknpExternMeshShape *shape,
                                    const hknpExternMeshShape::Geometry *geometry, const u32 *keys,
                                    int numTriangles, const Vec4 &scale,
                                    hknpShapeSlot22Output *output) /* derived name */
{
    for (int i = 0; i < numTriangles; i++) {
        const int triangleIndex = keys[i] >> (32 - shape->numShapeKeyBits);
        Vec4 vertices[4];
        geometry->unknownVirtual6(triangleIndex, vertices);
        vertices[0] = _mm_mul_ps(scale, vertices[0]);
        vertices[1] = _mm_mul_ps(scale, vertices[1]);
        vertices[2] = _mm_mul_ps(scale, vertices[2]);
        Vec4 *quad = &output->quadVertices[i * 4];
        quad[0] = vertices[0];
        quad[3] = vertices[0];
        if (MIRRORED) {
            quad[1] = vertices[2];
            quad[2] = vertices[1];
        } else {
            quad[1] = vertices[1];
            quad[2] = vertices[2];
        }
        output->quadFlags[i] = hknpShape::IS_CONVEX_SHAPE | hknpShape::IS_CONVEX_POLYTOPE_SHAPE |
                               hknpShape::SUPPORTS_COLLISIONS_WITH_INTERIOR_TRIANGLES |
                               hknpShape::USE_NORMAL_TO_FIND_SUPPORT_PLANE |
                               hknpShape::USE_SMALL_FACE_INDICES |
                               hknpShape::IS_TRIANGLE_OR_QUAD_SHAPE;
        output->quadShapeTags[i] = geometry->unknownVirtual7(triangleIndex);
    }
}

// NONMATCHING: 157 of 174, size 758 against 759: every instruction the base's but the walks'
// counter and the geometry's copy across the calls, r15 and r12 swapped (0x1664c0, 0x1664fb).
// Greedy (RegAllocGreedy::tryEvict) evicts `this` from r15 for the geometry's range, its
// spill weight the lighter (two loads in the loops against the output's eight stores), and the
// counter then evicts the output from r12; the base's eviction went the other way. Forms
// tried: one walk with the winding tested inside (no unswitch: one loop), the walk a static
// helper given the winding or the geometry, a template on the winding (all the same code).
void hknpExternMeshShape::FUN_001663e0(const u32 *keys, int numKeys,
                                       hknpShapeSlot22Output *output) const
{
    const Vec4 scale = output->scale;
    output->leafShape = this;
    output->convexRadius = 0.0f;
    output->flags = (output->flags & ~0x18) | 0x10;
    output->scale = D_14b2060[3];

    bool mirrored = false;
    if (_mm_movemask_ps(_mm_cmpneq_ps(scale, D_14b2060[3])) & 7) {
        const Vec4 determinant =
            _mm_mul_ps(_mm_shuffle_ps(scale, scale, _MM_SHUFFLE(2, 2, 2, 2)),
                       _mm_mul_ps(_mm_shuffle_ps(scale, scale, _MM_SHUFFLE(0, 0, 0, 0)),
                                  _mm_shuffle_ps(scale, scale, _MM_SHUFFLE(1, 1, 1, 1))));
        mirrored = _mm_movemask_ps(determinant) != 0;
    }

    const int numTriangles = hkMath::min2(numKeys, 10);
    if (numTriangles > 0) {
        const Geometry *geometry = this->geometry;
        if (mirrored) {
            getTriangleQuads<true>(this, geometry, keys, numTriangles, scale, output);
        } else {
            getTriangleQuads<false>(this, geometry, keys, numTriangles, scale, output);
        }
    }
    output->value = numTriangles;
}
