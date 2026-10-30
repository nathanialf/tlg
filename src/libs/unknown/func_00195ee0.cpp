/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: equal to the free list's fill; the base's loop keeps the value as an induction
// variable of its own (`dec ecx; cmp ecx, -1`, the index in rax), this compile computes it from
// the index (`mov ecx, 0x7f; sub ecx, eax`, the exit on the index) (NOTES Round 63B).
BroadPhaseTree00142a40::BroadPhaseTree00142a40(int maxLeafEntries) : maxLeafEntries(maxLeafEntries)
{
    root = Node::NO_CHILD;
    numLeaves = 0;
    numEntries = 0;
    freeBuckets.setSize(128);
    buckets.setSize(128);
    for (int i = 0; i < 128; i++) {
        freeBuckets[i] = 128 - 1 - i;
    }
}
