/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The stage after the collide tasks under the timer "PostCollide": the
 * commands the tasks wrote dispatched through a context lent to the event
 * dispatcher and the object at +0x6d0, each context's command range then
 * started again where its writer is, and the post-collide signal fired when
 * anything subscribed to it. derived name. */
void hknpWorld::FUN_000505f0()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBegin("TtPostCollide");
    stream.timerBegin("TtDispatchCommands");
    hknpWorldContextPool *pool = contextPool;
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();
    eventDispatcher->setStepContext(object1d0->elements, context);
    object6d0->setStepContext(object1d0->elements, context);
    contextPool->FUN_001704b0(context, eventDispatcher);
    object6d0->clearStepContext();
    eventDispatcher->setStepContext(HK_NULL, HK_NULL);
    stream.timerEnd("Et");
    pool->FUN_0016ffe0(context);
    for (int i = 0; i < contextPool->numUsed0; i++) {
        hknpWorldContextPool::Context &c = contextPool->contexts[i];
        c.commandRange.range.setStartPoint(&c.commandWriter->writer);
    }
    if (untagSlotLink(signals.postCollideSignal.slots)) {
        stream.timerBegin("TtPostCollideSignal");
        signals.postCollideSignal.fire(this);
        stream.timerEnd("Et");
    }
    stream.timerEnd("EtPostCollide");
}
