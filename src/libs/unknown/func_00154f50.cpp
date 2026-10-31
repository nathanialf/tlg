/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 5 under the collide timer: the world's constraints gathered, then
 * grouped, their count recorded as a monitor value. The interface's thunk
 * (0x1550b0, a jump) is emitted with it. */
void hknpPrepareConstraintsTask::process()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    stream.timerBeginList("LtPrepareConstraints", "StGather");
    hknpWorld *world = static_cast<hknpWorld *>(unknown18);
    hknpConstraint *constraints = world->constraintManager.constraints;
    gather()->FUN_000c5e30(world, constraints, world->constraintManager.peakConstraintId + 1);
    stream.timerSplitList("StGroup");
    groups()->FUN_000c6630(world, gather(), 0, gather()->numEntries10 - 1, constraints);
    /* The count read once the command is named, as the monitor's value
     * macro writes it (the name stored before the count is loaded). */
    if (stream.end < stream.capacityMinus16) {
        ThreadBuffer::AddValueCommand *command =
            reinterpret_cast<ThreadBuffer::AddValueCommand *>(stream.end);
        command->commandAndMonitor = "MiNumConstraints";
        command->value = float(gather()->numConstraints);
        stream.end = reinterpret_cast<char *>(command + 1);
    }
    stream.timerEndList("lt");
    stream.timerEndList("lt");
}
