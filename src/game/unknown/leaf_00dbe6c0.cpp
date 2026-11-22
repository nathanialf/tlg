/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: Lua's luaL_optlstring (FUN_00dd50c0) and the loader of a
 * buffer under the compiler's settings, Lua's luaL_loadbuffer
 * (FUN_00dd4dd0); their bodies not written */
const char *FUN_00dd50c0(lua_State *state, int argument, const char *def, size_t *length);
int FUN_00dd4dd0(lua_State *state, HksGlobal::HksCompilerSettings *settings, const char *buffer,
                 size_t size, const char *name);

/* derived name: the base library's "loadstring" (its entry in the table at
 * 0x16bc800): the first argument compiled as a chunk named by the second
 * (the text itself by default); on failure nil and the message */
// NONMATCHING: after the insert's moves the base stores the top once more (`mov [rbx+0x48], rcx` before the
// return); everything else equal
int FUN_00dbe6c0(lua_State *state)
{
    size_t l = 0;
    const char *s = hksi_luaL_checklstring(state, 1, &l);
    const char *chunkname = FUN_00dd50c0(state, 2, s, 0);
    if (FUN_00dd4dd0(state, &state->global->compilerSettings, s, l, chunkname) == 0)
        return 1;
    pushNil(state);
    hksi_lua_insert(state, -2);
    return 2;
}
