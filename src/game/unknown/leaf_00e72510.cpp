/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* The script C function the VM knows as "QuatToEuler" (the name
 * FUN_00e72800's registration gives it, lea at 0xe72827): with exactly one
 * userdata argument, the angles of its rotation (FUN_0134ab60, the rotation
 * copied first) are pushed as a vector; with anything else the identity
 * (0, 0, 0, 1), a temporary, is pushed. Returns 1. derived names. */
Float4A FUN_0134ab60(const Float4A &rotation); /* derived name */

int FUN_00e72510(lua_State *state) /* derived name */
{
    if (argumentCount(state) == 1 && typeOf(state, 1) == 7) {
        const Float4 &value = userdataValue(state, 1);
        Float4A rotation(value.x, value.y, value.z, value.w);
        Float4A angles = FUN_0134ab60(rotation);
        FUN_00c8aa70(state, &angles);
    } else {
        const Float4A &identity = Float4A(0, 0, 0, 1);
        FUN_00c8aa70(state, &identity);
    }
    return 1;
}
