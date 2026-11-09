/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The Sdf section (derived name, after its marker): the marker, the
 * Jacobians' build under its own marker when its value is set, then the
 * section's whole. */
static inline void writeSdfTimers(ThreadBuffer &stream, char *const limit, /* derived name */
                                  const TimerRecord &total, const TimerRecord &buildJac)
{
    if (stream.end < limit) {
        TimerMarker *command = reinterpret_cast<TimerMarker *>(stream.end);
        command->commandAndMonitor = "YtSdf";
        stream.end = reinterpret_cast<char *>(command + 1);
    }
    if (buildJac.value) {
        if (stream.end < limit) {
            TimerMarker *command = reinterpret_cast<TimerMarker *>(stream.end);
            command->commandAndMonitor = "YtbuildJac";
            stream.end = reinterpret_cast<char *>(command + 1);
        }
        if (stream.end < limit) {
            TimerRecord *command = reinterpret_cast<TimerRecord *>(stream.end);
            *command = buildJac;
            command->commandAndMonitor = "Wt";
            stream.end = reinterpret_cast<char *>(command + 1);
        }
    }
    if (stream.end < limit) {
        TimerRecord *command = reinterpret_cast<TimerRecord *>(stream.end);
        *command = total;
        command->commandAndMonitor = "Wt";
        stream.end = reinterpret_cast<char *>(command + 1);
    }
}

/* The owner's step timers written to the stream when it has room: the
 * owner's first commands, the Sdf section with its two records, then each
 * group's. The stream's limit is read once. */
void StepTimers::FUN_0017aeb0(ThreadBuffer &stream)
{
    if (!enabled) {
        return;
    }
    FUN_0017a3c0(convex, stream);
    writeSdfTimers(stream, stream.capacityMinus16, sdfTimer, buildJacTimer);
    FUN_0017a970(groupD8, stream);
    FUN_0017abe0(group268, stream);
}
