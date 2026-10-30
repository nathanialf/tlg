/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void PageAllocator::FUN_00019640(int numBytes)
{
    const int numPages = int((hkUlong(numBytes) + PAGE_SIZE - 1) / PAGE_SIZE);
    for (int i = 0; i < numPages; i++) {
        Page *page = static_cast<Page *>(FUN_0000bba0(*D_16dc070->temp58, PAGE_SIZE, 128));
        page->allocator = this;
        pages.pushBack(page);
        freePages.pushBack(page);
    }
}
