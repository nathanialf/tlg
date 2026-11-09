/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets the int at +8 to 1 when its argument is 99; slot 25 of
 * the vtable at 0x16bdc60 (its pointer at 0x16bdd38), the vtable stored by
 * FUN_00e5c990 FUN_00e5d180. Class and method unknown. */
struct Object00e5d2d0 { /* derived name */
    u8 unknown0[8];
    int unknown8;
};

void FUN_00e5d2d0(Object00e5d2d0 *self, int value) /* derived name */
{
    if (value == 99)
        self->unknown8 = 1;
}
