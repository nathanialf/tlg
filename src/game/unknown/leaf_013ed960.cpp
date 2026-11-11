/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d5228 (its pointer at 0x16d5240), whose class
 * leaf_013eeb00.cpp names Object013eeb10: passes its argument to FUN_013ed980, then
 * calls FUN_013ee950 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object013eeb10; /* derived name */

void FUN_013ed980(void *argument);       /* derived name */
void FUN_013ee950(Object013eeb10 *self); /* derived name */

void FUN_013ed960(Object013eeb10 *self, void *argument) /* derived name */
{
    FUN_013ed980(argument);
    FUN_013ee950(self);
}
