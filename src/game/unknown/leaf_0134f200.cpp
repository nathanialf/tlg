/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: zeroes the int at +0x20; slot 4 of the vtable at 0x16a8f10
 * (its pointer at 0x16a8f40), the vtable stored by FUN_003de0a0; slot 4
 * counted from the nearest stored vtable, at 0x16c7770 (its pointer at
 * 0x16c77a0), the vtable stored by FUN_003de0a0 FUN_003dec30 FUN_003decc0
 * FUN_0134f210 FUN_0134f2a0. Class and method unknown. */
struct Object0134f200 { /* derived name */
    u8 unknown0[0x20];
    int unknown20;
};

void FUN_0134f200(Object0134f200 *self) /* derived name */
{
    self->unknown20 = 0;
}
