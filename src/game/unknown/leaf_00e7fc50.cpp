/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorRotateY (the name FUN_00e80560's registration gives the
 * VM for it): with a userdata argument and a number of degrees, its vector
 * turned about the y axis by that angle (y and w kept) is pushed
 * (FUN_00c8aa70) and 1 is returned; else 0 (no results). The row keeps its
 * FUN_ name until a ruling, as leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int VectorRotateY(lua_State *state)
{
    int count = state->top - state->base;
    if (count >= 2 && typeOf(state, 1) == 7 && typeOf(state, 2) == 3) {
        const Float4 &a = userdataValue(state, 1);
        const float angle = toNumber(state, 2) * (3.14159265f / 180.0f);
        const float c = cosf(angle);
        const float s = sinf(angle);
        Float4A r(a.x * c + a.z * s, a.y, -a.x * s + a.z * c, a.w);
        FUN_00c8aa70(state, &r);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
