/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets bit 4 of the byte at +0x34, then passes the pointer at
 * +0x18 of the record at +0x58 of the object the pointer at 0x57c9390 holds
 * and the object itself to FUN_009f94d0, a tail call; slot 7 of the vtable at
 * 0x16b1a48 (its pointer at 0x16b1a90), stored by FUN_009f6ce0 and
 * FUN_009f88d0. The callee keeps its second argument (a store of rsi in its
 * frame). The classes and the callee's return type are not traced. */
struct Object009f8890 { /* derived name */
    u8 unknown0[0x34];
    u8 unknown34;
};
struct Member057c9390_58_18; /* derived name */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x18];
    Member057c9390_58_18 *unknown18;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58;
};

extern Object057c9390 *D_57c9390;

void FUN_009f94d0(Member057c9390_58_18 *member, Object009f8890 *object); /* derived name */

void FUN_009f8890(Object009f8890 *self) /* derived name */
{
    self->unknown34 |= 0x10;
    FUN_009f94d0(D_57c9390->unknown58->unknown18, self);
}
