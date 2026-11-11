/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x120 of the object the pointer at
 * 0x57c9390 holds and the object itself to FUN_00a07550, a tail call; slot 7
 * of the vtable at 0x16b61b0 (its pointer at 0x16b61f8), stored by
 * FUN_00b47230. The callee keeps its second argument (a store of rsi in its
 * frame). The classes and the callee's return type are not traced. */
struct Object00b47aa0;     /* derived name */
struct Member057c9390_120; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x120];
    Member057c9390_120 *unknown120;
};

extern Object057c9390 *D_57c9390;

void FUN_00a07550(Member057c9390_120 *member, Object00b47aa0 *object); /* derived name */

void FUN_00b47aa0(Object00b47aa0 *self) /* derived name */
{
    FUN_00a07550(D_57c9390->unknown120, self);
}
