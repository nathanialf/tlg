/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 15 of 120, 422 bytes against 333 (no stack guard, as the base:
// the two links' locals reach only phis). The base nests the block walk
// with the freed blocks' path as the inner loop (its header reloads the
// element size, 0x18d30) and the kept blocks' path as the outer one
// (0x18d28); LoopSimplify::SeparateNestedLoop partitions by the first header
// phi with a self-incoming value (LoopSimplify.cpp FindPHIToPartitionLoops),
// and this compile's choice nests the other way and hoists the size out of
// the inner loop (docs/NOTES.md, Round 67A).

int FreeList::FUN_00018c90()
{
    if (!activeBlocks) {
        return 0;
    }
    activeBlocks = FUN_000183c0(activeBlocks);

    /* The rest of the current block freed, then the freed elements in
     * address order. */
    void *head = freeHead;
    for (char *element = top; element < blockEnd; element += elementSize) {
        *reinterpret_cast<void **>(element) = head;
        head = element;
    }
    freeHead = head;
    top = HK_NULL;
    blockEnd = HK_NULL;
    freeHead = FUN_00092040(freeHead);

    /* Both lists in address order: the freed elements of each block are a
     * run of the free list; a block covered by its run moves to the free
     * blocks and the run leaves the free list. */
    int numFreed = 0;
    FreeListBlock *blocks = activeBlocks;
    void *freeElements = freeHead;
    FreeListBlock **blockLink = &blocks;
    void **elementLink = &freeElements;
    FreeListBlock *block = blocks;
    void *element = freeElements;
    while (block) {
        char *start = block->elements;
        char *end = start + block->numElements * elementSize;
        char *cur = start;
        while (cur == element && cur < end) {
            cur += elementSize;
            element = *static_cast<void **>(element);
        }
        if (cur == end) {
            *blockLink = block->next;
            block->next = freeBlocks;
            freeBlocks = block;
            block = *blockLink;
            *elementLink = element;
            numFreed++;
        } else {
            while (element && element < end) {
                element = *static_cast<void **>(element);
            }
            while (*elementLink != element) {
                elementLink = static_cast<void **>(*elementLink);
            }
            blockLink = &block->next;
            block = block->next;
        }
    }
    freeHead = freeElements;
    activeBlocks = blocks;
    cursor = HK_NULL;
    return numFreed;
}
