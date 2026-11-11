/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d7948 (its pointer at 0x16d7960), whose class
 * leaf_01484b40.cpp names Object01484b50: passes its argument to FUN_014839c0, then
 * calls FUN_01484990 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object01484b50; /* derived name */

void FUN_014839c0(void *argument);       /* derived name */
void FUN_01484990(Object01484b50 *self); /* derived name */

void FUN_014839a0(Object01484b50 *self, void *argument) /* derived name */
{
    FUN_014839c0(argument);
    FUN_01484990(self);
}
