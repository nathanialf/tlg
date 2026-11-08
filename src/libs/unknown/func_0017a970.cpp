/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A marker written to the stream when it has room (derived name). */
static inline void addMarker(ThreadBuffer &stream, const char *name)
{
    if (stream.end < stream.capacityMinus16) {
        TimerMarker *command = reinterpret_cast<TimerMarker *>(stream.end);
        command->commandAndMonitor = name;
        stream.end = reinterpret_cast<char *>(command + 1);
    }
}

/* A count written as a value when it is not zero and the stream has room
 * (derived name): the count read again for the value, after the name is
 * written. */
static inline void addCount(ThreadBuffer &stream, const char *name, const u32 &count)
{
    if (count) {
        if (stream.end < stream.capacityMinus16) {
            ThreadBuffer::AddValueCommand *command =
                reinterpret_cast<ThreadBuffer::AddValueCommand *>(stream.end);
            command->commandAndMonitor = name;
            command->value = float(count);
            stream.end = reinterpret_cast<char *>(command + 1);
        }
    }
}

/* A timer's record copied into the stream as a "Wt" command when it has
 * room (derived name). */
static inline void addTimer(ThreadBuffer &stream, const TimerRecord &timer)
{
    if (stream.end < stream.capacityMinus16) {
        TimerRecord *command = reinterpret_cast<TimerRecord *>(stream.end);
        *command = timer;
        command->commandAndMonitor = "Wt";
        stream.end = reinterpret_cast<char *>(command + 1);
    }
}

/* derived name: the convex against composite timers written when they ran:
 * the box query with its hits and sort, the contact cache's reuse and
 * check with their counts, the timers after them, then the whole. */
// NONMATCHING: 31 of 164 (626 bytes against 622): the commands are the base's; left, the
// stream's limit: the base reads it again only after the first marker and after the sort's
// (`mov rcx, [rbx+0x18]` at 0x17a9a7 and 0x17aa0c) and compares the others against the value
// it holds, where each room test here reads it after the last store (no strict aliasing); the
// sibling 0x17aeb0 reads it once for all. Which of the tests share one read is the question.
// NOTES Round 79A.
void FUN_0017a970(const CompositeTimers0017a970 &timers, ThreadBuffer &stream)
{
    if (!timers.total.value) {
        return;
    }
    addMarker(stream, "YtCvxVsComposite");
    addMarker(stream, "YtQueryAabb");
    addCount(stream, "MinumHits", timers.numHits);
    if (timers.sort.value) {
        addMarker(stream, "Ytsort");
        addTimer(stream, timers.sort);
    }
    addTimer(stream, timers.queryAabb);
    if (timers.reuseContactCache.value) {
        addMarker(stream, "YtreuseContactCache");
        addCount(stream, "MicompositeNumCachesReused", timers.numCachesReused);
        addTimer(stream, timers.reuseContactCache);
    }
    addMarker(stream, "YtcheckContactCache");
    addCount(stream, "MimaxRotationExceeded", timers.numMaxRotationExceeded);
    addCount(stream, "MimaxPositionExceeded", timers.numMaxPositionExceeded);
    addTimer(stream, timers.checkContactCache);
    FUN_0017a680(const_cast<u8 *>(timers.unknown90), stream);
    addTimer(stream, timers.total);
}
