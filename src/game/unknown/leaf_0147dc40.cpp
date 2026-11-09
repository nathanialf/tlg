/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_012388c0, slot 7 of the same vtable, directly with
 * the object and the address of the field at +0x2d0 of the record the pointer
 * at +0x8 holds, as a tail call; slot 4 of the vtable at 0x16d6d90 (its
 * pointer at 0x16d6dc0), the vtable stored by FUN_0122be10. The field's type,
 * the argument types and the return type are not traced. Class and method
 * unknown; the direct call is written as a call to the method's FUN_ row. */
struct Record0147dc40 { /* derived name */
    u8 unknown0[0x2d0];
    u8 unknown2d0; /* type not traced; its address is passed */
};

struct Object012388c0 { /* derived name */
    u8 unknown0[8];
    Record0147dc40 *unknown8;
};

void FUN_012388c0(Object012388c0 *self, void *argument); /* derived name */

void FUN_0147dc40(Object012388c0 *self) /* derived name */
{
    FUN_012388c0(self, &self->unknown8->unknown2d0);
}
