/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Object00015700::FUN_00015ae0()
{
    lock.enter();
    Block *block = firstBlock;
    freeEntries = reinterpret_cast<Entry *>(block);
    while (block) {
        for (int i = 0; i < 63; i++) {
            block->entries[i].values.clearAndDeallocate();
        }
        Block *nextBlock = block->next;
        new (block) Block();
        if (nextBlock) {
            block->next = nextBlock;
            block->entries[62].next = &nextBlock->entries[0];
        }
        block = nextBlock;
    }
    lock.leave();
}
