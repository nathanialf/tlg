/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::Vector4NewIndexM (the name FUN_00e80560's registration gives
 * the VM for it): the new-index metamethod of a four-float userdata with a
 * string key and a number: the lane the key's first letter names (X, Y, Z
 * or W) is set to the number; 0 is returned (no results). The row keeps its
 * FUN_ name until a ruling, as leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int Vector4NewIndexM(lua_State *state)
{
    if (argumentCount(state) >= 2 && isUserdata(state, 1) && typeOf(state, 2) == 4 &&
        typeOf(state, 3) == 3) {
        Float4 *vector = static_cast<Float4 *>(toUserdata(state, 1));
        const char *key = stringOf(state, 2);
        if (key[0] == 'X')
            vector->x = toNumber(state, 3);
        else if (key[0] == 'Y')
            vector->y = toNumber(state, 3);
        else if (key[0] == 'Z')
            vector->z = toNumber(state, 3);
        else if (key[0] == 'W')
            vector->w = toNumber(state, 3);
    }
    return 0;
}

} // namespace LuaBindings
