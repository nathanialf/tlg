/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* The script string library's "len" (its table at 0x16bcfa0, name and
 * function in turn): the length of its string argument. */
int FUN_00de1400(lua_State *state) /* derived name */
{
    size_t length = 0;
    hksi_luaL_checklstring(state, 1, &length);
    pushInteger(state, length);
    return 1;
}
