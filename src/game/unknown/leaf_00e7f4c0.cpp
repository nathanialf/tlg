/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorAdd4 (the name FUN_00e80560's registration gives the
 * VM for it): with two userdata arguments, the sum of their four-float
 * vectors is pushed (FUN_00c8aa70) and 1 is returned; else 0 (no results).
 * The row keeps its FUN_ name until a ruling, as leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int VectorAdd4(lua_State *state)
{
    int count = state->top - state->base;
    if (count >= 2 && typeOf(state, 1) == 7 && typeOf(state, 2) == 7) {
        const Float4 &a = userdataValue(state, 1);
        const Float4 &b = userdataValue(state, 2);
        Float4A sum(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
        FUN_00c8aa70(state, &sum);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
