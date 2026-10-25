/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 9 of the vtable at 0x168e8f0, a reference-counted
 * allocator of 4096-byte pages (constructor FUN_000195c0: a lock at +0x10,
 * an array of every page at +0x20, an array of free pages at +0x30;
 * FUN_00019640 allocates the pages, 128-byte aligned, and adds each to both
 * arrays). It returns the bytes held, the page count times the page size. */
class PageAllocator00019b50 /* derived name */
{
  public:
    enum { PAGE_SIZE = 4096 }; /* derived name */

    virtual ~PageAllocator00019b50();

    int FUN_00019b50() const; /* vtable slot 9; derived name */

    u8 unknown8[0x18];
    hkArray<void *> pages;     /* derived name */
    hkArray<void *> freePages; /* derived name */
};

int PageAllocator00019b50::FUN_00019b50() const /* derived name */
{
    return pages.size * PAGE_SIZE;
}
