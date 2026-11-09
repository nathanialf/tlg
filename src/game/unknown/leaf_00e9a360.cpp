/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00e9a380 with the object and 1 as a tail call when
 * the pointer at +0x268 is set; slot 14 of the vtable at 0x16be490 (its
 * pointer at 0x16be510). FUN_00e9a380 is also called with 0 by FUN_00ea2bb0.
 * Class and method unknown. */
struct Object00e9a360 { /* derived name */
    u8 unknown0[0x268];
    void *unknown268;
};

void FUN_00e9a380(Object00e9a360 *self, int); /* derived name */

void FUN_00e9a360(Object00e9a360 *self) /* derived name */
{
    if (self->unknown268) {
        FUN_00e9a380(self, 1);
    }
}
