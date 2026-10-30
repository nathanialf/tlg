/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Whether the world's object at +0x4f8 holds one of the ids a stream
 * names, the ids gathered into the array first (derived name). */
static inline bool findsKnownId(hknpWorld *world, const hkBlockStream *stream, hkArray<int> &ids)
{
    hkBlockStreamReader reader;
    reader.FUN_000937c0(stream);
    hknpWorldObject4f8 *object = world->object4f8;
    object->FUN_00063ec0(reader, ids);
    return object->FUN_000640b0(ids);
}

/* Slot 5 under the timer: a context taken from the pool; when the world has
 * its object at +0x4f8 enabled and that object finds one of the ids the
 * stream names, the status says so; otherwise the pairs are prepared. The
 * interface's thunk (0x15bf10, a jump) is emitted with it. */
void hknpPrepareNewPairsTask::process()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    hknpWorldContextPool *pool = contextPool;
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();
    hknpWorld *world = context->world;
    if (world->enabled4f0 && findsKnownId(world, stream28, ids)) {
        status->found = true;
    } else {
        status->found = false;
        FUN_0015b8e0(context);
    }
    pool->FUN_0016ffe0(context);
    stream.timerEndList("lt");
}
