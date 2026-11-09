/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets the int at +0x50 to 1 and returns 1; slot 9 of the
 * vtable at 0x16b08a8 (its pointer at 0x16b0900), the vtable stored by
 * FUN_008f3b60 FUN_008f3d30; slot 9 of the vtable at 0x16b0a20 (its pointer at
 * 0x16b0a78), the vtable stored by FUN_00900a40 FUN_00900bf0 FUN_00900ca0;
 * slot 9 of the vtable at 0x16b0b08 (its pointer at 0x16b0b60), the vtable
 * stored by FUN_009012d0 FUN_00903940; slot 9 of the vtable at 0x16b5380 (its
 * pointer at 0x16b53d8), the vtable stored by FUN_00b1f270 FUN_00b1f3e0; and 2
 * more. FUN_013742d0 (slot 11 of the same vtables) zeroes it. Class and method
 * unknown. */
struct Object013742d0 { /* derived name */
    u8 unknown0[0x50];
    int unknown50;
};

int FUN_013742c0(Object013742d0 *self) /* derived name */
{
    self->unknown50 = 1;
    return 1;
}
