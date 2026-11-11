/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0xf8 of the object the pointer at
 * 0x5938c40 holds to FUN_00ca7880, a tail call; slot 5 of the vtable at
 * 0x16d0ad8 (its pointer at 0x16d0b10), one of the 109 vtables whose slot 0 is
 * the destructor of Object013a6a50 (FUN_013a6a50). The object itself is not
 * read. The callee's other parameters and its return type are not traced;
 * FUN_00ca7880 is taken to take the one pointer. */
class Object013a6a50;     /* derived name */
struct Member05938c40_f8; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf8];
    Member05938c40_f8 *unknownf8;
};

extern Object05938c40 *D_5938c40;

void FUN_00ca7880(Member05938c40_f8 *member); /* derived name */

void FUN_013a38e0(Object013a6a50 *) /* derived name */
{
    FUN_00ca7880(D_5938c40->unknownf8);
}
