/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkLargeBlockAllocator::FUN_00012410(TreeChunk *chunk, u64 size)
{
    const u32 index = treeIndex(size);
    TreeChunk **bin = &treebins[index];
    chunk->index = index;
    chunk->child[0] = chunk->child[1] = 0;
    if (!(treemap & (1u << index))) {
        treemap |= 1u << index;
        *bin = chunk;
        chunk->parent = reinterpret_cast<TreeChunk *>(bin);
        chunk->prev = chunk->next = chunk;
    } else {
        TreeChunk *t = *bin;
        u64 k = size << leftShiftForTreeIndex(index);
        for (;;) {
            if ((t->head & ~u64(IN_USE_BITS)) != size) {
                TreeChunk **c = &t->child[(k >> 63) & 1];
                k <<= 1;
                if (*c) {
                    t = *c;
                } else {
                    *c = chunk;
                    chunk->parent = t;
                    chunk->prev = chunk->next = chunk;
                    break;
                }
            } else {
                Chunk *f = t->next;
                t->next = f->prev = chunk;
                chunk->next = f;
                chunk->prev = t;
                chunk->parent = 0;
                break;
            }
        }
    }
}
