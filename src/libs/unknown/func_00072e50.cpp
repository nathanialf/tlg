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
