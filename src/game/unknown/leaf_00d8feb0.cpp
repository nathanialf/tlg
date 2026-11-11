/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a worker of the job FUN_00d8e3d0's function builds (its
 * address taken there, the job's pointers at +0x10 to +0x30 the caller's
 * locals): counts itself in, then takes indices from the shared counter
 * (fetched and decremented atomically) while it was above zero, passes each
 * element below the index to FUN_00c569b0 with 0 and adds the result to the
 * shared total, and counts itself out. */
struct Target00ca2880; /* derived name, as leaf_00ca2880.cpp declares it */

int FUN_00c569b0(Target00ca2880 *target, int value); /* derived name */

struct List00d8feb0 { /* derived name */
    Target00ca2880 **elements;
};

struct Job00d8feb0 { /* derived name */
    u8 unknown0[0x10];
    List00d8feb0 *list; /* +0x10 */
    int *remaining;     /* +0x18 */
    int *finished;      /* +0x20 */
    int *started;       /* +0x28 */
    int *total;         /* +0x30 */
};

// NONMATCHING: tail merging: the base keeps the counter's fetch (`mov eax, -1; mov rcx,
// [r14 + 0x18]; lock xadd`) in the entry and again at the latch, both reaching one test;
// the build merges the two into one block the entry jumps to (also written as an
// explicit rotation: the same IR)
void FUN_00d8feb0(Job00d8feb0 *job) /* derived name */
{
    __sync_fetch_and_add(job->started, 1);
    int index;
    while ((index = __sync_fetch_and_sub(job->remaining, 1)) > 0)
        __sync_fetch_and_add(job->total, FUN_00c569b0(job->list->elements[index - 1], 0));
    __sync_fetch_and_add(job->finished, 1);
}
