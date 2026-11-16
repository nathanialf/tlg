/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::Vector4IndexM (the name FUN_00e80560's registration gives the
 * VM for it): the index metamethod of a four-float userdata with a string
 * key: a C function its metatable holds under the key is returned (the
 * metatable left under it), else the lane the key's first letter names (X,
 * Y, Z or W) is pushed as a number and 1 returned; else 0 (no results).
 * The row keeps its FUN_ name until a ruling, as leaf_00e7e520.cpp's. */
namespace LuaBindings
{

int Vector4IndexM(lua_State *state)
{
    if (argumentCount(state) >= 2 && typeOf(state, 2) == 4) {
        if (getMetatable(state, 1)) {
            pushValue(state, 2);
            getTableBelow(state);
            if (topIsCFunction(state))
                return 1;
            pop(state, 1);
        }
        if (isUserdata(state, 1)) {
            const Float4 *vector = static_cast<const Float4 *>(toUserdata(state, 1));
            const char *key = stringOf(state, 2);
            if (key[0] == 'X') {
                pushNumber(state, vector->x);
                return 1;
            } else if (key[0] == 'Y') {
                pushNumber(state, vector->y);
                return 1;
            } else if (key[0] == 'Z') {
                pushNumber(state, vector->z);
                return 1;
            } else if (key[0] == 'W') {
                pushNumber(state, vector->w);
                return 1;
            }
        }
    }
    return 0;
}

} // namespace LuaBindings
