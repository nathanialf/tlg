/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 13 of the vtables at 0x16a8830 and 0x16c7608 (its pointers at
 * 0x16a88a8 and 0x16c7680): returns what FUN_00823580 gives for the object, after
 * calling FUN_0134d0e0 on it. The result's type is not traced. Class and
 * method unknown. */
struct Object0134d700; /* derived name */

void *FUN_00823580(Object0134d700 *self); /* derived name */
void FUN_0134d0e0(Object0134d700 *self);  /* derived name */

void *FUN_0134d700(Object0134d700 *self) /* derived name */
{
    void *result = FUN_00823580(self);
    FUN_0134d0e0(self);
    return result;
}
