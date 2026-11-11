/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtable at 0x16d6578: when the int at +0x4 of
 * the record at +0x2f8 of the owner at +0x8 is 1, clears the int at +0x4 of
 * the record at +0x10 and the pointer at +0x60; then FUN_01469270 on the
 * object, as a tail call. Class and method unknown. */
struct State01469240 { /* derived name */
    u8 unknown0[4];
    int unknown4;
};

struct Owner01469240 { /* derived name */
    u8 unknown0[0x2f8];
    State01469240 *unknown2f8;
};

struct Object01469240 { /* derived name */
    u8 unknown0[8];
    Owner01469240 *unknown8;
    State01469240 *unknown10;
    u8 unknown18[0x48];
    void *unknown60;
};

void FUN_01469270(Object01469240 *self); /* derived name */

void FUN_01469240(Object01469240 *self) /* derived name */
{
    if (self->unknown8->unknown2f8->unknown4 == 1) {
        self->unknown10->unknown4 = 0;
        self->unknown60 = 0;
    }
    FUN_01469270(self);
}
