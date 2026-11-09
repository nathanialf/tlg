/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16d4420 (its pointer at 0x16d4470),
 * the vtable stored by FUN_00f9ab50; slot 8 of the vtable at 0x16d4478 (its
 * pointer at 0x16d44c8), the vtable stored by FUN_00f9ab50, whose slot 7 is
 * FUN_00fb7520: it calls that method directly, not through the vtable, as a
 * tail call, with 2 inserted as its third argument and its own int passed as
 * the fourth, as FUN_013e3920 does with 0. Class and method unknown; the
 * direct call is written as a call to the method's FUN_ row. */
struct Object00fb7520; /* derived name */
struct Target00fb7520; /* derived name */

void FUN_00fb7520(Object00fb7520 *self, Target00fb7520 *target, int first,
                  int second); /* derived name */

void FUN_013e3b00(Object00fb7520 *self, Target00fb7520 *target, int second) /* derived name */
{
    FUN_00fb7520(self, target, 2, second);
}
