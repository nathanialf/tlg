/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the debug library's "getmetatable" (its entry in the table
 * at 0x16bc8e0): the first argument's metatable pushed, nil when it has
 * none; the argument must be given */
int FUN_00deb200(lua_State *state)
{
    luaL_checkany(state, 1);
    if (!getMetatable(state, 1))
        pushNil(state);
    return 1;
}
