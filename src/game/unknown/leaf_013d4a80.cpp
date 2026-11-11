/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d3b18 (its pointer at 0x16d3b30), whose class
 * leaf_013d5c20.cpp names Object013d5c30: passes its argument to FUN_013d4aa0, then
 * calls FUN_013d5a70 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object013d5c30; /* derived name */

void FUN_013d4aa0(void *argument);       /* derived name */
void FUN_013d5a70(Object013d5c30 *self); /* derived name */

void FUN_013d4a80(Object013d5c30 *self, void *argument) /* derived name */
{
    FUN_013d4aa0(argument);
    FUN_013d5a70(self);
}
