/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken twice by FUN_00ee22d0):
 * calls the function pointer at +0x38 of the record at +0x90, when set, with
 * the object and the two ints its argument points to; returns 0. The types
 * are not traced. */
struct Object00eddfb0; /* derived name */

struct Record00eddfb0 { /* derived name */
    u8 unknown0[0x38];
    void (*unknown38)(Object00eddfb0 *self, int first, int second);
};

struct Object00eddfb0 { /* derived name */
    u8 unknown0[0x90];
    Record00eddfb0 *unknown90;
};

int FUN_00eddfb0(Object00eddfb0 *self, const int *values) /* derived name */
{
    if (self->unknown90->unknown38) {
        self->unknown90->unknown38(self, values[0], values[1]);
    }
    return 0;
}
