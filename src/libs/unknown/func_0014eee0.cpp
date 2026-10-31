/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 5 under the collide timer: a context taken from the pool, the world's
 * inactive caches cleaned in two steps over its streams at +0x600 and
 * +0x700, the commands the first step wrote kept as the task's range. The
 * interface's thunk (0x14f180, a jump) is emitted with it. */
void hknpCleanInactiveCachesTask::process()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    stream.timerBegin("TtCleanInactiveCaches");
    hknpWorldContextPool *pool = contextPool;
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();
    hknpWorld *world = context->world;
    hknpWorldObject4f8 *deactivation = world->object4f8;
    hknpWorldStreams260 *streams = world->streams260;
    context->commandRange.range.setStartPoint(&context->commandWriter->writer);
    ModifierSharedData shared;
    shared.FUN_00167c90(world);
    FUN_000657b0(deactivation, context, &shared, &streams->stream700);
    context->commandRange.range.FUN_00092220(&context->commandWriter->writer);
    commands = context->commandRange;
    context->commandRange.range.setStartPoint(&context->commandWriter->writer);
    FUN_00064810(deactivation, context, &streams->stream600, &streams->stream700, 0);
    stream.timerEnd("Et");
    pool->FUN_0016ffe0(context);
    stream.timerEndList("lt");
}
