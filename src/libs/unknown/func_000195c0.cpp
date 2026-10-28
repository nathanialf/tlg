/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

PageAllocator::PageAllocator(int initialBytes) : lock(0), peakBytesInUse(0)
{
    if (initialBytes > 0) {
        FUN_00019640(initialBytes);
    }
}
