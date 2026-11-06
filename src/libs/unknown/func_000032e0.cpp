/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 14 of TwoBaseAllocator's vtable (interface slot 3, through the thunk
 * 0x3490): under the lock, at least one block examined, the free lists
 * collected in turn from where the last call stopped, each list's walk
 * moving on to the next list when it comes to its end, until the blocks are
 * spent or the walk is back at the list it started from; the bytes counted
 * from each list's free count before and after; then the allocator below
 * collected the same way. */
void TwoBaseAllocator::FUN_000032e0(int numBlocks)
{
    criticalSection.enter();
    int numBlocksLeft = hkMath::max2(1, numBlocks);
    const int startIndex = incrementalFreeListIndex;
    int index = startIndex;
    int nextIndex;
    do {
        FreeList *freeList = freeLists[index];
        const s64 numFreeBefore = freeList->numFreeElements;
        int numExamined;
        if (freeList->FUN_00018ba0(numBlocksLeft, numExamined)) {
            nextIndex = index + 1;
            if (nextIndex >= numFreeLists) {
                nextIndex = 0;
            }
        } else {
            nextIndex = index;
        }
        freeList->FUN_00019190();
        numBlocksLeft -= numExamined;
        baseBytes += (freeList->numFreeElements - numFreeBefore) * freeList->elementSize;
        index = nextIndex;
    } while (numBlocksLeft > 0 && nextIndex != startIndex);
    incrementalFreeListIndex = nextIndex;
    if (allocator38) {
        allocator38->FUN_000032e0(numBlocks);
    }
    criticalSection.leave();
}
