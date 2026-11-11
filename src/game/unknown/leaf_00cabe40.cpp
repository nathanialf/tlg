/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 7 of the vtable at 0x16b8e48 (its pointer at
 * 0x16b8e90): passes the object at +0x28 and the object itself to
 * FUN_00cb27a0, then clears bit 0 of the byte at +0x20. Class and method
 * unknown. */
struct Object00cabe40 { /* derived name */
    u8 unknown0[0x20];
    u8 unknown20;
    u8 unknown21[0x7];
    void *unknown28;
};

void FUN_00cb27a0(void *owner, Object00cabe40 *self); /* derived name */

void FUN_00cabe40(Object00cabe40 *self) /* derived name */
{
    FUN_00cb27a0(self->unknown28, self);
    self->unknown20 &= ~1;
}
