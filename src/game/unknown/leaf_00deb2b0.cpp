/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the debug library's "getregistry" (its entry in the table
 * at 0x16bc8f0): the registry pushed */
int FUN_00deb2b0(lua_State *state)
{
    hksi_lua_pushRegistry(state);
    return 1;
}
