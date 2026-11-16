/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "PlayGoCheckStatus" (FUN_001bd010,
 * lea at 0x1db6da): with an argument, its number as an int selects a byte
 * of the array at +0x14 of the record at +0xf58 of the object the pointer at
 * 0x5938c40 holds; pushes whether it is nonzero and returns one result, else
 * returns 0 (no results). The array's extent is not traced. */
struct Member05938c40_f58 { /* derived name */
    u8 unknown0[0x14];
    u8 unknown14[1]; /* +0x14 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf58];
    Member05938c40_f58 *unknownf58;
};

extern Object05938c40 *D_5938c40;

int FUN_001b39b0(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count < 1) {
        return 0;
    }
    int index = toNumber(state, 1);
    pushBoolean(state, D_5938c40->unknownf58->unknown14[index] != 0);
    return 1;
}
