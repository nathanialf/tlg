/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the float at +0x40 is at most 0 (as an int)
 * of the record at +0x100 of the object the pointer at 0x57c9390 holds; slot 2
 * of the vtable at 0x16af870 (its pointer at 0x16af890), stored by
 * FUN_0088b4e0, its slots 0 and 1 FUN_008b0300 and FUN_008b0340. The object
 * itself is not read. */
struct Object008b0380; /* derived name */

struct Member057c9390_100 { /* derived name */
    u8 unknown0[0x40];
    float unknown40;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x100];
    Member057c9390_100 *unknown100;
};

extern Object057c9390 *D_57c9390;

int FUN_008b0380(Object008b0380 *) /* derived name */
{
    return D_57c9390->unknown100->unknown40 <= 0.0f;
}
