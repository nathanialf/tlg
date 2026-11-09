/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16d44d0 (its pointer at 0x16d4520),
 * the vtable stored by FUN_00fbb270; slot 8 of the vtable at 0x16d4528 (its
 * pointer at 0x16d4578), the vtable stored by FUN_00fbb270, whose slot 7 is
 * FUN_00fb7520: it calls that method directly, not through the vtable, as a
 * tail call, with 1 inserted as its third argument and its own int passed as
 * the fourth, as FUN_013e3920 does with 0. Class and method unknown; the
 * direct call is written as a call to the method's FUN_ row. */
struct Object00fb7520; /* derived name */
struct Target00fb7520; /* derived name */

void FUN_00fb7520(Object00fb7520 *self, Target00fb7520 *target, int first,
                  int second); /* derived name */

void FUN_013e3a10(Object00fb7520 *self, Target00fb7520 *target, int second) /* derived name */
{
    FUN_00fb7520(self, target, 1, second);
}
