/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before
 * their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* What the key query times (derived names): two timers, each its name, the
 * ticks it has counted, whether it is off and how often it ran, then the
 * keys found in all. */
struct KeyQueryTimers00172f60 /* derived name */
{
    struct Timer {
        const char *name;
        u32 ticks;
        int disabled;
        int count;
    };

    Timer queryTimer;
    Timer sortTimer;
    int numKeys;
};

/* The ticks since a start, the counter's wrap allowed for (derived name). */
static inline u32 ticksSince(u32 start)
{
    const u32 now = ThreadBuffer::readTimeStampCounter();
    return start <= now ? now - start : ~start + now;
}

/* derived name: the keys of a shape within a box, the box first made the
 * whole space, gathered by the shape's slot 25 and sorted, each step timed
 * when its timer is on; the number of keys. */
// NONMATCHING: 42 of 160 (size 581 against 604); the sort (explicitStackQuickSort) is the
// base's block for block; left: the timers' arithmetic: the base compares `cmp start, now;
// jbe` and keeps the elapsed ticks in the start's register (ebx), here InstCombine's
// canonical `icmp ult now, start` gives `cmp now, start; jae` and the ticks in eax, and the
// timers pointer is reloaded into r12 after the shape's call where it stays in rcx here.
// NOTES Round 79A.
int FUN_00172f60(const void *argument1, const void *argument2, const void *argument3,
                 const hknpShape *shape, const void *argument5, const void *argument6,
                 hkArray<u32> *keys, hkAabb *aabb, KeyQueryTimers00172f60 *timers)
{
    const int queryTimerDisabled = timers->queryTimer.disabled;
    u32 queryStart;
    if (!queryTimerDisabled) {
        queryStart = ThreadBuffer::readTimeStampCounter();
    }
    aabb->FUN_0014a220();
    shape->unknownVirtual25(argument1, argument2, argument3, argument6, argument5, keys, aabb);
    if (!queryTimerDisabled) {
        timers->queryTimer.ticks += ticksSince(queryStart);
        timers->queryTimer.count++;
    }
    const int numKeys = keys->getSize();
    timers->numKeys += numKeys;
    u32 sortStart;
    if (!timers->sortTimer.disabled) {
        sortStart = ThreadBuffer::readTimeStampCounter();
    }
    hkAlgorithm::explicitStackQuickSort(keys->data, numKeys, hkAlgorithm::less<u32>());
    if (!timers->sortTimer.disabled) {
        timers->sortTimer.ticks += ticksSince(sortStart);
        timers->sortTimer.count++;
    }
    return numKeys;
}
