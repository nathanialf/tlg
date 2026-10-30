/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FreeList::FUN_00018770()
{
    giveBackBlocks(activeBlocks);
    activeBlocks = 0;
    giveBackBlocks(freeBlocks);
    freeBlocks = 0;
    freeHead = 0;
    blockSize = 0;
    numFreeElements = 0;
    totalNumElements = 0;
    cursor = 0;
    blockEnd = 0;
    top = 0;
}
