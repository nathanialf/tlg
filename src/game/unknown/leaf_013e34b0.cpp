/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16d46e0 (its pointer at 0x16d4730),
 * the vtable stored by FUN_00fbadf0; slot 8 of the vtable at 0x16d4738 (its
 * pointer at 0x16d4788), the vtable stored by FUN_00fbadf0, whose slot 7 is
 * FUN_00fb0cf0: it calls that method directly, not through the vtable, as a
 * tail call, with 2 inserted as its third argument and its own int passed as
 * the fourth, as FUN_013e3450 does with 0. Class and method unknown; the
 * direct call is written as a call to the method's FUN_ row. */
struct Object00fb0cf0; /* derived name */
struct Target00fb0cf0; /* derived name */

void FUN_00fb0cf0(Object00fb0cf0 *self, Target00fb0cf0 *target, int first,
                  int second); /* derived name */

void FUN_013e34b0(Object00fb0cf0 *self, Target00fb0cf0 *target, int second) /* derived name */
{
    FUN_00fb0cf0(self, target, 2, second);
}
