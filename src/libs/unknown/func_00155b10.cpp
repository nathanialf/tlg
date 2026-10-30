/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void ShapeWatcher::FUN_00155b10()
{
    hknpShapeSignals *signals = shape->unknownVirtual8();
    signals->shapeMutated.unsubscribe(this, &ShapeWatcher::FUN_00155b00);
    signals->shapeDestroyed.unsubscribe(this, &ShapeWatcher::FUN_00155b10);
    shape = 0;
    owner->anyShapeChanged = true;
}
