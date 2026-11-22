/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_luaL_getmetafield (the name from its assertion message, FUN_00d95c10)
 * and the value's text pushed without a metamethod (FUN_00dd54f0, derived
 * name); their bodies not written */
int FUN_00d95c10(lua_State *s, int obj, const char *event);
void FUN_00dd54f0(lua_State *state, int argument);

/* hksi_lua_call (FUN_00d95e60) */
void FUN_00d95e60(lua_State *s, int nargs, int nresults);

/* Lua's luaL_callmeta, inlined: the metamethod `event` of a value called
 * with the value, its result pushed; 0 without one. The call timed. */
inline int luaL_callmeta(lua_State *s, int obj, const char *event)
{
    HksApiTimer timer(s);
    if (!FUN_00d95c10(s, obj, event))
        return 0;
    pushValue(s, obj);
    FUN_00d95e60(s, 1, 1);
    return 1;
}

/* derived name: Lua's tostring: the first argument's __tostring result,
 * else its text */
int FUN_00dedf90(lua_State *state)
{
    luaL_checkany(state, 1);
    setTop(state, 1);
    if (!luaL_callmeta(state, 1, "__tostring"))
        FUN_00dd54f0(state, 1);
    return 1;
}
