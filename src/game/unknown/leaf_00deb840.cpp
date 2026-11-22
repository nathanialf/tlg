/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: gives the function on the stack's top the name, popping it
 * (FUN_00db6800, its body not written) */
void FUN_00db6800(lua_State *state, const char *name);

/* derived name: the debug library's "setfname" (its entry in the table at
 * 0x16bc930): the first argument, a function, named by the second, a
 * string; no results */
int FUN_00deb840(lua_State *state)
{
    hksi_luaL_checktype(state, 1, 6, "function");
    const HksObject *value = state->base + 1;
    const char *name = value < state->top ? FUN_00db6b20(state, value, 0) : 0;
    if (!name)
        FUN_00dd38c0(state, 2, "string");
    pushValue(state, 1);
    FUN_00db6800(state, name);
    return 0;
}
