/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores the floats 20.0f and 42.0f at +0x11c and +0x120 (one
 * 64-bit store); slot 10 of the vtable at 0x16d5760 (its pointer at
 * 0x16d57c0), the vtable stored by FUN_01078df0 FUN_013fb0e0 FUN_013fb5f0;
 * slot 10 of the vtable at 0x16d5ac0 (its pointer at 0x16d5b20), the vtable
 * stored by FUN_010d9730 FUN_0140d6a0 FUN_0140d9d0; slot 10 of the vtable at
 * 0x16d5c40 (its pointer at 0x16d5ca0), the vtable stored by FUN_010f2e40
 * FUN_01415fc0 FUN_014163d0; slot 10 of the vtable at 0x16d5dc0 (its pointer
 * at 0x16d5e20), the vtable stored by FUN_0110cc00 FUN_0141d0e0 FUN_0141d4f0;
 * and 2 more. Class and method unknown. */
struct Object014354b0 { /* derived name */
    u8 unknown0[0x11c];
    float unknown11c;
    float unknown120;
};

void FUN_014354b0(Object014354b0 *self) /* derived name */
{
    self->unknown11c = 20.0f;
    self->unknown120 = 42.0f;
}
