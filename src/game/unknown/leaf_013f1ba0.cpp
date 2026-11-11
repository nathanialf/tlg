/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d53b8 (its pointer at 0x16d53d0), whose class
 * leaf_013f2d40.cpp names Object013f2d50: passes its argument to FUN_013f1bc0, then
 * calls FUN_013f2b90 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object013f2d50; /* derived name */

void FUN_013f1bc0(void *argument);       /* derived name */
void FUN_013f2b90(Object013f2d50 *self); /* derived name */

void FUN_013f1ba0(Object013f2d50 *self, void *argument) /* derived name */
{
    FUN_013f1bc0(argument);
    FUN_013f2b90(self);
}
