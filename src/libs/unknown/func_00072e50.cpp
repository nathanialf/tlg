/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The convex polytope shape's destructor (the capsule and the triangle
 * keep it): the connectivity released, then the shape's. */
hknpConvexPolytopeShape::~hknpConvexPolytopeShape() {}
