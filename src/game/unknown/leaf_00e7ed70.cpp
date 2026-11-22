/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorNormalize3 (the name FUN_00e80560's registration gives
 * the VM for it, under the key "Normalize3"): with a userdata argument, the
 * length of its vector's first three floats is taken; the vector divided by
 * it (by 1 when the length is under 1e-5, the four floats at once) is
 * pushed, zero for a length under 1e-5, with the vector's own fourth float,
 * then the length as a number, and 2 is returned; else 0 (no results). The
 * row keeps its FUN_ name until a ruling, as leaf_00e7e520.cpp's. */
namespace LuaBindings
{

// NONMATCHING: the vector's loads and the divisor: the base reads the first three floats apart
// for the length and the four at once for the quotient, and picks the divisor's vector by a branch
// (ones, or the length in every lane); the build takes the three from the four-float load and
// selects the scalar before one splat
int VectorNormalize3(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0 && typeOf(state, 1) == 7) {
        const Float4 &a = userdataValue(state, 1);
        Float4A v(a.x, a.y, a.z, a.w);
        float length = sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
        Float4A d = length < 1e-5f ? Float4A(1.0f, 1.0f, 1.0f, 1.0f)
                                   : Float4A(length, length, length, length);
        Float4A q(v.x / d.x, v.y / d.y, v.z / d.z, v.w / d.w);
        Float4A zero(0.0f, 0.0f, 0.0f, 0.0f);
        const Float4A &n = length < 1e-5f ? zero : q;
        Float4A r(n.x, n.y, n.z, a.w);
        FUN_00c8aa70(state, &r);
        pushNumber(state, length);
        return 2;
    }
    return 0;
}

} // namespace LuaBindings
