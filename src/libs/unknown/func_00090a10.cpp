/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Under the lock: the freed blocks forgotten (the list back over its own
 * storage), the buffer kept, nothing of it in use or allocated; a null
 * buffer leaves no end. */
void BufferAllocator::FUN_00090a10(void *buffer, int numBytes)
{
    lock.enter();
    freeBlocks.data = freeBlocks.storage;
    freeBlocks.size = 0;
    freeBlocks.capacityAndFlags = 64 | hkArray<FreeBlock>::DONT_DEALLOCATE_FLAG;
    char *const start = static_cast<char *>(buffer);
    bufferStart = start;
    currentEnd = start;
    bufferEnd = start + (start ? numBytes : 0);
    numAllocations = 0;
    lock.leave();
}
