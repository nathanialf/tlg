/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 194 of the vtable at 0x16b2d80: FUN_0043c0c0 with 126
 * when FUN_004593b0 on the object returns 0. The types are not traced. Class
 * and method unknown. */
struct Object00abec10; /* derived name */

int FUN_004593b0(Object00abec10 *self);            /* derived name */
void FUN_0043c0c0(Object00abec10 *self, int code); /* derived name */

void FUN_00abec10(Object00abec10 *self) /* derived name */
{
    if (!FUN_004593b0(self)) {
        FUN_0043c0c0(self, 126);
    }
}
