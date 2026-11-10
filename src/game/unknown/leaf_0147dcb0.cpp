/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_01240d00 directly with the object, the address of
 * the field at +0x2d0 of the record the pointer at +0x8 holds and 1 as a third
 * argument, as a tail call; slot 4 of the vtable at 0x16d73e8 (its pointer at
 * 0x16d7418). The field's type, the argument types and the return type are not
 * traced. Class and method unknown; the direct call is written as a call to
 * the method's FUN_ row. */
struct Record0147dcb0 { /* derived name */
    u8 unknown0[0x2d0];
    u8 unknown2d0; /* type not traced; its address is passed */
};

struct Object01240d00 { /* derived name */
    u8 unknown0[8];
    Record0147dcb0 *unknown8;
};

void FUN_01240d00(Object01240d00 *self, void *argument, int); /* derived name */

void FUN_0147dcb0(Object01240d00 *self) /* derived name */
{
    FUN_01240d00(self, &self->unknown8->unknown2d0, 1);
}
