/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The free count is the freed elements, the rest of the current block and
 * the free blocks' elements; the total is every block's elements; each
 * freed element is aligned and on an element boundary of a block in use. */
// NONMATCHING: 76 of 80, the base's loop shapes: each free element's next
// pointer read before its offset is tested, so the loop's latch is empty and
// LoopRotate folds it into the offset test (simplifyLoopLatch) and leaves the
// walk unrotated, one failure block (docs/NOTES.md, Round 70A). Left: the
// active blocks' sum, whose rotated phis LoopRotate orders pointer first (the
// count's zero copied second, the base the other way), and the totals'
// compare branching to the walk where the base branches to the failure.
// Round 94A (both compilers the same, 5 of 80 by position, four lines by
// alignment): the zero of the free count and of the active sum is copied
// twice (the guard's block and the rotated loop's preheader; the base's one
// zero serves both phis), and the walk's next-pointer load stays in the offset
// test's block where the base keeps it in a latch block of its own, entered by
// `jmp` from the totals' compare.
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

    for (void *element = freeHead; element;) {
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
        const u64 offset = u64(e - block->elements);
        element = *static_cast<void **>(element);
        if (offset % elementSize != 0) {
            return false;
        }
    }
    return true;
}
