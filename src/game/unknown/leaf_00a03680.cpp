/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x30 of the record at +0x58 of the
 * object the pointer at 0x57c9390 holds and the object itself to FUN_00a01f50,
 * a tail call; slot 8 of the vtable at 0x16b1af0 (its pointer at 0x16b1b40),
 * stored by FUN_00a02870, FUN_00a033c0 and FUN_00a034e0. The callee keeps its
 * second argument (a store of rsi in its frame). The classes and the callee's
 * return type are not traced. */
struct Object00a03680;       /* derived name */
struct Member057c9390_58_30; /* derived name */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x30];
    Member057c9390_58_30 *unknown30;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58;
};

extern Object057c9390 *D_57c9390;

void FUN_00a01f50(Member057c9390_58_30 *member, Object00a03680 *object); /* derived name */

void FUN_00a03680(Object00a03680 *self) /* derived name */
{
    FUN_00a01f50(D_57c9390->unknown58->unknown30, self);
}
