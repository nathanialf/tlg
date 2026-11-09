/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: zeroes the int at +0x1c; slot 5 of the vtable at 0x16d5050
 * (its pointer at 0x16d5088), the vtable stored by FUN_00ffe8c0 FUN_013ed250
 * FUN_013ed2e0; slot 5 of the vtable at 0x16d7750 (its pointer at 0x16d7788),
 * the vtable stored by FUN_0126a510 FUN_01482fd0 FUN_01483060. Class and
 * method unknown. */
struct Object013eb6e0 { /* derived name */
    u8 unknown0[0x1c];
    int unknown1c;
};

void FUN_013eb6e0(Object013eb6e0 *self) /* derived name */
{
    self->unknown1c = 0;
}
