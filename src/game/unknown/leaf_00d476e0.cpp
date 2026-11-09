/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x260 of the object its second
 * argument points to differs from the int at +0xc of it, as an int (the bool
 * widened, movzbl); the first argument is unused; slot 46 of the vtable at
 * 0x16ba2c8 (its pointer at 0x16ba448), the vtable stored by FUN_00d42af0
 * FUN_00d42cb0. Class and method unknown. */
struct Object00d476e0; /* derived name */

struct Target00d476e0 { /* derived name */
    u8 unknown0[0xc];
    int unknownc;
    u8 unknown10[0x260 - 0x10];
    int unknown260;
};

int FUN_00d476e0(Object00d476e0 *, const Target00d476e0 *target) /* derived name */
{
    return target->unknown260 != target->unknownc;
}
