/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x40 of the record at +0x58 of the
 * object the pointer at 0x57c9390 holds and the object itself to FUN_00b492e0,
 * a tail call; slot 7 of the vtable at 0x16b6f48 (its pointer at 0x16b6f90),
 * stored by FUN_00b828e0 and FUN_00b838e0. The callee keeps its second
 * argument (a store of rsi in its frame). The classes and the callee's return
 * type are not traced. */
struct Object00b83d10;       /* derived name */
struct Member057c9390_58_40; /* derived name */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x40];
    Member057c9390_58_40 *unknown40;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58;
};

extern Object057c9390 *D_57c9390;

void FUN_00b492e0(Member057c9390_58_40 *member, Object00b83d10 *object); /* derived name */

void FUN_00b83d10(Object00b83d10 *self) /* derived name */
{
    FUN_00b492e0(D_57c9390->unknown58->unknown40, self);
}
