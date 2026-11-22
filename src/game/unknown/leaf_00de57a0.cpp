/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the package library's "loadlib" (its entry in the table at
 * 0x16bcdf0): the path and the function's name checked as strings, nothing
 * loaded; no results */
int FUN_00de57a0(lua_State *state)
{
    hksi_luaL_checklstring(state, 1, 0);
    hksi_luaL_checklstring(state, 2, 0);
    return 0;
}
