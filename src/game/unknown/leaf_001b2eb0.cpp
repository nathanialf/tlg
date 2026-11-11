/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that passes the pointer at +0x108 of the
 * object the pointer at 0x57c9390 holds to FUN_00a26130 and returns 0 (no
 * results). FUN_001bd010 registers it (lea at 0x1db49a) through FUN_00c87e30
 * under the script name "SavePerpetual"; the VM's strings name lua_State. The
 * C function's own name is unknown. */
struct lua_State;

struct Member057c9390_108; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

void FUN_00a26130(Member057c9390_108 *member); /* derived name */

int FUN_001b2eb0(lua_State *state) /* derived name */
{
    FUN_00a26130(D_57c9390->unknown108);
    return 0;
}
