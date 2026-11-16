/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorLengthXZ (the name FUN_00e80560's registration gives the VM
 * for it): with a userdata, a userdata and a number,
 * the square root of the sum of the products of the two vectors' x and z
 * is pushed as a number and 1 is returned; else 0 (no results). The
 * number is tested and not read. The row keeps its FUN_ name until a ruling, as
 * leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int VectorLengthXZ(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0 && typeOf(state, 1) == 7 && typeOf(state, 2) == 7 && typeOf(state, 3) == 3) {
        const Float4 &a = userdataValue(state, 1);
        const Float4 &b = userdataValue(state, 2);
        pushNumber(state, sqrtf(a.x * b.x + a.z * b.z));
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
