/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorMul3 (the name FUN_00e80560's registration gives the VM
 * for it): with a userdata argument and a second that
 * is a userdata or a number, the product of the first's vector by the
 * second's (first three floats, with the first's fourth, by component) or by the number is pushed
 * (FUN_00c8aa70) and 1 is returned; else 0 (no results). The row keeps its FUN_ name until a ruling, as
 * leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int VectorMul3(lua_State *state)
{
    int count = state->top - state->base;
    if (count >= 2 && typeOf(state, 1) == 7) {
        if (typeOf(state, 2) == 7) {
            const Float4 &a = userdataValue(state, 1);
            const Float4 &b = userdataValue(state, 2);
            Float4A r(b.x * a.x, b.y * a.y, b.z * a.z, a.w);
            FUN_00c8aa70(state, &r);
            return 1;
        } else if (typeOf(state, 2) == 3) {
            const Float4 &a = userdataValue(state, 1);
            float s = toNumber(state, 2);
            Float4A r(a.x * s, a.y * s, a.z * s, a.w);
            FUN_00c8aa70(state, &r);
            return 1;
        }
    }
    return 0;
}

} // namespace LuaBindings
