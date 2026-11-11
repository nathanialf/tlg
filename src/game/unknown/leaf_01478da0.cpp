/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d6ad8 (its pointer at 0x16d6af0), whose class
 * leaf_01479f40.cpp names Object01479f50: passes its argument to FUN_01478dc0, then
 * calls FUN_01479d90 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object01479f50; /* derived name */

void FUN_01478dc0(void *argument);       /* derived name */
void FUN_01479d90(Object01479f50 *self); /* derived name */

void FUN_01478da0(Object01479f50 *self, void *argument) /* derived name */
{
    FUN_01478dc0(argument);
    FUN_01479d90(self);
}
