/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: zeroes the int at +0x60; slot 8 of the vtable at 0x16ae7e0
 * (its pointer at 0x16ae830), the vtable stored by FUN_00818b00 FUN_00818d10
 * FUN_00818ea0 FUN_00845fb0 FUN_00846c90 FUN_008eeb00 FUN_00b1b370
 * FUN_00b1b9f0; slot 8 of the vtable at 0x16ae838 (its pointer at 0x16ae888),
 * the vtable stored by FUN_00818ea0 FUN_008190a0 FUN_00819140 FUN_00b1bbf0
 * FUN_00b1bc90; slot 8 of the vtable at 0x16aef90 (its pointer at 0x16aefe0),
 * the vtable stored by FUN_00846c90 FUN_00847290; slot 8 of the vtable at
 * 0x16b0658 (its pointer at 0x16b06a8), the vtable stored by FUN_008eeb00; and
 * 1 more. Class and method unknown. */
struct Object00818e90 { /* derived name */
    u8 unknown0[0x60];
    int unknown60;
};

void FUN_00818e90(Object00818e90 *self) /* derived name */
{
    self->unknown60 = 0;
}
