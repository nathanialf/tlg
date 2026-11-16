/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::QuatMul (the name FUN_00e80560's registration gives the VM
 * for it under the key "__mul", lea at 0xe8165a): with two arguments that are
 * userdata (type 7), the product of their rotations (FUN_013439c0, as
 * leaf_013e3840.cpp declares it; each value at +0x20 of its userdata) is
 * pushed (FUN_00c8ab10) and 1 is returned; else 0 (no results). The row keeps
 * its FUN_ name until a ruling, as leaf_00e7e520.cpp's. derived names
 * otherwise. */
void FUN_013439c0(Float4 *product, const Float4 *first, const Float4 *second); /* derived name */

namespace LuaBindings
{

int QuatMul(lua_State *state)
{
    int count = state->top - state->base;
    if (count >= 2 && typeOf(state, 1) == 7 && typeOf(state, 2) == 7) {
        const Float4 &first = userdataValue(state, 1);
        const Float4 &second = userdataValue(state, 2);
        Float4 product;
        FUN_013439c0(&product, &first, &second);
        FUN_00c8ab10(state, &product);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
