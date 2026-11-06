/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the current block's rest freed (the loop before the second
// sort) keeps the head in the other registers, and the walk's register
// assignment follows. Equal (measured on a scratch copy of the headers) with
// FreeList's free head typed as Havok's element, `struct Element { Element
// *next; }; Element *freeHead;`, the loop storing `reinterpret_cast<Element
// *>(element)->next = head` and `head = reinterpret_cast<Element *>(element)`:
// the phi then takes a bitcast of the element, which isel exports as its own
// copy (`mov rdi, rax` before the compare). Not applied: the type change
// breaks func_00018c90.cpp, a file of round 75A's queue (NOTES, round 74B).
void FreeList::FUN_00018df0(MemoryWalkCallback callback, int pool, void *param)
{
    /* The free blocks' elements are all free. */
    for (FreeListBlock *block = freeBlocks; block != HK_NULL; block = block->next) {
        char *const end = block->elements + block->numElements * elementSize;
        for (char *element = block->elements; element < end; element += elementSize) {
            callback(element, elementSize, false, pool, param);
        }
    }

    if (activeBlocks == HK_NULL && freeHead == HK_NULL) {
        return;
    }

    /* The blocks in use and the free elements sorted by address, the rest
     * of the current block freed first, so one walk of both tells each
     * element's state. */
    activeBlocks = FUN_000183c0(activeBlocks);
    char *element = top;
    void *head = freeHead;
    while (element < blockEnd) {
        *reinterpret_cast<void **>(element) = head;
        head = element;
        element += elementSize;
    }
    freeHead = head;
    blockEnd = HK_NULL;
    top = HK_NULL;
    freeHead = FUN_00092040(freeHead);

    /* The free elements link through their first word. */
    void **nextFree = static_cast<void **>(freeHead);
    for (FreeListBlock *block = activeBlocks; block != HK_NULL; block = block->next) {
        char *const end = block->elements + block->numElements * elementSize;
        for (char *element = block->elements; element < end; element += elementSize) {
            if (element == static_cast<void *>(nextFree)) {
                callback(element, elementSize, false, pool, param);
                nextFree = static_cast<void **>(*nextFree);
            } else {
                callback(element, elementSize, true, pool, param);
            }
        }
    }
}
