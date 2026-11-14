/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the fourth of the four default callbacks in the 0x20-byte
 * record at 0x16bec80 (FUN_00f021a0, FUN_00f02510, FUN_00f02530, this),
 * which FUN_00f01270 stores at +0xe8 of its object when the record at +0x168
 * of its source has no fourth function (+0x180). It returns the int at +0x18
 * of its third argument; FUN_00f02510 and FUN_00f02530 likewise ignore their
 * first two arguments and pass the third on to FUN_00f02560. The first two
 * parameters' types are not traced. Owner and field unknown. */
struct Object00f02550 {
    u8 unknown0[0x18];
    int unknown18;
};

int FUN_00f02550(void *, void *, const Object00f02550 *item) /* derived name */
{
    return item->unknown18;
}
