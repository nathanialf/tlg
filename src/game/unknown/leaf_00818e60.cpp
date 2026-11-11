/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the first time (the int at +0x34 still 0), sets that int to 1
 * and passes the pointer at +0x48 of the object the pointer at 0x57c9390 holds
 * and the object to FUN_0081a930, a tail call; slot 7 of the vtable at
 * 0x16ae7e0 (its pointer at 0x16ae828), stored by FUN_00818b00, FUN_00818ea0,
 * FUN_00845fb0, FUN_00846c90, FUN_008eeb00 and FUN_00b1b370. The object's
 * other fields and the callee's return type are not traced. */
struct Member057c9390_48; /* derived name */

struct Object00818e60 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x48];
    Member057c9390_48 *unknown48;
};

extern Object057c9390 *D_57c9390;

void FUN_0081a930(Member057c9390_48 *member, Object00818e60 *object); /* derived name */

void FUN_00818e60(Object00818e60 *self) /* derived name */
{
    if (self->unknown34 != 0)
        return;
    self->unknown34 = 1;
    FUN_0081a930(D_57c9390->unknown48, self);
}
