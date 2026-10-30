/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 2 (0x8f220): under the lock, a block of the size asked for and its
 * header, rounded up to 16 bytes, drawn from the parent and put at the head
 * of the list; what is drawn and in use counted, the peak kept. */
void *BlockListAllocator::blockAlloc(int numBytes)
{
    lock.enter();
    int size = (numBytes + int(sizeof(Block)) + 15) & ~15;
    Block *block = static_cast<Block *>(parent->blockAlloc(size));
    block->numBytes = numBytes;
    block->size = size;
    block->next = blocks;
    blocks = block;
    void *payload = block + 1;
    statistics.allocated += size;
    statistics.inUse += numBytes;
    statistics.peakInUse = hkMath::max2(statistics.peakInUse, statistics.inUse);
    lock.leave();
    return payload;
}
