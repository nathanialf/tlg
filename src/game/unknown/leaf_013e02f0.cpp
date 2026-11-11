/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d4318 (its pointer at 0x16d4330), whose class
 * leaf_013e1490.cpp names Object013e14a0: passes its argument to FUN_013e0310, then
 * calls FUN_013e12e0 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object013e14a0; /* derived name */

void FUN_013e0310(void *argument);       /* derived name */
void FUN_013e12e0(Object013e14a0 *self); /* derived name */

void FUN_013e02f0(Object013e14a0 *self, void *argument) /* derived name */
{
    FUN_013e0310(argument);
    FUN_013e12e0(self);
}
