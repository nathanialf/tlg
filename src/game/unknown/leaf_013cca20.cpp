/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x34 differs from 0x7fffffff
 * (INT_MAX), as an int (the bool widened, movzbl); slot 2 of the vtable at
 * 0x16be878 (its pointer at 0x16be898), the vtable stored by FUN_00eb1a20.
 * Class and method unknown. */
struct Object013cca20 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
};

int FUN_013cca20(const Object013cca20 *self) /* derived name */
{
    return self->unknown34 != 0x7fffffff;
}
