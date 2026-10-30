/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The triangle's vertices in order, then reversed, the fourth vertex
 * last in both. derived name. */
static const u8 triangleIndices[8] = {0, 1, 2, 3, 2, 1, 0, 3};

hknpTriangleShape::hknpTriangleShape(int argument1)
    : hknpConvexPolytopeShape(4, 4, 8, 0.01f, sizeof(hknpTriangleShape))
{
    flags = IS_CONVEX_SHAPE | IS_CONVEX_POLYTOPE_SHAPE |
            SUPPORTS_COLLISIONS_WITH_INTERIOR_TRIANGLES | USE_NORMAL_TO_FIND_SUPPORT_PLANE |
            USE_SMALL_FACE_INDICES | IS_TRIANGLE_OR_QUAD_SHAPE;

    Face *face = faces.beginBytes();
    for (int i = 0; i < 4; i++) {
        face[i].firstIndex = 0;
        face[i].numIndices = 4;
        face[i].minHalfAngle = 127;
    }
    face[1].firstIndex = 4;

    memcpy(indices.beginBytes(), triangleIndices, sizeof(triangleIndices));

    setMemSize(u16((indices.endOffset(this) + 15) & ~15));
}
