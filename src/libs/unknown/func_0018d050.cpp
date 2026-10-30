/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BroadPhaseUpdateTask0018d050::FUN_0018d050() /* derived name */
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    stream.timerBegin("TtBroadPhase");
    data->bodyManager->FUN_001612a0();
    FUN_00141500(data->layers, data->bodyManager->bodies.data);
    stream.timerEnd("Et");
    stream.timerEndList("lt");
}
