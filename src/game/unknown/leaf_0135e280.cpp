/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x14 is 1, 2 or 3, as an int (the
 * unsigned compare of the value less 1 with 3, its carry widened by sbb and
 * and); slot 12 of the vtable at 0x16abb00 (its pointer at 0x16abb70), the
 * vtable stored by FUN_005b05b0 FUN_005b14b0; slot 0 of the vtable at
 * 0x16cb1a0 (its pointer at 0x16cb1b0), the vtable stored by FUN_005b05b0
 * FUN_005b14b0. FUN_0135e290 (slot 13) compares it with 4. Class and method
 * unknown. */
struct Object0135e290 { /* derived name */
    u8 unknown0[0x14];
    int unknown14; /* compared by FUN_0135e280 and FUN_0135e290 */
};

int FUN_0135e280(const Object0135e290 *self) /* derived name */
{
    return self->unknown14 >= 1 && self->unknown14 <= 3;
}
