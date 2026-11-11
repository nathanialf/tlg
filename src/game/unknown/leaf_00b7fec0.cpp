/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x48 of the record at +0x58 of the
 * object the pointer at 0x57c9390 holds and the object itself to FUN_00b46d00,
 * a tail call; slot 7 of the vtable at 0x16b6dc8 (its pointer at 0x16b6e10),
 * stored by FUN_00b7dea0 and five more; slot 7 of the vtable at 0x16b6e28 (its
 * pointer at 0x16b6e70), stored by FUN_00b7ff00; slot 7 of the vtable at
 * 0x16b6e88 (its pointer at 0x16b6ed0), stored by FUN_00b80e50; slot 7 of the
 * vtable at 0x16b6ee8 (its pointer at 0x16b6f30), stored by FUN_00b81ae0. The
 * callee keeps its second argument (a store of rsi in its frame). The classes
 * and the callee's return type are not traced. */
struct Object00b7fec0;       /* derived name */
struct Member057c9390_58_48; /* derived name */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x48];
    Member057c9390_58_48 *unknown48;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58;
};

extern Object057c9390 *D_57c9390;

void FUN_00b46d00(Member057c9390_58_48 *member, Object00b7fec0 *object); /* derived name */

void FUN_00b7fec0(Object00b7fec0 *self) /* derived name */
{
    FUN_00b46d00(D_57c9390->unknown58->unknown48, self);
}
