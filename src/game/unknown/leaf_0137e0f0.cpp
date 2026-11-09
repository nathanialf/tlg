/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets the bits of its argument in the int at +0x20 of the
 * object at +8, when that pointer is set; slot 32 of the vtable at 0x16b0fb0
 * (its pointer at 0x16b10c0), the vtable stored by FUN_00958460; slot 29 of
 * the vtable at 0x16c7b78 (its pointer at 0x16c7c70), the vtable stored by
 * FUN_00958460 FUN_0137e6e0. Class and method unknown. */
struct Target0137e0f0 { /* derived name */
    u8 unknown0[0x20];
    int unknown20;
};

struct Object0137e0f0 { /* derived name */
    u8 unknown0[8];
    Target0137e0f0 *unknown8;
};

void FUN_0137e0f0(Object0137e0f0 *self, int bits) /* derived name */
{
    if (self->unknown8)
        self->unknown8->unknown20 |= bits;
}
