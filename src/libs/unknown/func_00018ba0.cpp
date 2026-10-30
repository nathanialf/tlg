/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The block after the cursor is examined and unlinked when its elements
 * are all free, from the head of the blocks in use when there is no cursor;
 * an unlinked block goes to the free blocks, a kept one becomes the
 * cursor. */
bool FreeList::FUN_00018ba0(int numBlocks, int &numBlocksOut)
{
    int i = 0;
    for (; i < numBlocks; i++) {
        FreeListBlock *block;
        hkBool32 isFree;
        if (cursor == HK_NULL) {
            block = activeBlocks;
            if (!block) {
                numBlocksOut = i;
                cursor = HK_NULL;
                return true;
            }
            isFree = FUN_000189d0(block);
            if (isFree) {
                activeBlocks = block->next;
            }
        } else {
            block = cursor->next;
            if (!block) {
                numBlocksOut = i;
                cursor = HK_NULL;
                return true;
            }
            isFree = FUN_000189d0(block);
            if (isFree) {
                cursor->next = block->next;
            }
        }
        if (isFree) {
            block->next = freeBlocks;
            freeBlocks = block;
        } else {
            cursor = block;
        }
    }
    numBlocksOut = i;
    return cursor == HK_NULL;
}
