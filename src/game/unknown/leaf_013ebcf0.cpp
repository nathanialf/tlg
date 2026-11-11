/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d5188 (its pointer at 0x16d51a0), whose class
 * leaf_013ece90.cpp names Object013ecea0: passes its argument to FUN_013ebd10, then
 * calls FUN_013ecce0 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object013ecea0; /* derived name */

void FUN_013ebd10(void *argument);       /* derived name */
void FUN_013ecce0(Object013ecea0 *self); /* derived name */

void FUN_013ebcf0(Object013ecea0 *self, void *argument) /* derived name */
{
    FUN_013ebd10(argument);
    FUN_013ecce0(self);
}
