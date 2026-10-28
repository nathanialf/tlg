/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void ThreadMemory::blockAllocBatch(void **blocksOut, int numBlocks, int blockSize)
{
    if (blockSize <= MAX_ROW_SIZE) {
        for (int i = 0; i < numBlocks; i++) {
            blocksOut[i] = blockAlloc(blockSize);
        }
    } else {
        memory->blockAllocBatch(blocksOut, numBlocks, blockSize);
    }
}
