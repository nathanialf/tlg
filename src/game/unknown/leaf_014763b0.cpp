/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d6930 (its pointer at 0x16d6948), whose class
 * leaf_01477550.cpp names Object01477560: passes its argument to FUN_014763d0, then
 * calls FUN_014773a0 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object01477560; /* derived name */

void FUN_014763d0(void *argument);       /* derived name */
void FUN_014773a0(Object01477560 *self); /* derived name */

void FUN_014763b0(Object01477560 *self, void *argument) /* derived name */
{
    FUN_014763d0(argument);
    FUN_014773a0(self);
}
