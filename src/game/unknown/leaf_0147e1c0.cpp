/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_01243810 directly with the object, the address of
 * the field at +0x2d0 of the record the pointer at +0x8 holds and 3 and 0 as
 * the third and fourth arguments, as a tail call; slot 4 of the vtable at
 * 0x16d7128 (its pointer at 0x16d7158). The field's type, the argument types
 * and the return type are not traced. Class and method unknown; the direct
 * call is written as a call to the method's FUN_ row. */
struct Record0147e1c0 { /* derived name */
    u8 unknown0[0x2d0];
    u8 unknown2d0; /* type not traced; its address is passed */
};

struct Object01243810 { /* derived name */
    u8 unknown0[8];
    Record0147e1c0 *unknown8;
};

void FUN_01243810(Object01243810 *self, void *argument, int first, int second); /* derived name */

void FUN_0147e1c0(Object01243810 *self) /* derived name */
{
    FUN_01243810(self, &self->unknown8->unknown2d0, 3, 0);
}
