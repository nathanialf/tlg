/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 3 of hknpFlippedGetClosestPointsQueryCollector's vtable (0x1698fd0),
 * the class's key function: the vtable and the inline destructors are
 * emitted here, the deleting one (0x483d0) freeing the collector's 0x30
 * bytes. Forwards to the same slot of the collector it wraps (at +0x20). */
void hknpFlippedGetClosestPointsQueryCollector::reset()
{
    childCollector->reset();
}
