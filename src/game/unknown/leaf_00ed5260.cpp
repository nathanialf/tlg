/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_memory.h"

/* derived names: the function whose pointer is at 0x57adaa0: when the pointer at 0x5a8e008 holds a block (0x488 bytes; stored by FUN_00ed4be0), zeroes the block and clears the pointer; returns 0. */
struct Block05a8e008 { /* derived name */
    u8 unknown0[0x488];
};

extern Block05a8e008 *D_5a8e008;

int FUN_00ed5260() /* derived name */
{
    if (D_5a8e008 != 0) {
        clearMemory(D_5a8e008, sizeof(Block05a8e008));
        D_5a8e008 = 0;
    }
    return 0;
}
