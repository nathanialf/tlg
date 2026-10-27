/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpScaledConvexShapeBase's finish constructor: the decorator shape
 * finishes itself and the vtable is set. */
hknpScaledConvexShapeBase::hknpScaledConvexShapeBase(hkFinishLoadedObjectFlag flag)
    : hknpDecoratorShape(flag)
{
}

/* hknpScaledConvexShape's finish constructor (0x16ce90) shares this file:
 * it runs the base's inline (the decorator's call, then only its own
 * vtable), which it can only do with the base's body in the same file. The
 * signals, not serialized, start empty. */
hknpScaledConvexShape::hknpScaledConvexShape(hkFinishLoadedObjectFlag flag)
    : hknpScaledConvexShapeBase(flag)
{
}
