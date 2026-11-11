/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of the vtables at 0x16ca380, 0x16ca3d0, 0x16d4180 and 0x16d41d0: calls FUN_013dfda0
 * on the object, then sets the int at 0x70 to 0. Class and method unknown. */
struct Object013e1a80 { /* derived name */
    u8 unknown0[0x70];
    int unknown70;
};

void FUN_013dfda0(Object013e1a80 *self); /* derived name */

void FUN_013e1a80(Object013e1a80 *self) /* derived name */
{
    FUN_013dfda0(self);
    self->unknown70 = 0;
}
