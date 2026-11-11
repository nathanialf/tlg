/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x68 of the object the pointer at
 * 0x57c9390 holds and the object itself to FUN_00829210, a tail call; slot 8
 * of eight vtables: 0x16a8830 (stored by FUN_00344a60), 0x16a89f8
 * (FUN_0035b770), 0x16aaf60 (FUN_00510130), 0x16ab140 (FUN_00510fa0),
 * 0x16ac180 (FUN_006743e0), 0x16c7608, 0x16c7948 (whose slot 0 is the
 * destructor of Object008227e0) and 0x16cb520. The callee keeps its second
 * argument (a store of rsi in its frame). The classes and the callee's return
 * type are not traced. */
struct Object00822af0;    /* derived name */
struct Member057c9390_68; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x68];
    Member057c9390_68 *unknown68;
};

extern Object057c9390 *D_57c9390;

void FUN_00829210(Member057c9390_68 *member, Object00822af0 *object); /* derived name */

void FUN_00822af0(Object00822af0 *self) /* derived name */
{
    FUN_00829210(D_57c9390->unknown68, self);
}
