/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0xa8 of the object the pointer at
 * 0x57c9390 holds and the object itself to FUN_009483a0, a tail call; slot 9
 * of the vtables at 0x16b0d90 (stored by FUN_00924230 and FUN_0137c320) and
 * 0x16c79e0 (stored by FUN_00924230 and FUN_0092a190). The callee keeps its
 * second argument (a store of rsi in its frame). The classes and the callee's
 * return type are not traced. */
struct Object0092ac50;    /* derived name */
struct Member057c9390_a8; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0xa8];
    Member057c9390_a8 *unknowna8;
};

extern Object057c9390 *D_57c9390;

void FUN_009483a0(Member057c9390_a8 *member, Object0092ac50 *object); /* derived name */

void FUN_0092ac50(Object0092ac50 *self) /* derived name */
{
    FUN_009483a0(D_57c9390->unknowna8, self);
}
