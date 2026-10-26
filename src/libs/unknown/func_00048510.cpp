/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpFlippedGetClosestPointsQueryCollector's vtable
 * (0x1698fd0) forwards to the same slot of the collector it wraps (at
 * +0x20). */
bool hknpFlippedGetClosestPointsQueryCollector::FUN_00048510() const /* derived name */
{
    return childCollector->unknownVirtual6();
}
