/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

FreeList::FreeList()
    : freeHead(0), elementSize(0), activeBlocks(0), freeBlocks(0), blockSize(0), unknown30(0),
      top(0), blockEnd(0), blockAllocator(0), elementAllocator(0), totalNumElements(0),
      numFreeElements(0)
{
}
