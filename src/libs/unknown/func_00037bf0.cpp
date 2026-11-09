/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpMaskedShape's destructor (slot 0 of its vtable, 0x37c40): the
 * destroyed signal fired, the owned mask deleted as slot 31 deletes it, the
 * core shape's reference released, then the members (the two signals) and
 * hknpShape's destructor. The deleting destructor (0x37bf0, slot 1) is
 * emitted beside it. The fire loop is cookbook 168. */
hknpMaskedShape::~hknpMaskedShape()
{
    mutationSignals.shapeDestroyed.fire();
    if (mask && (memSizeAndRefCount >> 16) != 0) {
        delete mask;
        mask = 0;
    }
    coreShape->removeReference();
}
