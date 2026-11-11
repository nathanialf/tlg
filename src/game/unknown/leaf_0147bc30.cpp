/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d6de0 (its pointer at 0x16d6df8), whose class
 * leaf_0147cdd0.cpp names Object0147cde0: passes its argument to FUN_0147bc50, then
 * calls FUN_0147cc20 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object0147cde0; /* derived name */

void FUN_0147bc50(void *argument);       /* derived name */
void FUN_0147cc20(Object0147cde0 *self); /* derived name */

void FUN_0147bc30(Object0147cde0 *self, void *argument) /* derived name */
{
    FUN_0147bc50(argument);
    FUN_0147cc20(self);
}
