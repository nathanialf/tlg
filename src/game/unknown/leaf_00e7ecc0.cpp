/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorLength3 (the name FUN_00e80560's registration gives the
 * VM for it): with a userdata argument, the length of its vector's first
 * three floats is pushed as a number and 1 is returned; else 0 (no results).
 * The row keeps its FUN_ name until a ruling, as leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int VectorLength3(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0 && typeOf(state, 1) == 7) {
        const Float4 &a = userdataValue(state, 1);
        pushNumber(state, sqrtf(a.x * a.x + a.y * a.y + a.z * a.z));
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
