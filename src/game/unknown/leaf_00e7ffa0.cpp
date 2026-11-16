/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::QuatToEuler (the name FUN_00e80560's registration gives the
 * VM for it): with a userdata argument, the angles of its rotation
 * (FUN_0134ab60) are pushed as a vector (FUN_00c8aa70) and 1 is returned;
 * else 0 (no results). The row keeps its FUN_ name until a ruling, as
 * leaf_00e7e520.cpp's. derived names otherwise. */
void FUN_0134ab60(Float4A *angles, const Float4 *rotation); /* derived name */

namespace LuaBindings
{

int QuatToEuler(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0 && typeOf(state, 1) == 7) {
        Float4A angles;
        FUN_0134ab60(&angles, &userdataValue(state, 1));
        FUN_00c8aa70(state, &angles);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
