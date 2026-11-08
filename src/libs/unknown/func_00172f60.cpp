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

/* The ticks from a start to a later reading, the counter's wrap allowed
 * for (derived name). */
static inline u32 ticksBetween(u32 start, u32 now)
{
    return start > now ? ~start + now : now - start;
}

/* derived name: the keys of a shape within a box, the box first made the
 * whole space, gathered by the shape's slot 25 and sorted, each step timed
 * when its timer is on; the number of keys. */
// NONMATCHING: 60 of 160 (size 584 against 604); the sort (explicitStackQuickSort) and the
// timers' arithmetic are the base's (the ticks' helper takes the reading as a parameter, so
// InstCombine's complexity rule keeps `start > now` with its operands, cmp start, now; a
// helper reading the counter itself has an argument against an instruction and swaps them).
// Left: the timers pointer, reloaded from its stack argument into r12 after the shape's call
// in the base, held in rcx here; and the sort timer's flag, loaded into ecx and tested in the
// base (both reads, 0x173029 and 0x173169), folded into `cmp [rcx+0x24], 0` here. NOTES Round
// 79A and Round 80A.
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
        timers->queryTimer.ticks += ticksBetween(queryStart, ThreadBuffer::readTimeStampCounter());
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
        timers->sortTimer.ticks += ticksBetween(sortStart, ThreadBuffer::readTimeStampCounter());
        timers->sortTimer.count++;
    }
    return numKeys;
}
