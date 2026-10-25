/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpConvexShape's vtable (address point 0x1697da0)
 * returns the object's size: the shape followed by its vertices, kept in
 * whole groups of four (the creator at 0x44ee0 pads the count to a multiple
 * of four and allocates the same size). The same body fills slot 6 of
 * hknpSphereShape's (0x1695c20). */
int hknpConvexShape::FUN_000430e0() const /* derived name */
{
    return sizeof(hknpConvexShape) + (vertices.getSize() & ~3) * sizeof(Vec4);
}
