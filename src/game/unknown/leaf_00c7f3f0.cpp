/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets bit 0 of the int at +0x240 of the object its second
 * argument points to when bit 2 is set; the first argument is unused; slot 8
 * of the vtable at 0x16b8748 (its pointer at 0x16b8798), the vtable stored by
 * FUN_00c68d00 FUN_00c68f80. Class and method unknown. */
struct Object00c7f3f0; /* derived name */

struct Target00c7f3f0 { /* derived name */
    u8 unknown0[0x240];
    int unknown240;
};

void FUN_00c7f3f0(Object00c7f3f0 *, Target00c7f3f0 *target) /* derived name */
{
    if (target->unknown240 & 4) {
        target->unknown240 |= 1;
    }
}
