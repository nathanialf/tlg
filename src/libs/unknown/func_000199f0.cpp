/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 6: pages given back, each one that is set put on the free list
 * under the lock. */
void PageAllocator::FUN_000199f0(void *const *pages, int numPages) /* derived name */
{
    if (numPages == 0) {
        return;
    }
    lock.enter();
    for (int i = 0; i < numPages; i++) {
        if (pages[i]) {
            freePages.pushBack(pages[i]);
        }
    }
    lock.leave();
}
