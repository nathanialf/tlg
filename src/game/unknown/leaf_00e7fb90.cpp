/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorRotate (the name FUN_00e80560's registration gives the
 * VM for it under the key "Rotate", lea at 0xe80fed): with two arguments that
 * are userdata (type 7), the first's vector rotated by the second's rotation
 * (FUN_01343bb0, each value at +0x20 of its userdata) is pushed (FUN_00c8aa70)
 * and 1 is returned; else 0 (no results). The row keeps its FUN_ name until a
 * ruling, as leaf_00e7e520.cpp's. derived names otherwise. */
void FUN_01343bb0(Float4A *rotated, const Float4 *vector,
                  const Float4 *rotation); /* derived name */

namespace LuaBindings
{

int VectorRotate(lua_State *state)
{
    int count = state->top - state->base;
    if (count >= 2 && typeOf(state, 1) == 7 && typeOf(state, 2) == 7) {
        const Float4 &vector = userdataValue(state, 1);
        const Float4 &rotation = userdataValue(state, 2);
        Float4A rotated;
        FUN_01343bb0(&rotated, &vector, &rotation);
        FUN_00c8aa70(state, &rotated);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings
