/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpConvexShape's finish constructor, then the sphere's flags when the
 * object is being finished. */
hknpSphereShape::hknpSphereShape(hkFinishLoadedObjectFlag flag) : hknpConvexShape(flag)
{
    if (flag.finishing) {
        flags |=
            IS_CONVEX_SHAPE | USE_SINGLE_POINT_MANIFOLD | USE_SMALL_FACE_INDICES | IS_SPHERE_SHAPE;
    }
}
