/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpConvexShape's finish constructor, then the flags' two low bits set
 * when the object is being finished. */
hknpConvexPolytopeShape::hknpConvexPolytopeShape(hkFinishLoadedObjectFlag flag)
    : hknpConvexShape(flag), connectivity(flag)
{
    if (flag.finishing) {
        flags |= IS_CONVEX_SHAPE | IS_CONVEX_POLYTOPE_SHAPE;
    }
}
