/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the table of flag names at 0x5814688 that FUN_0069d690
 * fills (FUN_00d0c810) and leaves its address at 0x5814670; FUN_00d0c9f0
 * returns the bits the names of a list separated by '|' stand for (its
 * body not written) */
struct FlagNames05814688 { /* derived name */
    unsigned FUN_00d0c9f0(const char *names);
};

extern FlagNames05814688 *D_5814670; /* derived name */

/* derived name: an argument's string, null past the frame's top (as
 * leaf_00e7d320.cpp's) */
static inline const char *toString(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    return value < state->top ? FUN_00db6b20(state, value, 0) : 0;
}

/* derived names: the script C function FUN_001db8b0 registers (lea at
 * 0x1dd7ef) under the script name "bit_test" (its description "bit test"):
 * with two arguments, pushes whether the bit the second numbers (from 1) is
 * set among the bits the first's flag names stand for, and returns 1; else
 * returns 0. The C function's own name is unknown. */
int FUN_006e1cc0(lua_State *state) /* derived name */
{
    if (argumentCount(state) != 2)
        return 0;
    const unsigned bits = D_5814670->FUN_00d0c9f0(toString(state, 1));
    const int bit = int(toNumber(state, 2)) - 1;
    pushBoolean(state, (bits >> bit) & 1);
    return 1;
}
