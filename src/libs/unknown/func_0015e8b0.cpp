/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void StepStreams0015e980::FUN_0015e8b0(const StreamCaches0015e980 *caches, int mode)
{
    inUse = true;
    slot0.FUN_00094750(caches->cache, true);
    slot1.FUN_00094750(caches->cache, true);
    slot2.FUN_00094750(caches->cache, false);
    slot3.FUN_00094750(caches->cache, false);
    if (mode == 1) {
        slot4.FUN_00094750(caches->cache, false);
        slot5.FUN_00094750(caches->cache, false);
        slot6.FUN_00094750(caches->secondCache, true);
    }
}
