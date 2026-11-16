/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorAdd3 (the name FUN_00e80560's registration gives the VM
 * for it): with two userdata arguments, the sum of their vectors' first
 * three floats, with the first's fourth, is pushed (FUN_00c8aa70) and 1 is
 * returned; else 0 (no results). Each sum is written second + first: the
 * base keeps the first's floats in registers and adds the second's from
 * memory. The row keeps its FUN_ name until a ruling, as
 * leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int VectorAdd3(lua_State *state)
{
    int count = state->top - state->base;
    if (count >= 2 && typeOf(state, 1) == 7 && typeOf(state, 2) == 7) {
        const Float4 &a = userdataValue(state, 1);
        const Float4 &b = userdataValue(state, 2);
        Float4 r(b.x + a.x, b.y + a.y, b.z + a.z, a.w);
        FUN_00c8aa70(state, &r);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
