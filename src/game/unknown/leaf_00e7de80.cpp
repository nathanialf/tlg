/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::Vec4 (the name FUN_00e80560's registration gives the VM for
 * it): a vector, (0, 0, 0, 1) unless the arguments give it, read through
 * FUN_00c8edb0 with a reader of the frame (as leaf_001b2f20.cpp's, its index
 * here one more than the negated count of arguments), is pushed
 * (FUN_00c8aa70); 1 is returned. The row keeps its FUN_ name until a ruling,
 * as leaf_00e7e520.cpp's. derived names otherwise. */
struct ArgumentReader00c8edb0 { /* derived name */

    explicit ArgumentReader00c8edb0(lua_State *state_)
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

void FUN_00c8edb0(ArgumentReader00c8edb0 *reader, Float4 *vector); /* derived name */

namespace LuaBindings
{

int Vec4(lua_State *state)
{
    Float4 vector(0.0f, 0.0f, 0.0f, 1.0f);
    ArgumentReader00c8edb0 reader(state);
    FUN_00c8edb0(&reader, &vector);
    FUN_00c8aa70(state, &vector);
    return 1;
}

} // namespace LuaBindings
