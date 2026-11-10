/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00be0150 on the object, then FUN_0057d360 as a
 * tail call; slot 7 of the vtable at 0x16ab758 (its pointer at 0x16ab7a0).
 * The callees' other parameters and return types are not traced. Class and
 * method unknown. */
struct Object0057d340; /* derived name */

void FUN_00be0150(Object0057d340 *self); /* derived name */
void FUN_0057d360(Object0057d340 *self); /* derived name */

void FUN_0057d340(Object0057d340 *self) /* derived name */
{
    FUN_00be0150(self);
    FUN_0057d360(self);
}
