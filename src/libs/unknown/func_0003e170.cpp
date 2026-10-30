/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpShape's finish constructor, then the signals, which are not
 * serialized, constructed empty. */
hknpDummyShape::hknpDummyShape(hkFinishLoadedObjectFlag flag) : hknpShape(flag) {}

/* The destroyed signal fired, then the signals and hknpShape's destructor
 * (0x3e200, slot 0; the deleting destructor 0x3e1b0, slot 1, is emitted
 * beside it). The fire loop is cookbook 168. */
hknpDummyShape::~hknpDummyShape()
{
    signals.shapeDestroyed.fire();
}
