/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BufferAllocator::FUN_00008d80(void *pointer, int numBytes)
{
    lock.enter();
    numAllocations--;
    char *const start = static_cast<char *>(pointer);
    char *const end = start + numBytes;
    if (end == currentEnd) {
        currentEnd = start;
        while (freeBlocks.getSize() != 0) {
            const FreeBlock &block = freeBlocks[freeBlocks.getSize() - 1];
            if (block.start + block.numBytes != start) {
                break;
            }
            currentEnd = block.start;
            freeBlocks.popBack();
        }
    } else if (freeBlocks.getSize() == 0) {
        freeBlocks.size = 1;
        FreeBlock &block = freeBlocks[0];
        block.start = start;
        block.numBytes = numBytes;
    } else {
        int i = freeBlocks.getSize();
        while (i > 0 && freeBlocks[i - 1].start >= start) {
            i--;
        }
        if (i > 0 && freeBlocks[i - 1].start + freeBlocks[i - 1].numBytes == start) {
            FreeBlock &previous = freeBlocks[i - 1];
            previous.numBytes += numBytes;
            if (i <= freeBlocks.getSize() - 1 && end == freeBlocks[i].start) {
                previous.numBytes += freeBlocks[i].numBytes;
                freeBlocks.removeAtAndCopy(i);
            }
        } else if (i <= freeBlocks.getSize() - 1 && freeBlocks[i].start == end) {
            FreeBlock &next = freeBlocks[i];
            next.numBytes += numBytes;
            next.start = start;
        } else {
            freeBlocks.size++;
            for (int j = freeBlocks.getSize() - 1; j > i; j--) {
                freeBlocks[j] = freeBlocks[j - 1];
            }
            FreeBlock &block = freeBlocks[i];
            block.start = start;
            block.numBytes = numBytes;
        }
    }
    lock.leave();
}
