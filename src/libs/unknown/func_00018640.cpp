/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

FreeList::FreeList()
    : freeHead(0), elementSize(0), unknown18(0), unknown20(0), unknown28(0), unknown30(0), top(0),
      blockEnd(0), unknown50(0), unknown58(0), unknown60(0), numFreeElements(0)
{
}
