/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x18 of the record at +0x58 of the
 * object the pointer at 0x57c9390 holds and the object itself to FUN_009f9a70,
 * a tail call; slot 8 of the vtable at 0x16b19f0 (its pointer at 0x16b1a40),
 * stored by FUN_009f5dd0, FUN_009f6990 and FUN_009f6ab0. The callee keeps its
 * second argument (a store of rsi in its frame). The classes and the callee's
 * return type are not traced. */
struct Object009f6cc0;       /* derived name */
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

void FUN_009f9a70(Member057c9390_58_18 *member, Object009f6cc0 *object); /* derived name */

void FUN_009f6cc0(Object009f6cc0 *self) /* derived name */
{
    FUN_009f9a70(D_57c9390->unknown58->unknown18, self);
}
