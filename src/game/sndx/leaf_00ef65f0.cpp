/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: takes a message: 0x2000 starts a list of values at +0x5ac
 * with its value (mode 1 at +0x5a8, one value), 0x2001 adds its value to the
 * list (mode 2), at most four values (their count at +0x5a9); other messages
 * are ignored. The messages' meaning is not traced. */
struct Object00ef65f0 /* derived name */
{
    u8 unknown0[0x5a8];
    u8 mode;  /* +0x5a8 */
    u8 count; /* +0x5a9 */
    u8 unknown5aa[2];
    int values[4]; /* +0x5ac */
};

void FUN_00ef65f0(Object00ef65f0 *self, int message, int value) /* derived name */
{
    if (message == 0x2000) {
        self->mode = 1;
        self->count = 1;
        self->values[0] = value;
    } else if (message == 0x2001) {
        self->mode = 2;
        if (self->count < 4)
            self->values[self->count++] = value;
    }
}
