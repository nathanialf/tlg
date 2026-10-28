/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: waits on a vtable row (D14): the constructor stores the page
// allocator's vtable 0x168e8e0, which neither vtables file names
// (docs/NOTES.md Round 47); every instruction else is the base's.
PageAllocator::PageAllocator(int initialBytes) : lock(0), peakBytesInUse(0)
{
    if (initialBytes > 0) {
        FUN_00019640(initialBytes);
    }
}
