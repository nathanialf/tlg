/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_002178a0 on the object its second argument points
 * to when bit 1 of its int at +0x34 is set, as a tail call; the first argument
 * is unused; slot 5 of the vtable at 0x16c70f8 (its pointer at 0x16c7130), the
 * vtable stored by FUN_00e87bb0. Class and method unknown. */
struct Object01345ec0; /* derived name */

struct Target01345ec0 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
};

void FUN_002178a0(Target01345ec0 *target); /* derived name */

void FUN_01345ec0(Object01345ec0 *, Target01345ec0 *target) /* derived name */
{
    if (target->unknown34 & 2) {
        FUN_002178a0(target);
    }
}
