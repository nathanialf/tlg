/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* Slot 5 of the solver factory task, under the solve timer: a context taken
 * from the pool, a new solve data task over it kept by the owner (its
 * reference handed over), the arrays given room for the solver's tasks over
 * every sub step, an entry of no task added and the solve data task's tasks
 * before it, a pointer for that entry given to the queue with the factory's
 * own, the arrays built for the queue and the factory's pointer handed back;
 * the context goes back. The interface's slot 2 is its this-adjusting
 * thunk (0x14e840). */
void hknpSolverFactoryTask::process()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StSolve");
    hknpWorldContextPool *pool = contextPool;
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();
    void *pointer10 = owner->pointer10;
    owner->task190.setAndDontIncrementRefCount(
        new hknpSolveDataTask(contextPool, context, pointer10));

    const hknpWorld *world = context->world;
    const int numSubSteps = world->solverInfo.numSteps * world->solverInfo.numMicroSteps;
    const int numTasks =
        world->spaceSplitter->FUN_0018e380(
            static_cast<hknpSolveDataTask *>(owner->task190.pntr)->solveData->records, 3) *
        numSubSteps;
    arrays.FUN_00092510(numTasks + 2, 2 * numTasks + 4);
    const RefArrays::EntryId entry = arrays.FUN_000922f0(HK_NULL, 1, 0);
    RefArrays::EntryId none;
    none.value = 0xffff;
    static_cast<hknpSolveDataTask *>(owner->task190.pntr)
        ->FUN_0016e7d0(contextPool, context, pointer10, &arrays, none, entry);
    void *pointer = arrays.FUN_000925d0(queue, entry);
    queue->unknownVirtual4(pointer, unknown30);
    arrays.FUN_00092650(queue, 12);
    queue->unknownVirtual6(&unknown30, 1);
    pool->FUN_0016ffe0(context);
    stream.timerEndList("lt");
}
