/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 1 of the vtable at 0x16d7b00 (its pointer at 0x16d7b18), whose class
 * leaf_014894d0.cpp names Object014894e0: passes its argument to FUN_01488350, then
 * calls FUN_01489320 on the object as a tail call. The argument's type is not
 * traced. Class and method unknown. */
struct Object014894e0; /* derived name */

void FUN_01488350(void *argument);       /* derived name */
void FUN_01489320(Object014894e0 *self); /* derived name */

void FUN_01488330(Object014894e0 *self, void *argument) /* derived name */
{
    FUN_01488350(argument);
    FUN_01489320(self);
}
