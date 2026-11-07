/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

bool FUN_00018280(const void *a, const void *b); /* derived name */

/* The free elements that lie in the block taken off the free list into a
 * buffer on the thread's stack, the ones the block has not yet handed out
 * counted with them; when that is all of the block's elements it is free
 * (and no longer the one being handed out), otherwise its free elements go
 * back to the head of the free list sorted by address. */
hkBool32 FreeList::FUN_000189d0(FreeListBlock *block)
{
    LocalBuffer<void *> inBlock(int(block->numElements));
    Element *element = freeHead;
    char *const start = block->elements;
    char *const end = start + block->numElements * elementSize;

    Element **prev = &freeHead;
    int numFound = 0;
    while (element) {
        if (reinterpret_cast<char *>(element) < start || reinterpret_cast<char *>(element) >= end) {
            prev = &element->next;
            element = *prev;
            continue;
        }
        inBlock.data[numFound++] = element;
        *prev = element->next;
        element = element->next;
    }

    if (top >= start && top < end) {
        const int numUnused = int(hkUlong(blockEnd - top) / elementSize);
        if (numFound + numUnused == int(block->numElements)) {
            top = HK_NULL;
            blockEnd = HK_NULL;
            return true;
        }
    } else if (numFound == int(block->numElements)) {
        return true;
    }

    if (numFound > 0) {
        hkAlgorithm::quickSort(inBlock.data, numFound, FUN_00018280);
        Element *link = static_cast<Element *>(inBlock.data[0]);
        for (int i = 1; i < numFound; i++) {
            Element *next = static_cast<Element *>(inBlock.data[i]);
            link->next = next;
            link = next;
        }
        static_cast<Element *>(inBlock.data[numFound - 1])->next = freeHead;
        freeHead = static_cast<Element *>(inBlock.data[0]);
    }
    return false;
}
