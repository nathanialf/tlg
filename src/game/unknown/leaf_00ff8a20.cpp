/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of the vtables at 0x16c0710: calls FUN_013ea8a0
 * on the object, then sets the int at 0x80 to 1. Class and method unknown. */
struct Object00ff8a20 { /* derived name */
    u8 unknown0[0x80];
    int unknown80;
};

void FUN_013ea8a0(Object00ff8a20 *self); /* derived name */

void FUN_00ff8a20(Object00ff8a20 *self) /* derived name */
{
    FUN_013ea8a0(self);
    self->unknown80 = 1;
}
