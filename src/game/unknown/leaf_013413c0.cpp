/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0xa8 of the object the pointer at
 * 0x57c9390 holds and 0 to FUN_0094d420, a tail call; slot 5 of the vtable at
 * 0x16c6d18 (its pointer at 0x16c6d50, stored by FUN_001bab90), one of the 109
 * vtables whose slot 0 is the destructor of Object013a6a50 (FUN_013a6a50). The
 * object itself is not read. The callee stores its second argument as a 32-bit
 * value; its other parameters and return type are not traced. */
class Object013a6a50;     /* derived name */
struct Member057c9390_a8; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0xa8];
    Member057c9390_a8 *unknowna8;
};

extern Object057c9390 *D_57c9390;

void FUN_0094d420(Member057c9390_a8 *member, int value); /* derived name */

void FUN_013413c0(Object013a6a50 *) /* derived name */
{
    FUN_0094d420(D_57c9390->unknowna8, 0);
}
