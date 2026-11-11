/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d55d8 (its pointer at 0x16d55f0), whose class
 * leaf_013f9170.cpp names Object013f9180: passes its argument to FUN_013f7ff0, then
 * calls FUN_013f8fc0 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object013f9180; /* derived name */

void FUN_013f7ff0(void *argument);       /* derived name */
void FUN_013f8fc0(Object013f9180 *self); /* derived name */

void FUN_013f7fd0(Object013f9180 *self, void *argument) /* derived name */
{
    FUN_013f7ff0(argument);
    FUN_013f8fc0(self);
}
