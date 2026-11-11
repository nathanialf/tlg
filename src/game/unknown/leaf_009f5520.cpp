/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x10 of the record at +0x58 of the
 * object the pointer at 0x57c9390 holds and the object itself to FUN_009f5a00,
 * a tail call; slot 7 of the vtable at 0x16b1970 (its pointer at 0x16b19b8),
 * stored by FUN_009f4890 and FUN_009f52f0. The callee keeps its second
 * argument (a store of rsi in its frame). The classes and the callee's return
 * type are not traced. */
struct Object009f5520;       /* derived name */
struct Member057c9390_58_10; /* derived name */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x10];
    Member057c9390_58_10 *unknown10;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58;
};

extern Object057c9390 *D_57c9390;

void FUN_009f5a00(Member057c9390_58_10 *member, Object009f5520 *object); /* derived name */

void FUN_009f5520(Object009f5520 *self) /* derived name */
{
    FUN_009f5a00(D_57c9390->unknown58->unknown10, self);
}
