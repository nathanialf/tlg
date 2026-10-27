/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the block goes back to the calling thread's temporary
 * allocator at the size it holds. */
void FUN_00199770(SizedBlock00199600 *block)
{
    D_16dc070->temp58->blockFree(block, block->numBytes);
}
