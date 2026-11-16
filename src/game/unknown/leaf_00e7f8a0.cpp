/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorCross4 (the name FUN_00e80560's registration gives the VM
 * for it): with two userdata arguments, the cross
 * product of their vectors' first three floats, with a fourth of 0, is
 * pushed (FUN_00c8aa70) and 1 is returned; else 0 (no results). The row keeps its FUN_ name until a ruling, as
 * leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int VectorCross4(lua_State *state)
{
    int count = state->top - state->base;
    if (count >= 2 && typeOf(state, 1) == 7 && typeOf(state, 2) == 7) {
        const Float4 &a = userdataValue(state, 1);
        const Float4 &b = userdataValue(state, 2);
        Float4A r(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
        FUN_00c8aa70(state, &r);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
