/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <stdlib.h>

#include "tlg_game_block.h"

/* derived names: an allocation callback (its address at 0x16b71b0 and
 * 0x16d0210, in two vtables; the object it is called on is not read): size
 * bytes at the given alignment from the calling thread's heap, the
 * thread-local at 0x16dc090, set on first use to the first heap of the table
 * at 0x5943280, through the heap's slot 4 with 1 as its last argument (as
 * FUN_001afa60 with its alignment of 32); malloc when there is no heap;
 * nothing (null) for a size of 0. */
extern __thread Owner05943280 *D_16dc090; /* derived name: the calling thread's heap */

void *FUN_0139e0d0(void *, unsigned size, unsigned alignment) /* derived name */
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
    return heap->slot4(size, alignment, 1);
}
