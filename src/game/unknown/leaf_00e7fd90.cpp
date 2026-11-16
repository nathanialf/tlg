/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

void FUN_0020c3b0(Float4A *rotation, float x, float y, float z); /* derived name */

/* LuaBindings::VectorEulerToQuat (the name FUN_00e80560's registration gives
 * the VM for it): with a userdata argument, the rotation of its vector's
 * three angles (FUN_0020c3b0, as leaf_00e7ff00.cpp's) is pushed
 * (FUN_00c8ab10) and 1 is returned; else 0 (no results). The row keeps its
 * FUN_ name until a ruling, as leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int VectorEulerToQuat(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0 && typeOf(state, 1) == 7) {
        const Float4 &a = userdataValue(state, 1);
        Float4A rotation;
        FUN_0020c3b0(&rotation, a.x, a.y, a.z);
        FUN_00c8ab10(state, &rotation);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
