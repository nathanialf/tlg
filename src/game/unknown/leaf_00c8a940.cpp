/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_lua_bindings.h"

/* derived names: pushes a copy of an 8-byte value (two ints) as a block of 8
 * bytes FUN_00dba890 makes on the stack, then pushes the address 0x151e4ff
 * as a value of type 2 (a key: nothing at the address is read here), has
 * FUN_00db7fd0 look the key up in the table the state's global holds at
 * +0x1c8 (its type) and +0x1d0 and puts the result in the key's place,
 * type and value, by field; when the stack holds the block and the result above its base, FUN_00d971b0 joins them and
 * the result is popped. Four callers. The value's meaning is not traced.
 * FUN_00c8a9d0, FUN_00c8aa70 and FUN_00c8ab10 do the same for a point (w
 * made 1), a vector and a rotation, the first two under the key 0x151e500,
 * the rotation under 0x151e501. */
struct Value00c8a940 { /* derived name */
    int first;         /* +0x0 */
    int second;        /* +0x4 */
};

struct Global00c8a940 { /* derived name: the state's global, seen from here */
    u8 unknown0[0x1c8];
    int unknown1c8; /* +0x1c8: the table's type */
    u8 unknown1cc[4];
    void *unknown1d0; /* +0x1d0: the table */
};

extern const char D_151e4ff;
extern const char D_151e500;
extern const char D_151e501;

void *FUN_00dba890(lua_State *state, unsigned long size); /* derived name */
HksObject FUN_00db7fd0(lua_State *state, int type, void *table,
                       const HksObject *key);                             /* derived name */
void FUN_00d971b0(lua_State *state, HksObject *object, HksObject *table); /* derived name */

/* derived name: the userdata on the stack's top gets the table the key names
 * in the global's table (FUN_00db7fd0) as its metatable (FUN_00d971b0) */
inline void setMetatable(lua_State *state, const char *name)
{
    HksObject *key = state->top;
    key->value.pointer = const_cast<char *>(name);
    key->type = 2;
    state->top = key + 1;
    Global00c8a940 *global = reinterpret_cast<Global00c8a940 *>(state->global);
    HksObject result = FUN_00db7fd0(state, global->unknown1c8, global->unknown1d0, key);
    HksObject *slot = state->top - 1;
    slot->type = result.type;
    slot->value = result.value;
    if (state->top - 2 >= state->base) {
        FUN_00d971b0(state, state->top - 2, state->top - 1);
        state->top--;
    }
}

void FUN_00c8a940(lua_State *state, const Value00c8a940 *value) /* derived name */
{
    Value00c8a940 *copy = static_cast<Value00c8a940 *>(FUN_00dba890(state, sizeof(Value00c8a940)));
    copy->first = value->first;
    copy->second = value->second;
    setMetatable(state, &D_151e4ff);
}

void FUN_00c8a9d0(lua_State *state, const Float4 *point) /* derived name */
{
    Float4 *copy = static_cast<Float4 *>(FUN_00dba890(state, sizeof(Float4)));
    *copy = Float4(point->x, point->y, point->z, 1.0f);
    setMetatable(state, &D_151e500);
}

void FUN_00c8aa70(lua_State *state, const Float4A *vector)
{
    Float4 *copy = static_cast<Float4 *>(FUN_00dba890(state, sizeof(Float4)));
    copy->x = vector->x;
    copy->y = vector->y;
    copy->z = vector->z;
    copy->w = vector->w;
    setMetatable(state, &D_151e500);
}

void FUN_00c8ab10(lua_State *state, const Float4A *rotation)
{
    Float4 *copy = static_cast<Float4 *>(FUN_00dba890(state, sizeof(Float4)));
    copy->x = rotation->x;
    copy->y = rotation->y;
    copy->z = rotation->z;
    copy->w = rotation->w;
    setMetatable(state, &D_151e501);
}
