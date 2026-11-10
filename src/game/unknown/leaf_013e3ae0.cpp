/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00fb7520, slot 7 of the same vtable, directly with
 * the object, the address of the field at +0x2f0 of the record the pointer at
 * +0x8 holds, 2, and the int at 0x248 as its fourth argument, as a tail call
 * (the slot 8 siblings pass their own int there); slot 4 of the vtable at
 * 0x16d4478 (its pointer at 0x16d44a8). The field's type and the return type
 * are not traced. Class and method unknown; the direct call is written as a
 * call to the method's FUN_ row. */
struct Record013e3ae0 { /* derived name */
    u8 unknown0[0x2f0];
    u8 unknown2f0; /* type not traced; its address is passed */
};

struct Object00fb7520 { /* derived name */
    u8 unknown0[8];
    Record013e3ae0 *unknown8;
    u8 unknown10[0x238];
    int unknown248;
};

void FUN_00fb7520(Object00fb7520 *self, void *target, int first, int second); /* derived name */

void FUN_013e3ae0(Object00fb7520 *self) /* derived name */
{
    FUN_00fb7520(self, &self->unknown8->unknown2f0, 2, self->unknown248);
}
