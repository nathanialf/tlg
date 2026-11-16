/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorLerp3 (the name FUN_00e80560's registration gives the VM
 * for it): with two userdata arguments and a number t,
 * the first's vector moved toward the second's by t in its first three
 * floats (its fourth kept) is pushed (FUN_00c8aa70) and 1 is returned;
 * else 0 (no results). The row keeps its FUN_ name until a ruling, as
 * leaf_00e7e520.cpp's. */
namespace LuaBindings
{

// NONMATCHING: instruction order only: the base loads and computes y before x (b.y, a.y, b.x,
// a.x, then b.z before the w word); 77/89, three forms compiled
int VectorLerp3(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0 && typeOf(state, 1) == 7 && typeOf(state, 2) == 7 && typeOf(state, 3) == 3) {
        const Float4 &a = userdataValue(state, 1);
        const Float4 &b = userdataValue(state, 2);
        float t = toNumber(state, 3);
        Float4A r((b.x - a.x) * t + a.x, (b.y - a.y) * t + a.y, (b.z - a.z) * t + a.z, a.w);
        FUN_00c8aa70(state, &r);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
