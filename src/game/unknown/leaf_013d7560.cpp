/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d3e30 (its pointer at 0x16d3e48), whose class
 * leaf_013d8700.cpp names Object013d8710: passes its argument to FUN_013d7580, then
 * calls FUN_013d8550 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object013d8710; /* derived name */

void FUN_013d7580(void *argument);       /* derived name */
void FUN_013d8550(Object013d8710 *self); /* derived name */

void FUN_013d7560(Object013d8710 *self, void *argument) /* derived name */
{
    FUN_013d7580(argument);
    FUN_013d8550(self);
}
