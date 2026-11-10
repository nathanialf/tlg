/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00fb1d70, slot 7 of the same vtable, directly with
 * the object, the address of the field at +0x2f0 of the record the pointer at
 * +0x8 holds, and the address of its own field at +0x100, as a tail call; slot
 * 4 of the vtable at 0x16d4948 (its pointer at 0x16d4978); FUN_013e30a0 passes
 * its arguments on to the same method. The fields' types are not traced. Class
 * and method unknown; the direct call is written as a call to the method's
 * FUN_ row. */
struct Record013e3080 { /* derived name */
    u8 unknown0[0x2f0];
    u8 unknown2f0; /* type not traced; its address is passed */
};

struct Object00fb1d70 { /* derived name */
    u8 unknown0[8];
    Record013e3080 *unknown8;
    u8 unknown10[0xf0];
    u8 unknown100; /* type not traced; its address is passed */
};

void FUN_00fb1d70(Object00fb1d70 *self, void *a, void *b); /* derived name */

void FUN_013e3080(Object00fb1d70 *self) /* derived name */
{
    FUN_00fb1d70(self, &self->unknown8->unknown2f0, &self->unknown100);
}
