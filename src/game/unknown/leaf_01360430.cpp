/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 16 of the vtables at 0x16ac180 and 0x16cb520 (its pointers at
 * 0x16ac210 and 0x16cb5b0): returns what FUN_00823c90 gives for the object, after
 * calling FUN_0134d0e0 on it. The result's type is not traced. Class and
 * method unknown. */
struct Object01360430; /* derived name */

int FUN_00823c90(Object01360430 *self);  /* derived name */
void FUN_0134d0e0(Object01360430 *self); /* derived name */

int FUN_01360430(Object01360430 *self) /* derived name */
{
    int result = FUN_00823c90(self);
    FUN_0134d0e0(self);
    return result;
}
