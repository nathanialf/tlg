/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 7 of PageAllocator's vtable (address point 0x168e8f0)
 * returns the bytes in use, the pages not on the free list times the page
 * size. */
int PageAllocator::FUN_00019b30() const /* derived name */
{
    return (pages.size - freePages.size) * PAGE_SIZE;
}
