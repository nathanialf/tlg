/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void StepStreams0015e980::FUN_0015e8b0(const hknpWorldContextPool::Context *context, int mode)
{
    inUse = true;
    slot0.FUN_00094750(context->cache258, true);
    slot1.FUN_00094750(context->cache258, true);
    slot2.FUN_00094750(context->cache258, false);
    slot3.FUN_00094750(context->cache258, false);
    if (mode == 1) {
        slot4.FUN_00094750(context->cache258, false);
        slot5.FUN_00094750(context->cache258, false);
        slot6.FUN_00094750(context->cache260, true);
    }
}
