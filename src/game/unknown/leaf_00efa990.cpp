/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_memory.h"

/* derived names: the function whose pointer is at 0x57ada70: when the pointer
 * at 0x5a8e0d8 holds a block (0x60 bytes, taken zeroed from a linear allocator
 * by FUN_00efa740), zeroes the block and clears the pointer; returns 0. */
struct Block05a8e0d8 { /* derived name */
    u8 unknown0[0x60];
};

extern Block05a8e0d8 *D_5a8e0d8;

int FUN_00efa990() /* derived name */
{
    if (D_5a8e0d8 != 0) {
        clearMemory(D_5a8e0d8, sizeof(Block05a8e0d8));
        D_5a8e0d8 = 0;
    }
    return 0;
}
