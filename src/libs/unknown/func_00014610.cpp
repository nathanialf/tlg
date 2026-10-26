/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void ThreadMemory::FUN_00014610(AllocatorBase *memory, int maxNumElemsOnFreeList)
{
    if (memory) {
        this->memory = memory;
        this->maxNumElemsOnFreeList = maxNumElemsOnFreeList;
    } else {
        this->memory = 0;
    }
}
