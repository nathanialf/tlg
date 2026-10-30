/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 13: every block the free lists keep given back to the allocator the
 * thread draws from, the last row first, four at a time. */
void ThreadMemory::FUN_00014690()
{
    for (int row = 16 - 1; row >= 0; row--) {
        FreeList &list = freeLists[row];
        int numElem = list.numElem;
        if (numElem) {
            const int blockSize = rowToSize[row];
            while (numElem > 0) {
                const int numBlocks = numElem > 4 ? 4 : numElem;
                void *blocks[4];
                for (int i = 0; i < numBlocks; i++) {
                    blocks[i] = list.pop();
                }
                memory->blockFreeBatch(blocks, numBlocks, blockSize);
                numElem -= numBlocks;
            }
        }
    }
}
