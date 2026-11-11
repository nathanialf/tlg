/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of the vtables at 0x16c28b8: calls FUN_01480760
 * on the object, then sets the int at 0x80 to 1. Class and method unknown. */
struct Object012650f0 { /* derived name */
    u8 unknown0[0x80];
    int unknown80;
};

void FUN_01480760(Object012650f0 *self); /* derived name */

void FUN_012650f0(Object012650f0 *self) /* derived name */
{
    FUN_01480760(self);
    self->unknown80 = 1;
}
