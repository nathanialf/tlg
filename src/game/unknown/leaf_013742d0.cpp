/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: zeroes the int at +0x50; slot 11 of the vtable at 0x16b08a8
 * (its pointer at 0x16b0910), the vtable stored by FUN_008f3b60 FUN_008f3d30;
 * slot 11 of the vtable at 0x16b0a20 (its pointer at 0x16b0a88), the vtable
 * stored by FUN_00900a40 FUN_00900bf0 FUN_00900ca0; slot 11 of the vtable at
 * 0x16b0b08 (its pointer at 0x16b0b70), the vtable stored by FUN_009012d0
 * FUN_00903940; slot 11 of the vtable at 0x16b5380 (its pointer at 0x16b53e8),
 * the vtable stored by FUN_00b1f270 FUN_00b1f3e0; and 3 more. Class and method
 * unknown. */
struct Object013742d0 { /* derived name */
    u8 unknown0[0x50];
    int unknown50;
};

void FUN_013742d0(Object013742d0 *self) /* derived name */
{
    self->unknown50 = 0;
}
