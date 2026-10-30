/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void StepStreams0015e980::FUN_0015e980(const StreamCaches0015e980 *caches, int mode)
{
    slot0.stream.FUN_00094990(caches->cache);
    slot2.stream.FUN_00094990(caches->cache);
    slot1.stream.FUN_00094990(caches->cache);
    slot3.stream.FUN_00094990(caches->cache);
    if (mode == 1) {
        slot4.stream.FUN_00094990(caches->cache);
        slot5.stream.FUN_00094990(caches->cache);
        slot6.stream.FUN_00094990(caches->secondCache);
    }
}
