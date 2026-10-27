/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpConvexPolytopeShape's finish constructor, then the triangle's flags
 * when the object is being finished. */
hknpTriangleShape::hknpTriangleShape(hkFinishLoadedObjectFlag flag) : hknpConvexPolytopeShape(flag)
{
    if (flag.finishing) {
        flags |= IS_CONVEX_SHAPE | IS_CONVEX_POLYTOPE_SHAPE |
                 SUPPORTS_COLLISIONS_WITH_INTERIOR_TRIANGLES | USE_NORMAL_TO_FIND_SUPPORT_PLANE |
                 USE_SMALL_FACE_INDICES | IS_TRIANGLE_OR_QUAD_SHAPE;
    }
}
