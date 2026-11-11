/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d3978 (its pointer at 0x16d3990), whose class
 * leaf_013d15f0.cpp names Object013d1600: passes its argument to FUN_013d0470, then
 * calls FUN_013d1440 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object013d1600; /* derived name */

void FUN_013d0470(void *argument);       /* derived name */
void FUN_013d1440(Object013d1600 *self); /* derived name */

void FUN_013d0450(Object013d1600 *self, void *argument) /* derived name */
{
    FUN_013d0470(argument);
    FUN_013d1440(self);
}
