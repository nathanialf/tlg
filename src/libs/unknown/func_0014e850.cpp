/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 5 under the solve timer: a context taken from the pool, its
 * union-find opened, the pair stream of every context with pairs joined
 * into it relative to the context's node ranges, then closed and
 * collapsed. The class's key function: its vtable and the interface's
 * thunk (0x14ea10, a jump) are emitted here. */
void hknpAddActiveBodyPairsTask::process()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StSolve");
    stream.timerBegin("TtAddActiveBodyPairs");
    hknpWorldContextPool *pool = contextPool;
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();
    CollideShared0015ea30 *shared = owner->shared;
    Object00065f20 *unionFind = context->unionFind;
    const hkArray<UnionFindRange> *ranges = context->unionFindRanges;
    FUN_00065f10(unionFind);
    for (int i = 0; i < shared->numContexts; i++) {
        const hkBlockStream &pairs = shared->contextStreams[i][0];
        if (pairs.numTotalElements) {
            FUN_00065fd0(unionFind, &pairs, *ranges);
        }
    }
    FUN_00065f20(unionFind);
    unionFind->unionFind->FUN_0008f7d0();
    stream.timerEnd("Et");
    pool->FUN_0016ffe0(context);
    stream.timerEndList("lt");
}
