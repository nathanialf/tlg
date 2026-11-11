/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d3ec8 (its pointer at 0x16d3ee0), whose class
 * leaf_013dbbc0.cpp names Object013dbbd0: passes its argument to FUN_013daa40, then
 * calls FUN_013dba10 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object013dbbd0; /* derived name */

void FUN_013daa40(void *argument);       /* derived name */
void FUN_013dba10(Object013dbbd0 *self); /* derived name */

void FUN_013daa20(Object013dbbd0 *self, void *argument) /* derived name */
{
    FUN_013daa40(argument);
    FUN_013dba10(self);
}
