/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

void FUN_00208b90(Float4A *rotation, float fromX, float fromY, float fromZ, float toX, float toY,
                  float toZ); /* derived name */

/* LuaBindings::VectorLookatQuat (the name FUN_00e80560's registration gives
 * the VM for it): with exactly two userdata arguments, the rotation
 * FUN_00208b90 makes from their vectors' first three floats is pushed
 * (FUN_00c8ab10) and 1 is returned; else 0 (no results). The row keeps its
 * FUN_ name until a ruling, as leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int VectorLookatQuat(lua_State *state)
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count == 2 && typeOf(state, 1) == 7 && typeOf(state, 2) == 7) {
        const Float4 &a = userdataValue(state, 1);
        const Float4 &b = userdataValue(state, 2);
        Float4A rotation;
        FUN_00208b90(&rotation, a.x, a.y, a.z, b.x, b.y, b.z);
        FUN_00c8ab10(state, &rotation);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
