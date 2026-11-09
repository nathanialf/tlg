/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its unsigned argument at +0x144 converted to float
 * (zero-extended, then vcvtsi2ss from 64 bits); slot 20 of the vtable at
 * 0x16ba8e0 (its pointer at 0x16ba990), the vtable stored by FUN_00d5f7d0
 * FUN_013b9d70; slot 20 of the vtable at 0x16be9a8 (its pointer at 0x16bea58),
 * the vtable stored by FUN_00eb3c90 FUN_00eb3fb0. Class and method unknown. */
struct Object013ba220 { /* derived name */
    u8 unknown0[0x144];
    float unknown144;
};

void FUN_013ba220(Object013ba220 *self, unsigned value) /* derived name */
{
    self->unknown144 = value;
}
