/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the pointer at +0x70 of the object the pointer at
 * 0x57c9390 holds is not null and the int at +0xf38 of the object the pointer
 * at 0x5938c40 holds is not 1, passes that pointer and the object to
 * FUN_007f1100, a tail call; slot 8 of the vtable at 0x16ae1c0 (its pointer at
 * 0x16ae210), stored by FUN_007f8f10 and FUN_007f9370. The types and the
 * callee's return type are not traced. */
struct Member057c9390_70; /* derived name */
struct Object00805330;    /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x70];
    Member057c9390_70 *unknown70;
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf38];
    int unknownf38;
};

extern Object057c9390 *D_57c9390;
extern Object05938c40 *D_5938c40;

void FUN_007f1100(Member057c9390_70 *member, Object00805330 *object); /* derived name */

void FUN_00805330(Object00805330 *self) /* derived name */
{
    Member057c9390_70 *member = D_57c9390->unknown70;
    if (!member || D_5938c40->unknownf38 == 1)
        return;
    FUN_007f1100(member, self);
}
