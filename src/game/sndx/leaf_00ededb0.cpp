/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_00ee5d20, lea at
 * 0xee6177): with the function pointer at +0x70 of the record at +0x90 set,
 * returns what it gives for the object, the pointer at +0x0 of its argument,
 * 0, the int at +0x8 and the pointer at +0x10, as a tail call; else 0. The
 * types are not traced. */
struct Object00ededb0; /* derived name */

struct Argument00ededb0 { /* derived name */
    void *unknown0;
    int unknown8;
    void *unknown10;
};

struct Record00ededb0 { /* derived name */
    u8 unknown0[0x70];
    int (*unknown70)(Object00ededb0 *self, void *first, int zero, int second, void *third);
};

struct Object00ededb0 { /* derived name */
    u8 unknown0[0x90];
    Record00ededb0 *unknown90;
};

int FUN_00ededb0(Object00ededb0 *self, const Argument00ededb0 *argument) /* derived name */
{
    int (*function)(Object00ededb0 *, void *, int, int, void *) = self->unknown90->unknown70;
    if (function) {
        return function(self, argument->unknown0, 0, argument->unknown8, argument->unknown10);
    }
    return 0;
}
