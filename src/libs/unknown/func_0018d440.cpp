/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpBroadPhaseExportNewPairsTask::process()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    stream.timerBegin("TtBroadPhase");
    hknpWorldContextPool *pool = owner->contextPool;
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();

    stream.timerBegin("TtAppendStreams");
    const int numPairs = owner->layers->layerPairs.getSize() / 2;
    for (int i = 0; i < numPairs; i++) {
        hkBlockStream *pairs = &owner->collideTasks[i]->newPairs;
        owner->newPairs->FUN_00094a10(context->cache250, pairs);
        pairs->FUN_00094990(context->cache250);
    }
    stream.timerEnd("Et");

    stream.timerBegin("TtUpdatePreviousAabbs");
    owner->bodyManager->FUN_00161350();
    stream.timerEnd("Et");

    stream.timerEnd("Et");
    pool->FUN_0016ffe0(context);
    stream.timerEndList("lt");
}
