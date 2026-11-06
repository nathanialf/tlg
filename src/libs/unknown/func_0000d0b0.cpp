/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The free-list memory system's snapshot (slot 18): the system's provider,
 * the buffer allocator's buffer recorded for it and for the solver's, the
 * allocator interface's own record under the system, then each block the
 * block-list allocator drew, for the system and as the debug allocator's
 * header, payload and slack. */
hkResult hkFreeListMemorySystem::getMemorySnapshot(MemorySnapshot00011280 &snapshot) const
{
    if (!extended20) {
        return HK_FAILURE;
    }
    const int systemId = snapshot.FUN_00011170("<System>", -1);
    const int solverId = snapshot.FUN_00011170("hkSolverAllocator(Solver)", systemId);
    snapshot.FUN_00011280(systemId, MemorySnapshot00011280::STATUS_USED,
                          bufferAllocator.bufferStart,
                          int(bufferAllocator.bufferEnd - bufferAllocator.bufferStart));
    snapshot.FUN_00011280(solverId, MemorySnapshot00011280::STATUS_USED,
                          bufferAllocator.bufferStart,
                          int(bufferAllocator.bufferEnd - bufferAllocator.bufferStart));
    const int heapId = extended20->addToSnapshot(&snapshot, systemId);
    if (heapId == -1) {
        return HK_FAILURE;
    }
    const int debugId = snapshot.FUN_00011170("hkRecallAllocator(Debug)", systemId);
    for (const BlockListAllocator::Block *block = blockListAllocator.blocks; block;
         block = block->next) {
        snapshot.FUN_00011280(systemId, MemorySnapshot00011280::STATUS_USED, block, block->size);
        snapshot.FUN_00011280(debugId, MemorySnapshot00011280::STATUS_OVERHEAD, block,
                              sizeof(BlockListAllocator::Block));
        const void *payload = hkAddByteOffsetConst(block, sizeof(BlockListAllocator::Block));
        snapshot.FUN_00011280(debugId, MemorySnapshot00011280::STATUS_USED, payload,
                              block->numBytes);
        const void *slack = hkAddByteOffsetConst(payload, block->numBytes);
        const void *end = hkAddByteOffsetConst(block, block->size);
        if (slack != end) {
            snapshot.FUN_00011280(debugId, MemorySnapshot00011280::STATUS_OVERHEAD, slack,
                                  int(hkUlong(end) - hkUlong(slack)));
        }
    }
    snapshot.FUN_00011320(heapId, heapId, heapId, debugId, solverId);
    return HK_SUCCESS;
}
