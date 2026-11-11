/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 15 of the vtables at 0x16ac180 and 0x16cb520 (its pointers at
 * 0x16ac208 and 0x16cb5a8): calls FUN_00823bb0 on the object, then
 * FUN_0134d0e0 as a tail call. The result's type is not traced. Class and
 * method unknown. */
struct Object01360410; /* derived name */

void FUN_00823bb0(Object01360410 *self); /* derived name */
void FUN_0134d0e0(Object01360410 *self); /* derived name */

void FUN_01360410(Object01360410 *self) /* derived name */
{
    FUN_00823bb0(self);
    FUN_0134d0e0(self);
}
