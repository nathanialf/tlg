/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of hknpConvexShape's vtable (0x1697d90) returns the
 * number of its vertices. The same body fills slot 9 of the vtables of
 * hknpTriangleShape (0x169b670), hknpConvexPolytopeShape (0x16a4460) and
 * the class at 0x1695c10. */
int hknpConvexShape::FUN_00045ac0() const /* derived name */
{
    return vertices.getSize();
}
