/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x50 of the record at +0x58 of the
 * object the pointer at 0x57c9390 holds and the object itself to FUN_00b49990,
 * a tail call; slot 8 of the vtable at 0x16b7058 (its pointer at 0x16b70a8),
 * stored by FUN_00b85c60 and FUN_00b866d0. The callee keeps its second
 * argument (a store of rsi in its frame). The classes and the callee's return
 * type are not traced. */
struct Object00b87d80;       /* derived name */
struct Member057c9390_58_50; /* derived name */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x50];
    Member057c9390_58_50 *unknown50;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58;
};

extern Object057c9390 *D_57c9390;

void FUN_00b49990(Member057c9390_58_50 *member, Object00b87d80 *object); /* derived name */

void FUN_00b87d80(Object00b87d80 *self) /* derived name */
{
    FUN_00b49990(D_57c9390->unknown58->unknown50, self);
}
