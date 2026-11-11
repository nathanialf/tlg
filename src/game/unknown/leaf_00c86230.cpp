/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback that passes the pointer at +0x40 of the object the
 * pointer at 0x5938c40 holds and its third argument to FUN_00c89850 and
 * returns 0. FUN_00c83870 registers it (lea at 0xc84586) through FUN_00d43e50
 * with the record at +0x38 of that object, the string "lua" and 3. Its first
 * two arguments are unused; the types are not traced. */
struct Member05938c40_40; /* derived name */
struct Argument00c86230;  /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x40];
    Member05938c40_40 *unknown40;
};

extern Object05938c40 *D_5938c40;

void FUN_00c89850(Member05938c40_40 *member, Argument00c86230 *argument); /* derived name */

int FUN_00c86230(void *, void *, Argument00c86230 *argument) /* derived name */
{
    FUN_00c89850(D_5938c40->unknown40, argument);
    return 0;
}
