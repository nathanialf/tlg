/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: the twelfth and last function of the table at 0x168c098
 * (its size 0x70 and the int 1 first, then twelve functions from FUN_001afe90;
 * the next table, at 0x168c108, carries 2): the usable size of a block, passed
 * on to the C library. Its neighbours FUN_001b0520 and FUN_001b0540 pass the
 * space at 0x57c9120 with their argument. */
size_t FUN_001b0560(void *block) /* derived name */
{
    return sceLibcMspaceMallocUsableSize(block);
}
