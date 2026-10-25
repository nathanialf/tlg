/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 13 of hknpConvexPolytopeShape's vtable (0x16a4460)
 * returns the number of its faces. The same body fills slot 13 of the
 * vtables of hknpCapsuleShape (0x169b260) and hknpTriangleShape
 * (0x169b670). */
int hknpConvexPolytopeShape::FUN_00072f70() const /* derived name */
{
    return faces.getSize();
}
