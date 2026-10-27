/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"
#include "tlg_lib_unknown.h"

/* derived name: slot 2 of the system heap allocator's vtable (0x168ca00)
 * allocates a block: the size joins the bytes in use (an atomic addition,
 * since any thread may allocate), the peak follows, then the C library
 * allocates at the allocator's alignment. */
void *hkMallocAllocator::blockAlloc(int numBytes)
{
    if (__sync_add_and_fetch(&bytesInUse, numBytes) > peakInUse) {
        peakInUse = bytesInUse;
    }
    return memalign(alignment, numBytes);
}
