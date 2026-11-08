/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 2 of the collide task: under the collide stage's broad phase timer,
 * a context taken from the world's pool, the task's pair stream set up over
 * its cache, and when both layers' trees hold boxes the trees walked against
 * each other into a writer on that stream, under their own timer; the
 * context goes back. */
void BroadPhaseCollideTask::process()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    stream.timerBegin("TtBroadPhase");
    hknpWorldContextPool *pool = owner->contextPool;
    BroadPhaseLayers00142a40 *layers = owner->layers;
    const BroadPhaseTree00142a40 *treeA = layers->trees[layers->layerPairs[2 * index]];
    const BroadPhaseTree00142a40 *treeB = layers->trees[layers->layerPairs[2 * index + 1]];
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();
    newPairs.FUN_00094750(context->cache250, false);
    if (treeA->numEntries > 0 && treeB->numEntries > 0) {
        stream.timerBegin("TtQueryTreeVsTree");
        hkBlockStreamWriter writer;
        writer.FUN_000938c0(context->cache250, &newPairs);
        FUN_00197c60(context, context->world->modifierManager->collisionFilter.pntr, treeA, treeB,
                     &writer, owner->bodyManager->previousAabbs.data);
        writer.FUN_00093a10();
        stream.timerEnd("Et");
    }
    stream.timerEnd("Et");
    pool->FUN_0016ffe0(context);
    stream.timerEndList("lt");
}
