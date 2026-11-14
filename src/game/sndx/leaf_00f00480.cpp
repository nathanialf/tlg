/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_memory.h"

/* derived names: the function whose pointer is at 0x57ada58: when the pointer at 0x5a8e0e0 holds a block (0x8 bytes; stored by FUN_00eff7e0), calls FUN_00f00fd0, zeroes the block and clears the pointer; returns 0. */
struct Block05a8e0e0 { /* derived name */
    u8 unknown0[0x8];
};

extern Block05a8e0e0 *D_5a8e0e0;

void FUN_00f00fd0(); /* derived name; the return type is not traced */

int FUN_00f00480() /* derived name */
{
    if (D_5a8e0e0 != 0) {
        FUN_00f00fd0();
        clearMemory(D_5a8e0e0, sizeof(Block05a8e0e0));
        D_5a8e0e0 = 0;
    }
    return 0;
}
