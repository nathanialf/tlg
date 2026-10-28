/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The task's work: the world's stage under the timer, the thread's stream
 * read once for its begin and its end. The interface's slot 2 is the
 * this-adjusting thunk with this body inlined. */
void hknpPostSolveTask::process()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StSolve");
    world->FUN_00050fd0();
    stream.timerEndList("lt");
}
