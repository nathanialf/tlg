/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b6dc8.h"

/* derived names: passes the pointer at +0x48 of the record at +0x58 of the
 * object the pointer at 0x57c9390 holds and the object itself to FUN_00b46d00,
 * a tail call; slot 7 of the vtable at 0x16b6dc8 (its pointer at 0x16b6e10),
 * stored by FUN_00b7dea0 and five more, and of the three classes over it
 * (vtables 0x16b6e28, 0x16b6e88, 0x16b6ee8). The first virtual of
 * Object016b6dc8 defined out of line: this unit emits its vtable and its two
 * destructors (FUN_00b7f5f0, FUN_00b7f710). The callee keeps its second
 * argument (a store of rsi in its frame). The callee's return type is not
 * traced. */
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

void FUN_00b46d00(Member057c9390_58_48 *member, Object016b6dc8 *object); /* derived name */

void Object016b6dc8::FUN_001af750()
{
    FUN_00b46d00(D_57c9390->unknown58->unknown48, this);
}
