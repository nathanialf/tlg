/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpScaledOffsetQueryCollector's vtable (address
 * point 0x16a55c0) forwards to the same slot of the collector it wraps (at
 * +0x58); a bool return keeps the call (cookbook 25). */
bool hknpScaledOffsetQueryCollector::FUN_0016d1d0() const /* derived name */
{
    return childCollector->unknownVirtual6();
}
