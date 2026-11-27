/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: a C function (its address taken by FUN_00c83870): the
 * first argument read as a string (FUN_00db6b20, a number made one in its
 * slot) when the frame holds one, the string not used, and no results */
int FUN_00c871e0(lua_State *state)
{
    if (state->base < state->top) {
        FUN_00db6b20(state, state->base, 0);
    }
    return 0;
}
