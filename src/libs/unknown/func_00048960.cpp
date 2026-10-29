/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The task's work: the world's stage after the collide tasks under the
 * timer, its stage number set first. The interface's slot 2 is the
 * this-adjusting thunk with this body inlined. */
void hknpPostCollideTask::process()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    world->simulationStage = 8;
    world->FUN_000505f0();
    stream.timerEndList("lt");
}
