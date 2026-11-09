/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the 16-bit value at +0x20 differs from
 * 0xffff, as an int (the bool widened, movzbl); slot 2 of the vtable at
 * 0x16be8d0 (its pointer at 0x16be8f0), the vtable stored by FUN_00ea83b0
 * FUN_00eb2710. Class and method unknown. */
struct Object013cca30 { /* derived name */
    u8 unknown0[0x20];
    u16 unknown20;
};

int FUN_013cca30(const Object013cca30 *self) /* derived name */
{
    return self->unknown20 != 0xffff;
}
