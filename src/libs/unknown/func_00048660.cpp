/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpFlippedShapeCastQueryCollector's vtable
 * (0x1699020) forwards to the same slot of the collector it wraps (at
 * +0x30). */
bool hknpFlippedShapeCastQueryCollector::FUN_00048660() const /* derived name */
{
    return childCollector->unknownVirtual6();
}
