/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <stdlib.h>

#include "tlg_game_block.h"

/* derived names: the first four of the eight functions of the table at
 * 0x168c118 (after its size, 0x70, and the 2 at 0x168c110; the next four,
 * 0x1afc60 to 0x1afd20, are 0x3f bytes each): four identical allocations of
 * size bytes aligned to 32 from the calling thread's heap, the thread-local
 * at 0x16dc090 (tp -64), set on first use to the first heap of the table at
 * 0x5943280, through the heap's slot 4 with 1 as its last argument; malloc
 * when there is no heap; nothing (null) for a size of 0. The size is tested
 * and passed as 32 bits though the register is kept whole (`mov r14, rdi;
 * test r14d, r14d`): the entries take a 64-bit size and the allocation a
 * 32-bit one. Any argument after the size is not read. */

static inline void *allocate(unsigned size) /* derived name */
{
    if (!size)
        return 0;
    Owner05943280 *heap = D_16dc090;
    if (!heap) {
        heap = D_5943280[0];
        D_16dc090 = heap;
        if (!heap)
            return malloc(size);
    }
    return heap->slot4(size, 0x20, 1);
}

void *FUN_001afa60(size_t size) /* derived name */
{
    return allocate(size);
}

void *FUN_001afae0(size_t size) /* derived name */
{
    return allocate(size);
}

void *FUN_001afb60(size_t size) /* derived name */
{
    return allocate(size);
}

void *FUN_001afbe0(size_t size) /* derived name */
{
    return allocate(size);
}
