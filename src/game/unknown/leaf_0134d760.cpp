/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 15 of the vtables at 0x16a8830 and 0x16c7608 (its pointers at
 * 0x16a88b8 and 0x16c7690): calls FUN_00823bb0 on the object, then
 * FUN_0134d0e0 as a tail call. The result's type is not traced. Class and
 * method unknown. */
struct Object0134d760; /* derived name */

void FUN_00823bb0(Object0134d760 *self); /* derived name */
void FUN_0134d0e0(Object0134d760 *self); /* derived name */

void FUN_0134d760(Object0134d760 *self) /* derived name */
{
    FUN_00823bb0(self);
    FUN_0134d0e0(self);
}
