/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The prepare-existing-pairs task's file (derived names), one object from
 * 0x179840 to 0x179c70 (D44): slot 5, the work, is the class's key
 * function, so the interface's thunk of it (0x179c70) is emitted with it. */

/* The task's constructor, called by FUN_00150330 on the 0x30 bytes it
 * takes from the thread's heap. */
hknpPrepareExistingPairsTask::hknpPrepareExistingPairsTask(void *unknown18, void *unknown20)
    : unknown18(unknown18), unknown20(unknown20)
{
}

/* derived name: the task's name for the dumps, its timer's, in the first
 * state's fill colour. */
void hknpPrepareExistingPairsTask::getName(hkStringBuf *name, hkStringBuf *description) const
{
    FUN_000116c0(name, "Collide/Prepare Existing Pairs");
    if (description) {
        FUN_000116c0(description, FUN_00091b30(0));
    }
}

/* Slot 5: the step's narrow phase prepared on a context from the pool: the
 * solver's elements made for the pool's contexts and the splitter's cells,
 * the new collision caches sorted through the context's command writer and
 * the commands they wrote linked into the first cell's list, then both
 * pairs tasks set up over the elements. */
void hknpPrepareExistingPairsTask::process()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    hknpWorldContextPool *pool = static_cast<hknpWorldContextPool *>(unknown18);
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();
    hknpWorld *world = context->world;
    ConstraintSetup00150330 *setup = static_cast<ConstraintSetup00150330 *>(unknown20);
    hknpWorldStreams260 *streams = world->streams260;
    stream.timerBeginList("LtPrepareNarrowPhase", "StAllocateSolverData");
    const int numCells = world->spaceSplitter->numCells;
    const int numCellPairs = world->spaceSplitter->numCellPairs;
    Elements000760c0 *elements =
        new Elements000760c0(context, context->cache260, context->cache250,
                             static_cast<hknpWorldContextPool *>(unknown18)->numUsed0 +
                                 static_cast<hknpWorldContextPool *>(unknown18)->numUsed4,
                             numCells, numCellPairs);
    setup->elements = elements;
    elements->simulationContext = static_cast<ElementsContext00077250 *>(unknown18);
    stream.timerSplitList("StSortNewCollisionCaches");
    context->commandRange.range.setStartPoint(&context->commandWriter->writer);
    streams->FUN_00174f30(context);
    context->commandRange.range.FUN_00092220(&context->commandWriter->writer);
    LinkedRange0015ea30 commands;
    commands = context->commandRange;
    hkBlockStreamWriter &commandWriter = context->commandWriter->writer;
    context->commandRange.range.setStartPoint(&commandWriter);
    if (commands.range.numElements != 0) {
        appendLinkedRange((*context->commandRanges)[0], commands, commandWriter);
    }
    stream.timerSplitList("StInitNarrowPhaseTasks");
    setup->existingPairsTask->FUN_0015e220(static_cast<hknpWorldContextPool *>(unknown18), context,
                                           setup->elements, streams, false);
    setup->newPairsTask->FUN_0015e220(static_cast<hknpWorldContextPool *>(unknown18), context,
                                      setup->elements, streams, false);
    stream.timerEndList("lt");
    pool->FUN_0016ffe0(context);
    stream.timerEndList("lt");
}
