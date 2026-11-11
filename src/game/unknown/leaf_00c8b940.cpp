/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that sets the int at +0xf80 of the object
 * the pointer at 0x5938c40 holds to 1 and returns 0 (no results). FUN_00c83870
 * registers it (lea at 0xc856db) through FUN_00dd6ba0, the VM's push of a
 * named C function, under the script name "DiscardVelocityMap"; the VM's
 * strings name lua_State. The C function's own name is unknown. */
struct lua_State;

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf80];
    int unknownF80;
};

extern Object05938c40 *D_5938c40;

int FUN_00c8b940(lua_State *state) /* derived name */
{
    D_5938c40->unknownF80 = 1;
    return 0;
}
