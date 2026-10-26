/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 3 of hknpScaledQueryCollector's vtables (0x16a3c50,
 * 0x16a3d00) forwards to the same slot of the collector it wraps (at
 * +0x48). */
void hknpScaledQueryCollector::FUN_000cf8c0() /* derived name */
{
    childCollector->reset();
}
