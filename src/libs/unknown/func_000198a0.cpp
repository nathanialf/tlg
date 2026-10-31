/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 5: numPages pages handed out under the lock, from the last free
 * one; when there are too few, pages added first for the shortfall or for
 * slot 9's amount, whichever is more; the peak raised to slot 7's figure. */
void PageAllocator::FUN_000198a0(void **pagesOut, int numPages) /* derived name */
{
    if (numPages == 0) {
        return;
    }
    lock.enter();
    if (freePages.getSize() < numPages) {
        /* At least doubled: the bytes already held, when more. */
        const int bytesHeld = FUN_00019b50();
        const int bytesShort = (numPages - freePages.getSize()) * int(PAGE_SIZE);
        FUN_00019640(bytesShort < bytesHeld ? bytesHeld : bytesShort);
    }
    for (int i = 0; i < numPages; i++) {
        pagesOut[i] = freePages[freePages.getSize() - 1];
        freePages.popBack();
    }
    peakBytesInUse = hkMath::max2(peakBytesInUse, FUN_00019b30());
    lock.leave();
}
