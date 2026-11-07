/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Under the lock, while the freed blocks' storage could still take one more
 * block back: the smallest freed block that fits, scanned from the last,
 * handed out whole (the caller told its real size) unless the size must be
 * exact or the block is more than half again too large for a request over
 * 1 KiB, in which case the request is cut from its start; with none, the
 * request cut from the buffer's unused end. The allocations counted and the
 * peak use kept. */
void *BufferAllocator::FUN_00090b70(int &numBytesInOut, bool exactSize)
{
    lock.enter();
    void *block = HK_NULL;
    if (numAllocations + 1 < 2 * freeBlocks.getCapacity() - freeBlocks.getSize()) {
        const int numBytes = numBytesInOut;
        int bestSize = 0x7ffffff;
        int bestIndex = -1;
        for (int i = freeBlocks.getSize() - 1; i >= 0; i--) {
            const int size = freeBlocks.data[i].numBytes;
            if (size >= numBytes && size < bestSize) {
                bestSize = size;
                bestIndex = i;
            }
        }
        if (bestIndex < 0) {
            if (int(bufferEnd - currentEnd) >= numBytes) {
                block = currentEnd;
                currentEnd += numBytes;
                numBytesInOut = numBytes;
                numAllocations++;
                const hkUlong use = currentEnd - bufferStart;
                if (use > peakUse) {
                    peakUse = use;
                }
            }
        } else {
            FreeBlock &freeBlock = freeBlocks.data[bestIndex];
            block = freeBlock.start;
            if ((bestSize != numBytes && exactSize) ||
                (2 * bestSize > 3 * numBytes && numBytes > 1024)) {
                numBytesInOut = numBytes;
                freeBlock.numBytes -= numBytes;
                freeBlock.start += numBytes;
            } else {
                numBytesInOut = freeBlock.numBytes;
                freeBlocks.removeAtAndCopy(bestIndex);
            }
            numAllocations++;
            const hkUlong use = currentEnd - bufferStart;
            if (use > peakUse) {
                peakUse = use;
            }
        }
    }
    lock.leave();
    return block;
}
