/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 8 of AllocatorBase, kept by Allocator0000ed40 and
 * eight other allocator vtables: a batch freed block by block, null slots
 * skipped. */
void AllocatorBase::blockFreeBatch(void **blocks, int numBlocks, int blockSize)
{
    for (int i = 0; i < numBlocks; ++i) {
        if (blocks[i]) {
            blockFree(blocks[i], blockSize);
        }
    }
}
