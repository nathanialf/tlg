/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_00d8f280, lea at
 * 0xd8f2d3), as FUN_00d8ff10: calls FUN_00d47c20 with the object when bit 0 of
 * the byte at +0x24 is set (a one-bit field, cookbook 1111) or the int at
 * +0x270 is nonzero, and returns 1. The types are not traced. */
struct Object00d8ff50 { /* derived name */
    u8 unknown0[0x24];
    u8 unknown24_0 : 1;
    u8 unknown25[0x24b];
    int unknown270;
};

void FUN_00d47c20(Object00d8ff50 *self); /* derived name */

int FUN_00d8ff50(Object00d8ff50 *self) /* derived name */
{
    if (self->unknown24_0 || self->unknown270 != 0) {
        FUN_00d47c20(self);
    }
    return 1;
}
