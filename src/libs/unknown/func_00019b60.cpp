/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 10: under the lock, every page given back to the thread's heap and
 * none kept, free or not. */
void PageAllocator::FUN_00019b60()
{
    lock.enter();
    for (int i = 0; i < pages.getSize(); i++) {
        FUN_0000bc00(*D_16dc070->temp58, pages[i]);
    }
    pages.clear();
    freePages.clear();
    lock.leave();
}
