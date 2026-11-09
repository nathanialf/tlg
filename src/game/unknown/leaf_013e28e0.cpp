/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00faa6c0, slot 7 of the same vtable, directly with
 * the object and the address of the field at +0x2f0 of the record the pointer
 * at +0x8 holds, as a tail call; slot 4 of the vtable at 0x16d4130 (its
 * pointer at 0x16d4160), the vtable stored by FUN_00f9ab50. The field's type,
 * the argument types and the return type are not traced. Class and method
 * unknown; the direct call is written as a call to the method's FUN_ row. */
struct Record013e28e0 { /* derived name */
    u8 unknown0[0x2f0];
    u8 unknown2f0; /* type not traced; its address is passed */
};

struct Object00faa6c0 { /* derived name */
    u8 unknown0[8];
    Record013e28e0 *unknown8;
};

void FUN_00faa6c0(Object00faa6c0 *self, void *argument); /* derived name */

void FUN_013e28e0(Object00faa6c0 *self) /* derived name */
{
    FUN_00faa6c0(self, &self->unknown8->unknown2f0);
}
