/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x2e8 is non-zero, as an int (the
 * bool widened, movzbl); slot 22 of the vtable at 0x16ad480 (its pointer at
 * 0x16ad540), the vtable stored by FUN_00783b40 FUN_007847d0. Class and method
 * unknown. */
struct Object0078dab0 { /* derived name */
    u8 unknown0[0x2e8];
    int unknown2e8;
};

int FUN_0078dab0(const Object0078dab0 *self) /* derived name */
{
    return self->unknown2e8 != 0;
}
