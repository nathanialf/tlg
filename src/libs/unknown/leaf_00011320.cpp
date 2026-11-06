/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the providers the router's allocators are, stored in the
 * snapshot (the memory system's snapshot, 0xd215). */
void MemorySnapshot00011280::FUN_00011320(int stackId, int tempId, int heapId, int debugId,
                                          int solverId)
{
    this->stackId = stackId;
    this->tempId = tempId;
    this->heapId = heapId;
    this->debugId = debugId;
    this->solverId = solverId;
}
