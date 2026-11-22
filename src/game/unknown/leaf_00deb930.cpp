/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: Lua's lua_setmetatable by its arguments: the object's
 * metatable set to the value given (FUN_00d971b0, its body not written) */
void FUN_00d971b0(lua_State *state, const HksObject *object, const HksObject *metatable);

/* derived name: the debug library's "setmetatable" (its entry in the table
 * at 0x16bc940): the first argument's metatable set to the second, nil, a
 * table or a struct; pushes true */
// NONMATCHING: after settop's loop the base stores the top before it reads the base again (`mov [rbx+0x48], rcx; mov rsi, [rbx+0x50]`); here GVN PRE puts the load first
int FUN_00deb930(lua_State *state)
{
    luaL_checkany(state, 1);
    const HksObject *metatable = state->base + 1;
    const int type = metatable < state->top ? metatable->type & 0xf : -1;
    if (!(type == 0 || type == 5 || type == 12))
        FUN_00dd3450(state, 2, "nil, table or struct expected");
    setTop(state, 2);
    const HksObject *object = state->base;
    if (object < state->top) {
        FUN_00d971b0(state, object, state->top - 1);
        --state->top;
    }
    pushBoolean(state, true);
    return 1;
}
