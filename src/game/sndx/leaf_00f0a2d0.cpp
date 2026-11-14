/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_memory.h"

/* derived names: the function whose pointer is at 0x57ad9f8: when the pointer at 0x5aa21e0 holds a block (0x70 bytes; stored by FUN_00f0a130), zeroes the block and clears the pointer; returns 0. */
struct Block05aa21e0 { /* derived name */
    u8 unknown0[0x70];
};

extern Block05aa21e0 *D_5aa21e0;

int FUN_00f0a2d0() /* derived name */
{
    if (D_5aa21e0 != 0) {
        clearMemory(D_5aa21e0, sizeof(Block05aa21e0));
        D_5aa21e0 = 0;
    }
    return 0;
}
