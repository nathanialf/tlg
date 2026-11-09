/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when bit 4 (0x10) of the flags at +0x20 of its argument is
 * set, clears it and calls FUN_00cbd9b0 with the argument as a tail call; the
 * object is unused; slot 14 of the vtable at 0x16b9108 (its pointer at
 * 0x16b9188). Class and method unknown. */
struct Object00cbdb10; /* derived name */

struct Target00cbdb10 { /* derived name */
    u8 unknown0[0x20];
    u32 unknown20; /* flags */
};

void FUN_00cbd9b0(Target00cbdb10 *target); /* derived name */

void FUN_00cbdb10(Object00cbdb10 *, Target00cbdb10 *target) /* derived name */
{
    u32 flags = target->unknown20;
    if (flags & 0x10) {
        target->unknown20 = flags & ~0x10u;
        FUN_00cbd9b0(target);
    }
}
