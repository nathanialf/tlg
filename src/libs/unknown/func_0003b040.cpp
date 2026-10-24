/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 0 of hknpDecoratorShape's vtable (0x16958d0): the class adds nothing
 * to destroy, so its destructor is its base's (the compiler emits the
 * complete destructor as a jump to hknpShape's). The same body fills slot 0
 * of the vtables of hknpSphereShape (0x1695c10), hknpConvexShape (0x1697d90)
 * and hknpScaledConvexShapeBase (0x16a5390). */
hknpDecoratorShape::~hknpDecoratorShape() {}
