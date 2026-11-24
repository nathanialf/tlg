/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_libc.h"

/* derived names: a block reallocated at 32 bytes' alignment: an existing
 * block tagged 10 goes back to its owner (slot 5) when the owner is set,
 * any other one to the C library's realloc from its header; with none, a new
 * one from the calling thread's heap (allocateBlock) */
void *FUN_00ca21b0(void *block, unsigned size) /* derived name */
{
    if (block) {
        BlockHeader05943280 *header = static_cast<BlockHeader05943280 *>(block) - 1;
        if (header->tag == 10) {
            if (Owner05943280 *owner = D_5943280[header->owner])
                return owner->slot5(block, size, 32, 1);
        }
        return realloc(header, size);
    }
    return allocateBlock(size, 32);
}
