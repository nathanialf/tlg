/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the dump's writer: each piece added to the buffer given
 * (Lua's writer in lstrlib.c) */
// NONMATCHING: the loop: the base loads p before it (`mov rdi, [r14]` before `lea r13`) and again after the
// flush, the head reading it in a register; here the head loads it
static int FUN_00de2770(lua_State *, const void *piece, size_t size, void *buffer)
{
    hksi_luaL_addlstring(static_cast<luaL_Buffer *>(buffer), static_cast<const char *>(piece),
                         size);
    return 0;
}

/* derived names: Lua's lua_dump by its arguments (FUN_00dd70f0) and the
 * error raised with a message (FUN_00dbe320); their bodies not written */
int FUN_00dd70f0(lua_State *state, int (*writer)(lua_State *, const void *, size_t, void *),
                 void *data);
int FUN_00dbe320(lua_State *state, const char *format, ...);

/* derived name: the string library's "dump" (its entry in the table at
 * 0x16bd080): the first argument, a function, dumped into a string */
// NONMATCHING: instruction order only: the base forms the writer's address (`lea rsi`) after the buffer's
// two addresses and stores the top first
int FUN_00de2610(lua_State *state)
{
    luaL_Buffer b;
    hksi_luaL_checktype(state, 1, 6, "function");
    setTop(state, 1);
    hksi_luaL_buffinit(state, &b);
    if (FUN_00dd70f0(state, FUN_00de2770, &b) != 0)
        FUN_00dbe320(state, "unable to dump the function given");
    else
        luaL_pushresult(&b);
    return 1;
}
