/* The game's script bindings of vectors and rotations, the C functions whose
 * names FUN_00e80560 gives the VM ("LuaBindings::VectorAdd4", ...): each
 * reads its arguments as userdata (type 7) holding a four-float value at
 * +0x20 and pushes a result. derived names. */
#ifndef TLG_LUA_BINDINGS_H
#define TLG_LUA_BINDINGS_H

#include "tlg_hks.h"
#include "tlg_math.h"

struct LuaVectorUserdata { /* derived name */
    u8 unknown0[0x20];     /* the userdata's header, not traced */
    Float4 value;          /* +0x20 */
};

/* derived names: push a vector and a rotation as new userdata; their bodies
 * are not written */
void FUN_00c8aa70(lua_State *state, const Float4 *vector);
void FUN_00c8ab10(lua_State *state, const Float4 *rotation);

/* derived name: the value of the userdata an argument holds (its type
 * tested before) */
inline const Float4 &userdataValue(lua_State *state, int argument)
{
    return static_cast<const LuaVectorUserdata *>(state->base[argument - 1].value.pointer)->value;
}

#endif
