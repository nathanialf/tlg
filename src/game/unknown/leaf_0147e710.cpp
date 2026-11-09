/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16d6f70 (its pointer at 0x16d6fc0),
 * the vtable stored by FUN_0122be10; slot 8 of the vtable at 0x16d6fc8 (its
 * pointer at 0x16d7018), the vtable stored by FUN_0122be10, whose slot 7 is
 * FUN_01248760: it calls that method directly, not through the vtable, as a
 * tail call, with 1 inserted as its third argument and its own int passed as
 * the fourth, as FUN_0147e620 does with 0. Class and method unknown; the
 * direct call is written as a call to the method's FUN_ row. */
struct Object01248760; /* derived name */
struct Target01248760; /* derived name */

void FUN_01248760(Object01248760 *self, Target01248760 *target, int first,
                  int second); /* derived name */

void FUN_0147e710(Object01248760 *self, Target01248760 *target, int second) /* derived name */
{
    FUN_01248760(self, target, 1, second);
}
