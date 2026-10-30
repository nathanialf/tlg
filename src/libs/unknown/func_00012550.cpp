/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkLargeBlockAllocator::FUN_00012550(TreeChunk *chunk)
{
    TreeChunk *parent = chunk->parent;
    TreeChunk *replacement;
    if (chunk->prev != chunk) {
        Chunk *next = chunk->next;
        replacement = static_cast<TreeChunk *>(chunk->prev);
        next->prev = replacement;
        replacement->next = next;
    } else {
        TreeChunk **link;
        if (((replacement = *(link = &chunk->child[1])) != HK_NULL) ||
            ((replacement = *(link = &chunk->child[0])) != HK_NULL)) {
            TreeChunk **childLink;
            while ((*(childLink = &replacement->child[1]) != HK_NULL) ||
                   (*(childLink = &replacement->child[0]) != HK_NULL)) {
                replacement = *(link = childLink);
            }
            *link = HK_NULL;
        }
    }
    if (parent != HK_NULL) {
        TreeChunk **bin = &treebins[chunk->index];
        if (chunk == *bin) {
            if ((*bin = replacement) == HK_NULL) {
                treemap &= ~(1u << chunk->index);
            }
        } else {
            if (parent->child[0] == chunk) {
                parent->child[0] = replacement;
            } else {
                parent->child[1] = replacement;
            }
        }
        if (replacement != HK_NULL) {
            replacement->parent = parent;
            TreeChunk *child0 = chunk->child[0];
            if (child0 != HK_NULL) {
                replacement->child[0] = child0;
                child0->parent = replacement;
            }
            TreeChunk *child1 = chunk->child[1];
            if (child1 != HK_NULL) {
                replacement->child[1] = child1;
                child1->parent = replacement;
            }
        }
    }
}
