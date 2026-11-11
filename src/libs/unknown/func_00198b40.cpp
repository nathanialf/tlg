/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The object 0x198b40 to 0x198f30 (docs/DECISIONS.md D44): a solver
 * stage's two kinds of work. 0x198b40, over the stage's four indices, is
 * not written yet. */

/* A stage's sub-integration over the motions of one index (0x198f30;
 * 0x18f030 calls it): the step set up from the solver's settings, the
 * motions' velocities integrated (the last step's with the record at +0x220
 * of the context), and the commands the context wrote meanwhile linked into
 * the list of the index's cell with itself. derived name. */
// NONMATCHING: two residuals, round 142C. (1) cookbook 335: the base holds u16(index + 1) as
// `shl 16; add 0x10000; shr 16`, which this cellPairIndex folds to `lea [rax + 1]` (index is a u8,
// so the mask is known redundant); a pair of u16 built and passed by value (coerced to one i32)
// reproduces it exactly and with it every instruction's shape (cookbook 997), but no developer
// form of that pair is known. (2) with it, greedy's assignment differs throughout (149 of 230,
// the same instructions): the command range's address (context + 0x390, FUN_00092220's this and
// the copy's source) is one GEP with the start's, CSE'd into the entry block and spilled across
// the integration calls, where the base computes it after them (`lea r15, [r14 + 0x390]` at
// 0x199165) and spills the timer stream instead; the start's range expression must differ from
// the end's in the base's IR (not found).
void FUN_00198f30(hknpWorldContextPool::Context *context, int stage, int subStage, int threadIndex,
                  u8 index, SolverStages0018ef40 *stages)
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBegin("TtSubIntegrate");
    context->commandRange.range.setStartPoint(&context->commandWriter->writer);
    hknpSolverStep step;
    step.FUN_0006c260(*stages->config, stage, subStage);
    const int listIndex = cellPairIndex(index, index);
    const SolverStages0018ef40::MotionRange &range = stages->motionRanges[index];
    const int numMotions = (range.count + 3) & ~3;
    if (stage < stages->config->numSteps - 1) {
        stream.timerBegin("TtSubIntegrate");
        FUN_00148400(context, step, stages->velocities + range.first, stages->sums + range.first,
                     numMotions, *stages->config, stages->motionProperties);
    } else {
        stream.timerBegin("TtSubIntegrateLast");
        if (context->world->enabled4f0) {
            FUN_00148720(step, stages->velocities + range.first, stages->sums + range.first,
                         numMotions, stages->data50, stages->data90, stages->motionProperties,
                         stages, context, context->pointer240, context->record220->data,
                         range.first, context->record220->count);
        } else {
            FUN_00148720(step, stages->velocities + range.first, stages->sums + range.first,
                         numMotions, stages->data50, stages->data90, stages->motionProperties,
                         stages, context, context->pointer240, HK_NULL, 0, 0);
        }
    }
    context->commandRange.range.FUN_00092220(&context->commandWriter->writer);
    if (context->commandRange.range.numElements != 0) {
        appendLinkedRange((*context->commandRanges)[listIndex], context->commandRange,
                          context->commandWriter->writer);
    }
    context->commandRange.range.setStartPoint(&context->commandWriter->writer);
    stream.timerEnd("Et");
    stream.timerEnd("Et");
}
