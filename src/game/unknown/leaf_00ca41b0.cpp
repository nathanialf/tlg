/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores the pointer its argument points to at +0x38 and
 * returns 1; slot 13 of the vtable at 0x16b8db8 (its pointer at 0x16b8e30),
 * the vtable stored by FUN_00ca3e70. FUN_00ca41a0 and FUN_00ca41b0 (slots 5
 * and 13) have the same body. FUN_01373fc0 (slot 8) reads through the pointer
 * at +0x38 and FUN_01373fd0 (slot 15) clears it. Class and method unknown. */
struct Target01373fc0; /* derived name */

struct Object01373fc0 { /* derived name */
    u8 unknown0[0x38];
    Target01373fc0 *unknown38;
};

int FUN_00ca41b0(Object01373fc0 *self, Target01373fc0 *const *value) /* derived name */
{
    self->unknown38 = *value;
    return 1;
}
