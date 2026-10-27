/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 10 of the thread's allocator's vtable (address point
 * 0x168e470): a request a row serves is asked of the allocator below at
 * the row's block size, a larger one as it is. */
int ThreadMemory::getAllocatedSize(const void *pointer, int numBytes) const
{
    if (numBytes <= MAX_ROW_SIZE) {
        numBytes = rowToSize[getRow(numBytes)];
    }
    return memory->getAllocatedSize(pointer, numBytes);
}
