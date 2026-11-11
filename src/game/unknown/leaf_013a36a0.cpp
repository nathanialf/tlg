/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the pointer at +0xd0 of the object the pointer at
 * 0x5938c40 holds and 0 to FUN_00c628d0, a tail call; slot 5 of the vtable at
 * 0x16d07c0 (its pointer at 0x16d07f8, stored by FUN_00c3a520), one of the 109
 * vtables whose slot 0 is the destructor of Object013a6a50 (FUN_013a6a50). The
 * object itself is not read. The callee stores its second argument as a 32-bit
 * value; its other parameters and return type are not traced. */
class Object013a6a50;     /* derived name */
struct Member05938c40_d0; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0xd0];
    Member05938c40_d0 *unknownd0;
};

extern Object05938c40 *D_5938c40;

void FUN_00c628d0(Member05938c40_d0 *member, int value); /* derived name */

void FUN_013a36a0(Object013a6a50 *) /* derived name */
{
    FUN_00c628d0(D_5938c40->unknownd0, 0);
}
