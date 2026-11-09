/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00f67000 on the object with 1 and 3, as a tail
 * call, as FUN_00f68e10 does with 0 and 4; slot 4 of the vtable at 0x16bf440
 * (its pointer at 0x16bf470), the vtable stored by FUN_00f59e00. Class and
 * method unknown. */
struct Object00f67000; /* derived name */

void FUN_00f67000(Object00f67000 *self, int, u64); /* derived name */

void FUN_00f68e00(Object00f67000 *self) /* derived name */
{
    FUN_00f67000(self, 1, 3);
}
