/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets the byte at +0x110 of the object its second argument
 * points to when it is clear; the first argument is unused; slot 36 of the
 * vtable at 0x16aa8e0 (its pointer at 0x16aaa10), the vtable stored by
 * FUN_004f3ad0 FUN_004f3df0. Class and method unknown. */
struct Object00500910; /* derived name */

struct Target00500910 { /* derived name */
    u8 unknown0[0x110];
    bool unknown110;
};

void FUN_00500910(Object00500910 *, Target00500910 *target) /* derived name */
{
    if (!target->unknown110) {
        target->unknown110 = true;
    }
}
