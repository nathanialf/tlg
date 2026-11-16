/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_libc.h"

/* derived names: the allocation of the heap whose vtable is at 0x16b8c00
 * (slot 4, its pointer at 0x16b8c30; Object00ca24c0 of leaf_00ca24c0.cpp,
 * Owner05943280's slot4): nothing for a size of 0; else the size rounded up
 * to the alignment (at least 32) and a 16-byte header before it, from the C
 * library's memalign for an alignment over 32 and from malloc otherwise; the
 * header gets the tag 10, the heap's index in the table at 0x5943280, the
 * rounded size and the size with the header. The flags are unused. */
void *FUN_00ca2540(Owner05943280 *self, unsigned size, unsigned alignment, int) /* derived name */
{
    if (!size)
        return 0;
    unsigned align = alignment > 32 ? alignment : 32;
    unsigned rounded = (size + align - 1) & -align;
    size_t total = rounded + sizeof(BlockHeader05943280);
    void *memory = alignment > 32 ? memalign(align, total) : malloc(total);
    if (!memory)
        return 0;
    BlockHeader05943280 *header = static_cast<BlockHeader05943280 *>(memory);
    header->tag = 10;
    header->owner = self->index;
    header->size = rounded;
    header->total = total;
    return header + 1;
}

/* derived names: the reallocation of the same heap (slot 5, its pointer at
 * 0x16b8c38; Owner05943280's slot5): a size of 0 frees the block; no block is
 * an allocation (slot 4, inlined); a block whose rounded size is the same is
 * kept; else the block with its header is moved by the C library's
 * reallocalign for an alignment over 32 and by realloc otherwise, and the
 * header is written again. */
// NONMATCHING: register assignment only: the base copies the size to eax first and keeps the
// alignment in the copy (rdx, passed to memalign as `mov rdi, rdx`) with the mask negated in
// edi; the build negates the copy and passes `mov edi, edi`
void *FUN_00ca25c0(Owner05943280 *self, void *block, unsigned size, unsigned alignment,
                   int flags) /* derived name */
{
    if (!size) {
        if (block)
            free(static_cast<BlockHeader05943280 *>(block) - 1);
        return 0;
    }
    unsigned align = alignment > 32 ? alignment : 32;
    unsigned rounded = (size + align - 1) & -align;
    if (!block)
        return FUN_00ca2540(self, rounded, alignment, flags);
    BlockHeader05943280 *old = static_cast<BlockHeader05943280 *>(block) - 1;
    if (old->size == rounded)
        return block;
    size_t total = rounded + sizeof(BlockHeader05943280);
    void *memory = alignment > 32 ? reallocalign(old, total, align) : realloc(old, total);
    if (!memory)
        return 0;
    BlockHeader05943280 *header = static_cast<BlockHeader05943280 *>(memory);
    header->tag = 10;
    header->owner = self->index;
    header->size = rounded;
    header->total = total;
    return header + 1;
}
