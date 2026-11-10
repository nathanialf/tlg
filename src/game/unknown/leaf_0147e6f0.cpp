/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_01248760 directly with the object, the address of
 * the field at +0x2d0 of the record the pointer at +0x8 holds and 1 and 0 as
 * the third and fourth arguments, as a tail call; slot 4 of the vtable at
 * 0x16d6fc8 (its pointer at 0x16d6ff8). The field's type, the argument types
 * and the return type are not traced. Class and method unknown; the direct
 * call is written as a call to the method's FUN_ row. */
struct Record0147e6f0 { /* derived name */
    u8 unknown0[0x2d0];
    u8 unknown2d0; /* type not traced; its address is passed */
};

struct Object01248760 { /* derived name */
    u8 unknown0[8];
    Record0147e6f0 *unknown8;
};

void FUN_01248760(Object01248760 *self, void *argument, int first, int second); /* derived name */

void FUN_0147e6f0(Object01248760 *self) /* derived name */
{
    FUN_01248760(self, &self->unknown8->unknown2d0, 1, 0);
}
