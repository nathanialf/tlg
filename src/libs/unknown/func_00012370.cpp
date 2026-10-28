/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkLargeBlockAllocator::~hkLargeBlockAllocator()
{
    Page *page = pages.next;
    while (page != &pages) {
        Page *next = page->next;
        server->FUN_00008d80(page, page->size);
        page = next;
    }
}
