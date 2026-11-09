/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x128 is non-zero, as an int (the
 * bool widened, movzbl); slot 22 of the vtable at 0x16ad228 (its pointer at
 * 0x16ad2e8), the vtable stored by FUN_007795c0 FUN_007796c0. Class and method
 * unknown. */
struct Object0136b930 { /* derived name */
    u8 unknown0[0x128];
    int unknown128;
};

int FUN_0136b930(const Object0136b930 *self) /* derived name */
{
    return self->unknown128 != 0;
}
