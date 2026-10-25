/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 10 of hknpConvexShape's vtable (0x1697d90) returns its
 * vertices, stored after the shape at the relative array's offset. The same
 * body fills slot 10 of the vtables of hknpSphereShape (0x1695c10),
 * hknpTriangleShape (0x169b670) and hknpConvexPolytopeShape (0x16a4460). */
const Vec4 *hknpConvexShape::FUN_00045ad0() const /* derived name */
{
    return vertices.begin();
}
