/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::Quat (the name FUN_00e80560's registration gives the VM for
 * it): three angles read through FUN_00c8edb0 with a reader of the frame (as
 * leaf_00e7de80.cpp's) make a rotation (FUN_0020c3b0, as
 * leaf_0020c3b0.cpp's from three floats), which is pushed (FUN_00c8ab10); 1
 * is returned. The row keeps its FUN_ name until a ruling,
 * as leaf_00e7e520.cpp's. derived names otherwise. */
struct ArgumentReader00e7ff00 { /* derived name */

    explicit ArgumentReader00e7ff00(lua_State *state_)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index = 1 - (int)((unsigned long)((char *)state_->top - (char *)state_->base) /
                          sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

void FUN_00c8edb0(ArgumentReader00e7ff00 *reader, Float4A *vector); /* derived name */
void FUN_0020c3b0(Float4A *rotation, float x, float y, float z);    /* derived name */

namespace LuaBindings
{

int Quat(lua_State *state)
{
    Float4A angles;
    ArgumentReader00e7ff00 reader(state);
    FUN_00c8edb0(&reader, &angles);
    Float4A rotation;
    FUN_0020c3b0(&rotation, angles.x, angles.y, angles.z);
    FUN_00c8ab10(state, &rotation);
    return 1;
}

} // namespace LuaBindings
