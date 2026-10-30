/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The owner's step timers written to the stream when it has room: the
 * owner's first commands, two named markers and the two records, then each
 * group's. The stream's limit is read once. */
// NONMATCHING: equal but for the copy of the record at +0xa8, whose address the base
// materializes (`lea rcx, [rbx+0xa8]`, the loads through rcx) where this compile folds it into
// the loads; the record at +0xc0, whose value is tested in an earlier block, comes out as the
// base's (NOTES Round 63B, 64B). Round 64A measured: a reference to the record at +0xa8 bound
// before the first branch gives every instruction (its GEP crosses blocks as +0xc0's does); not
// kept, it exists only to move the address (the crutch test), and a helper taking the record by
// reference changes nothing.
void StepTimers::FUN_0017aeb0(ThreadBuffer &stream)
{
    if (!enabled) {
        return;
    }
    FUN_0017a3c0(this, stream);
    char *const limit = stream.capacityMinus16;
    if (stream.end < limit) {
        TimerMarker *command = reinterpret_cast<TimerMarker *>(stream.end);
        command->commandAndMonitor = "YtSdf";
        stream.end = reinterpret_cast<char *>(command + 1);
    }
    if (timerC0.value) {
        if (stream.end < limit) {
            TimerMarker *command = reinterpret_cast<TimerMarker *>(stream.end);
            command->commandAndMonitor = "YtbuildJac";
            stream.end = reinterpret_cast<char *>(command + 1);
        }
        if (stream.end < limit) {
            TimerRecord *command = reinterpret_cast<TimerRecord *>(stream.end);
            *command = timerC0;
            command->commandAndMonitor = "Wt";
            stream.end = reinterpret_cast<char *>(command + 1);
        }
    }
    if (stream.end < limit) {
        TimerRecord *command = reinterpret_cast<TimerRecord *>(stream.end);
        *command = timerA8;
        command->commandAndMonitor = "Wt";
        stream.end = reinterpret_cast<char *>(command + 1);
    }
    FUN_0017a970(groupD8, stream);
    FUN_0017abe0(group268, stream);
}
