/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_0092c480 with its second argument and returns 1;
 * the object is unused. The argument's type is not traced; slot 3 of the
 * vtable at 0x16cc9e8 (its pointer at 0x16cca10), the vtable stored by
 * FUN_0137c8b0. Class and method unknown. */
struct Object0137c8f0; /* derived name */
struct Target0092c480; /* derived name */

void FUN_0092c480(Target0092c480 *target); /* derived name */

int FUN_0137c8f0(Object0137c8f0 *, Target0092c480 *target) /* derived name */
{
    FUN_0092c480(target);
    return 1;
}
