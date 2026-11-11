/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 16 of the vtables at 0x16a8830 and 0x16c7608 (its pointers at
 * 0x16a88c0 and 0x16c7698): returns what FUN_00823c90 gives for the object, after
 * calling FUN_0134d0e0 on it. The result's type is not traced. Class and
 * method unknown. */
struct Object0134d780; /* derived name */

int FUN_00823c90(Object0134d780 *self);  /* derived name */
void FUN_0134d0e0(Object0134d780 *self); /* derived name */

int FUN_0134d780(Object0134d780 *self) /* derived name */
{
    int result = FUN_00823c90(self);
    FUN_0134d0e0(self);
    return result;
}
