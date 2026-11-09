/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores 300 in the int at +0x110 of the record the pointer at
 * +0x8 holds and sets the flag the pointer at +0x10 points to; slot 2 of the
 * vtable at 0x16af5a0 (its pointer at 0x16af5c0). Class and method unknown. */
struct Record008af710 { /* derived name */
    u8 unknown0[0x110];
    int unknown110;
};

struct Object008af710 { /* derived name */
    u8 unknown0[8];
    Record008af710 *unknown8;
    bool *unknown10;
};

void FUN_008af710(Object008af710 *self) /* derived name */
{
    self->unknown8->unknown110 = 300;
    *self->unknown10 = true;
}
