/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 113 of 121, 512 bytes as the base: the entries' clearing loop
// keeps its count in eax and the byte offset in ecx in the base (0x16fd82),
// the other way here (the loop's two induction values, IVUsers' order); the
// entry's own references and direct indexing compile the same or worse
// (docs/NOTES.md, Round 75B).
void hknpWorldContextPool::FUN_0016fcb0(hknpWorld *world, const Counts &counts,
                                        BlockStreamAllocator *allocator)
{
    const int numFirst = counts.numUsed0; /* derived name */
    int numContexts = counts.numUsed4;    /* derived name */
    numUsed0 = numFirst;
    numUsed4 = counts.numUsed4;

    cellPairEntries.setSize(world->spaceSplitter->numCellPairs);
    for (int i = 0; i < cellPairEntries.getSize(); i++) {
        cellPairEntries[i].range.startBlock = 0;
        cellPairEntries[i].range.numElements = 0;
        cellPairEntries[i].next = 0;
    }

    numContexts += numFirst;
    for (int i = 0; i < numContexts; i++) {
        contexts[i].FUN_00167d50(world, &cellPairEntries, allocator, i < counts.numUsed0,
                                 world->enabled278);
        contexts[i].index = i;
    }

    for (int i = 0; i < 7; i++) {
        next[i] = i + 1;
    }
    next[7] = 0xf;
    freeHead = 0;
    cache = HK_NULL;
}
