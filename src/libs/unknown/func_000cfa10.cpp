/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpScaledQueryCollector's vtables (0x16a3c50,
 * 0x16a3d00) forwards to the same slot of the collector it wraps (at
 * +0x48); a bool return keeps the call (cookbook 25). */
bool hknpScaledQueryCollector::FUN_000cfa10() const /* derived name */
{
    return childCollector->unknownVirtual6();
}
