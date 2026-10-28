/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: waits on two vtable rows (D14): the destructors (0x12370, its
// deleting form 0x12270 with the allocators' empty delete, and the second
// base's thunk 0x122f0) store LargeBlockAllocator's vtables 0x168e290 and
// 0x168e350 (address points 0x168e2a0 and 0x168e360), which neither vtables
// file names (docs/NOTES.md Round 47).
LargeBlockAllocator::~LargeBlockAllocator()
{
    Page *page = pages.next;
    while (page != &pages) {
        Page *next = page->next;
        server->FUN_00008d80(page, page->size);
        page = next;
    }
}
