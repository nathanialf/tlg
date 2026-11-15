/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the script math library's C function that pushes acosf of
 * its first argument (luaL_checknumber) and returns one result; beside
 * FUN_00de6d20 (asinf), FUN_00de6e00 (atanf), FUN_00de72d0 (expf),
 * FUN_00de7bb0 (tanf), FUN_00de7c90 */
int FUN_00de6c40(lua_State *state) /* derived name */
{
    pushNumber(state, acosf(luaL_checknumber(state, 1)));
    return 1;
}
