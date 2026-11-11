/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 14 of the vtables at 0x16ac180 and 0x16cb520 (its pointers at
 * 0x16ac200 and 0x16cb5a0): returns what FUN_008239d0 gives for the object, after
 * calling FUN_0134d0e0 on it. The result's type is not traced. Class and
 * method unknown. */
struct Object013603e0; /* derived name */

void *FUN_008239d0(Object013603e0 *self); /* derived name */
void FUN_0134d0e0(Object013603e0 *self);  /* derived name */

void *FUN_013603e0(Object013603e0 *self) /* derived name */
{
    void *result = FUN_008239d0(self);
    FUN_0134d0e0(self);
    return result;
}
