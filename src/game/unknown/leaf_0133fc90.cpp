/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0x118 of the object the pointer at
 * 0x57c9390 holds to FUN_00a07df0, a tail call; slot 5 of the vtable at
 * 0x16c6a00 (its pointer at 0x16c6a38), one of the 109 vtables whose slot 0 is
 * the destructor of Object013a6a50 (FUN_013a6a50). The object itself is not
 * read. The callee's other parameters and its return type are not traced;
 * FUN_00a07df0 is taken to take the one pointer. */
class Object013a6a50;      /* derived name */
struct Member057c9390_118; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x118];
    Member057c9390_118 *unknown118;
};

extern Object057c9390 *D_57c9390;

void FUN_00a07df0(Member057c9390_118 *member); /* derived name */

void FUN_0133fc90(Object013a6a50 *) /* derived name */
{
    FUN_00a07df0(D_57c9390->unknown118);
}
