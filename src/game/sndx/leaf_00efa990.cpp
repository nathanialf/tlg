/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
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
