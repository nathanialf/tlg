/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 5 of hknpSolverStageTask's vtable: under the timer, a
 * context taken from the world's pool runs the task's current stage and
 * sub-stage, the task steps on to the next, and the context goes back. */
void FUN_0018ef40(hknpSolverStageTask *self)
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StSolve");
    hknpWorldContextPool *pool = self->stages->contextPool;
    hknpWorldContextPool::Context *context = pool->FUN_0016ff90();
    context->solverStages = self->stages;
    FUN_0018f030(context, self->stages, self->stage, self->subStage, context->index, &self->info);
    if (self->subStage == self->stages->config->numSubStages - 1) {
        self->subStage = 0;
        self->stage++;
    } else {
        self->subStage++;
    }
    pool->FUN_0016ffe0(context);
    stream.timerEndList("lt");
}
