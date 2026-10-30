/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 3: a block's chunk given back, merged with a free neighbour on
 * either side (dlmalloc's free over tree bins only): into the top when the
 * chunk after it is the top, else into its bin; the totals lessened by the
 * chunk and its payload. */
// NONMATCHING (NOTES Round 64B): every block, branch and memory operand is the base's; the
// registers are permuted (the base keeps the pointer in r15, the chunk's size in r14, the
// merged chunk and size in r13 and r12, this compile r12, r13, r15 and rbx).
void hkLargeBlockAllocator::blockFree(void *pointer, int numBytes)
{
    if (!pointer) {
        return;
    }
    Chunk *chunk = reinterpret_cast<Chunk *>(static_cast<char *>(pointer) - sizeof(Chunk));
    u64 size = chunk->head & ~u64(IN_USE_BITS);
    totalBlockBytes -= size;
    totalPayloadBytes -= (chunk->head & ~u64(IN_USE_BITS)) - sizeof(Chunk);
    Chunk *const next = reinterpret_cast<Chunk *>(reinterpret_cast<char *>(chunk) + size);
    if (!(chunk->head & PREVIOUS_IN_USE)) {
        const u64 previousSize = chunk->prevFoot;
        chunk = reinterpret_cast<Chunk *>(reinterpret_cast<char *>(chunk) - previousSize);
        FUN_00012550(static_cast<TreeChunk *>(chunk));
        size += previousSize;
    }
    const u64 nextHead = next->head;
    if (nextHead & IN_USE) {
        next->head = nextHead & ~u64(PREVIOUS_IN_USE);
        chunk->head = size | PREVIOUS_IN_USE;
        reinterpret_cast<Chunk *>(reinterpret_cast<char *>(chunk) + size)->prevFoot = size;
    } else {
        if (next == top) {
            topSize += size;
            top = chunk;
            chunk->head = topSize | PREVIOUS_IN_USE;
            return;
        }
        FUN_00012550(static_cast<TreeChunk *>(next));
        size += nextHead & ~u64(IN_USE_BITS);
        chunk->head = size | PREVIOUS_IN_USE;
        reinterpret_cast<Chunk *>(reinterpret_cast<char *>(chunk) + size)->prevFoot = size;
    }
    FUN_00012410(static_cast<TreeChunk *>(chunk), size);
}
