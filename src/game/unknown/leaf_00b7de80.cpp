/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x28 of the record at +0x58 of the
 * object the pointer at 0x57c9390 holds and the object itself to FUN_00b469f0,
 * a tail call; slot 8 of the vtable at 0x16b6d70 (its pointer at 0x16b6dc0),
 * stored by FUN_00b7d020, FUN_00b7dd00 and FUN_00b7ddb0. The callee keeps its
 * second argument (a store of rsi in its frame). The classes and the callee's
 * return type are not traced. */
struct Object00b7de80;       /* derived name */
struct Member057c9390_58_28; /* derived name */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x28];
    Member057c9390_58_28 *unknown28;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58;
};

extern Object057c9390 *D_57c9390;

void FUN_00b469f0(Member057c9390_58_28 *member, Object00b7de80 *object); /* derived name */

void FUN_00b7de80(Object00b7de80 *self) /* derived name */
{
    FUN_00b469f0(D_57c9390->unknown58->unknown28, self);
}
