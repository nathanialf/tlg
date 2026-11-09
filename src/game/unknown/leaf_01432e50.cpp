/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores the floats 24.0f and 60.0f at +0x120 and +0x124 (one
 * 64-bit store); slot 6 of the vtable at 0x16d5710 (its pointer at 0x16d5750),
 * the vtable stored by FUN_01078df0 FUN_013fac20 FUN_013fb820; slot 6 of the
 * vtable at 0x16d5a70 (its pointer at 0x16d5ab0), the vtable stored by
 * FUN_010d9730 FUN_0140d390 FUN_0140dc00; slot 6 of the vtable at 0x16d5bf0
 * (its pointer at 0x16d5c30), the vtable stored by FUN_010f2e40 FUN_01415cb0
 * FUN_01416600; slot 6 of the vtable at 0x16d5d70 (its pointer at 0x16d5db0),
 * the vtable stored by FUN_0110cc00 FUN_0141cc20 FUN_0141d720; and 2 more.
 * Class and method unknown. */
struct Object01432e50 { /* derived name */
    u8 unknown0[0x120];
    float unknown120;
    float unknown124;
};

void FUN_01432e50(Object01432e50 *self) /* derived name */
{
    self->unknown120 = 24.0f;
    self->unknown124 = 60.0f;
}
