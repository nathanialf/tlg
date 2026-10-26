/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpScaledConvexShapeBase's finish constructor: the decorator shape
 * finishes itself and the vtable is set. */
hknpScaledConvexShapeBase::hknpScaledConvexShapeBase(hkFinishLoadedObjectFlag flag)
    : hknpDecoratorShape(flag)
{
}
