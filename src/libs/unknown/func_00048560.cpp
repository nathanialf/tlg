/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 3 of hknpFlippedShapeCastQueryCollector's vtable (0x1699020) forwards to the same slot of
 * the collector it wraps (at +0x30). */
void hknpFlippedShapeCastQueryCollector::FUN_00048560() /* derived name */
{
    childCollector->reset();
}
