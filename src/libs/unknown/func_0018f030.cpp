/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The cases in this order: the switch lowering tests the case whose block
 * follows last (SelectionDAGBuilder handleSmallSwitchRange), so the base's
 * `cmp 1` before `test 0` has case 0 first in the source. */
bool FUN_0018f030(hknpWorldContextPool::Context *context, SolverStages0018ef40 *stages, int stage,
                  int subStage, int threadIndex, const SolverStageInfo0018ef40 *info)
{
    const u8 index3 = info->index3;
    const u8 index4 = info->index4;
    const int lastSubStage = stages->config->numSubStages - 1;
    switch (info->type) {
    case 0:
        FUN_00198b40(context, stage, subStage, threadIndex, info->index1, info->index2, index3,
                     index4, stages);
        if (subStage != lastSubStage) {
            return false;
        }
        break;
    case 1:
        if (subStage != lastSubStage) {
            return false;
        }
        FUN_00198f30(context, stage, subStage, threadIndex, index3, stages);
        break;
    default:
        if (subStage != lastSubStage) {
            return false;
        }
    }
    if (info->flags & 1) {
        FUN_00198f30(context, stage, subStage, threadIndex, index3, stages);
    }
    if (info->flags & 2) {
        FUN_00198f30(context, stage, subStage, threadIndex, index4, stages);
    }
    return false;
}
