/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d7888 (its pointer at 0x16d78a0), whose class
 * leaf_01482c10.cpp names Object01482c20: passes its argument to FUN_01481a90, then
 * calls FUN_01482a60 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object01482c20; /* derived name */

void FUN_01481a90(void *argument);       /* derived name */
void FUN_01482a60(Object01482c20 *self); /* derived name */

void FUN_01481a70(Object01482c20 *self, void *argument) /* derived name */
{
    FUN_01481a90(argument);
    FUN_01482a60(self);
}
