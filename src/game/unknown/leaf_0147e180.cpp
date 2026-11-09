/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16d7230 (its pointer at 0x16d7280),
 * the vtable stored by FUN_0122be10; slot 8 of the vtable at 0x16d7288 (its
 * pointer at 0x16d72d8), the vtable stored by FUN_0122be10, whose slot 7 is
 * FUN_01243810: it calls that method directly, not through the vtable, as a
 * tail call, with 1 inserted as its third argument and its own int passed as
 * the fourth, as FUN_0147e150 does with 0. Class and method unknown; the
 * direct call is written as a call to the method's FUN_ row. */
struct Object01243810; /* derived name */
struct Target01243810; /* derived name */

void FUN_01243810(Object01243810 *self, Target01243810 *target, int first,
                  int second); /* derived name */

void FUN_0147e180(Object01243810 *self, Target01243810 *target, int second) /* derived name */
{
    FUN_01243810(self, target, 1, second);
}
