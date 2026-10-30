/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The free count is the freed elements, the rest of the current block and
 * the free blocks' elements; the total is every block's elements; each
 * freed element is aligned and on an element boundary of a block in use. */
// NONMATCHING: equal up to the free-element loop (NOTES Round 63B, 64B): the base enters it at
// one test block shared by the entry and the latch (`mov al, 1; test r11, r11; je ret`), every
// failure in one `xor al, al` block; here SimplifyCFG folds the loop guard into the count's
// compare (FoldBranchToCommonDest, sete) and the returns are duplicated.
bool FreeList::FUN_000188c0() const
{
    u64 numFree = 0;
    for (void *element = freeHead; element; element = *static_cast<void **>(element)) {
        numFree++;
    }
    numFree += u64(blockEnd - top) / elementSize;
    for (FreeListBlock *block = freeBlocks; block; block = block->next) {
        numFree += block->numElements;
    }
    if (numFree != u64(numFreeElements)) {
        return false;
    }

    u64 numActive = 0;
    for (FreeListBlock *block = activeBlocks; block; block = block->next) {
        numActive += block->numElements;
    }
    u64 numInFree = 0;
    for (FreeListBlock *block = freeBlocks; block; block = block->next) {
        numInFree += block->numElements;
    }
    if (numInFree + numActive != totalNumElements) {
        return false;
    }

    for (void *element = freeHead; element; element = *static_cast<void **>(element)) {
        if (hkUlong(element) & (unknown30 - 1)) {
            return false;
        }
        const char *e = static_cast<const char *>(element);
        FreeListBlock *block = activeBlocks;
        for (; block; block = block->next) {
            if (e >= block->elements && e < block->elements + block->numElements * elementSize) {
                break;
            }
        }
        if (!block) {
            return false;
        }
        if (u64(e - block->elements) % elementSize != 0) {
            return false;
        }
    }
    return true;
}
