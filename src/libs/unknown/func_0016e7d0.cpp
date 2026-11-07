/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

void hknpSolveDataTask::FUN_0016e7d0(hknpWorldContextPool *pool,
                                     hknpWorldContextPool::Context *context, void *argument3,
                                     RefArrays *arrays, RefArrays::EntryId before,
                                     RefArrays::EntryId after)
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("LtCreateSolverTask", "StBuildGraph");
    const hknpWorld *world = context->world;
    const hknpSpaceSplitter *splitter = world->spaceSplitter;
    elements.reserve(hkContainerHeapAllocator::get(), 256);
    const RefArrays::EntryId self = arrays->FUN_00092380(this, 1, 0);
    FUN_0018e3e0(&elements, world->solverInfo.numSteps, world->solverInfo.numMicroSteps, splitter,
                 unknownA0, unknown40, 3, &ranges, solveData, before, after, arrays);
    solveData->tasksAdded = 1;
    if (before.value != 0xffff && self.value != 0xffff) {
        arrays->addDependency(before.value, self.value);
    }
    if (self.value != 0xffff && after.value != 0xffff) {
        arrays->addDependency(self.value, after.value);
    }
    stream.timerEndList("lt");
}
