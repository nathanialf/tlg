/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 336 bytes against 333, every block and loop in place (round
// 75B: the counter declared after the links, so LoopSimplify's
// SeparateNestedLoop partitions on a link's phi and the freed blocks' path is
// the inner loop; the free list walked from a head element on the stack, so
// the walk is one block). Left: one coalescing order. RegisterCoalescer
// (compareMBBPriority, RegisterCoalescer.cpp:1988) takes the outer header's
// copies (three edges, lower number) before the kept path's tail (three
// edges), so the outer block phi joins the inner one and the tail's link copy
// (CodeGenPrepare's zero GEP sunk as a cast to the tail's top) stays; the
// base holds the outcome of the other order (`mov r10, rdi` at 0x18d28, the
// link copied last at 0x18db4), and the element size and product trade rdx
// and rsi with it (docs/NOTES.md, Round 75B).

int FreeList::FUN_00018c90()
{
    if (!activeBlocks) {
        return 0;
    }
    activeBlocks = FUN_000183c0(activeBlocks);

    /* The rest of the current block freed, then the freed elements in
     * address order. */
    Element *head = freeHead;
    for (char *element = top; element < blockEnd; element += elementSize) {
        reinterpret_cast<Element *>(element)->next = head;
        head = reinterpret_cast<Element *>(element);
    }
    freeHead = head;
    top = HK_NULL;
    blockEnd = HK_NULL;
    freeHead = static_cast<Element *>(FUN_00092040(freeHead));

    /* Both lists in address order: the freed elements of each block are a
     * run of the free list; a block covered by its run moves to the free
     * blocks and the run leaves the free list. */
    FreeListBlock *blocks = activeBlocks;
    Element freeElements;
    freeElements.next = freeHead;
    Element *prevElement = &freeElements;
    FreeListBlock **blockLink = &blocks;
    FreeListBlock *block = blocks;
    Element *element = freeElements.next;
    int numFreed = 0;
    while (block) {
        char *start = block->elements;
        char *end = start + block->numElements * elementSize;
        char *cur = start;
        while (cur == reinterpret_cast<char *>(element) && cur < end) {
            cur += elementSize;
            element = element->next;
        }
        if (cur == end) {
            *blockLink = block->next;
            block->next = freeBlocks;
            freeBlocks = block;
            block = *blockLink;
            prevElement->next = element;
            numFreed++;
        } else {
            while (element && reinterpret_cast<char *>(element) < end) {
                element = element->next;
            }
            while (prevElement->next != element) {
                prevElement = prevElement->next;
            }
            blockLink = &block->next;
            block = block->next;
        }
    }
    freeHead = freeElements.next;
    activeBlocks = blocks;
    cursor = HK_NULL;
    return numFreed;
}
