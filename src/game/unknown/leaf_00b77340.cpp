/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x38 of the record at +0x58 of the
 * object the pointer at 0x57c9390 holds and the object itself to FUN_00b45a40,
 * a tail call; slot 8 of the vtable at 0x16b6c20 (its pointer at 0x16b6c70),
 * stored by FUN_00b766d0, FUN_00b76da0, FUN_00b76ec0 and FUN_00b781a0; slot 8
 * of the vtable at 0x16b6c98 (its pointer at 0x16b6ce8), stored by
 * FUN_00b77360 and FUN_00b781a0. The callee keeps its second argument (a store
 * of rsi in its frame). The classes and the callee's return type are not
 * traced. */
struct Object00b77340;       /* derived name */
struct Member057c9390_58_38; /* derived name */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_58_38 *unknown38;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58;
};

extern Object057c9390 *D_57c9390;

void FUN_00b45a40(Member057c9390_58_38 *member, Object00b77340 *object); /* derived name */

void FUN_00b77340(Object00b77340 *self) /* derived name */
{
    FUN_00b45a40(D_57c9390->unknown58->unknown38, self);
}
