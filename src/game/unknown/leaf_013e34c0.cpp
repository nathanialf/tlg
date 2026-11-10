/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00fb0cf0, slot 7 of the same vtable, directly with
 * the object, the address of the field at +0x2f0 of the record the pointer at
 * +0x8 holds, 3, and the int at 0x264 as its fourth argument, as a tail call
 * (the slot 8 siblings pass their own int there); slot 4 of the vtable at
 * 0x16d4688 (its pointer at 0x16d46b8). The field's type and the return type
 * are not traced. Class and method unknown; the direct call is written as a
 * call to the method's FUN_ row. */
struct Record013e34c0 { /* derived name */
    u8 unknown0[0x2f0];
    u8 unknown2f0; /* type not traced; its address is passed */
};

struct Object00fb0cf0 { /* derived name */
    u8 unknown0[8];
    Record013e34c0 *unknown8;
    u8 unknown10[0x254];
    int unknown264;
};

void FUN_00fb0cf0(Object00fb0cf0 *self, void *target, int first, int second); /* derived name */

void FUN_013e34c0(Object00fb0cf0 *self) /* derived name */
{
    FUN_00fb0cf0(self, &self->unknown8->unknown2f0, 3, self->unknown264);
}
