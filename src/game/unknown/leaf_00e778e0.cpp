/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_hks_string.h"

/* LuaBindings::ObjectToString, LuaBindings::ObjectRelease,
 * LuaBindings::ObjectGetClass and LuaBindings::ObjectEqual (the names
 * FUN_00e77a00's registration gives the VM for them, under the keys
 * "GetName", lea at 0xe7890a, "Release", 0xe789a4, "GetClass", 0xe78955,
 * and "__eq", 0xe78a36): the objects the arguments hold are read through
 * FUN_00c8c290 with a reader of the frame from an argument on (as
 * leaf_0046f770.cpp's and leaf_00e7ff00.cpp's). ToString pushes the string
 * of the object's name (nil for none) and returns 1, Release does nothing
 * else and returns 0 (no results), GetClass pushes the object's type
 * (FUN_00c8ae90) and returns 1; both return 0 for no object. Equal pushes
 * whether its two arguments hold the same object and returns 1. The rows
 * keep their FUN_ names until a ruling, as leaf_00e7e520.cpp's. derived
 * names otherwise. */
struct ArgumentReader00e778e0 { /* derived name */

    ArgumentReader00e778e0(lua_State *state_, int first)
        : state(state_), unknown8(0), unknown14(0), unknown18(0)
    {
        index = first - (int)((unsigned long)((char *)state_->top - (char *)state_->base) /
                              sizeof(HksObject));
    }

    lua_State *state; /* +0x0 */
    void *unknown8;   /* +0x8 */
    int index;        /* +0x10 */
    int unknown14;    /* +0x14 */
    int unknown18;    /* +0x18 */
};

void FUN_00c8c290(ArgumentReader00e778e0 *reader, Object016b9108 **object); /* derived name */
void FUN_00c8ae90(lua_State *state, const Type00503fb0 *type);              /* derived name */
void FUN_00c89360(lua_State *state, Object016b9108 *object);                /* derived name */

/* derived names: the script C functions "Exists" and "FindObject" of the
 * same registration (lea at 0xe77fc5 and 0xe7831f, the VM's names for
 * them): Exists pushes whether its one argument holds an object (false for
 * any other count); FindObject pushes the object its argument holds
 * (FUN_00c89360) unless bit 5 of its flags at +0x16 is set, and returns 1,
 * else 0 (no results). */
int FUN_00e74400(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count == 1) {
        ArgumentReader00e778e0 reader(state, 0);
        Object016b9108 *object = 0;
        FUN_00c8c290(&reader, &object);
        pushBoolean(state, object != 0);
    } else {
        pushBoolean(state, false);
    }
    return 1;
}

// NONMATCHING: register assignment: the base materialises the 0 it returns again after the
// reader's call (`xor eax, eax` before the null test) and holds the guard's address in r14; the
// build keeps one 0 in r14 across the call (the guard in r15, a frame 8 bytes larger)
int FUN_00e75b70(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        ArgumentReader00e778e0 reader(state, 0);
        Object016b9108 *object = 0;
        FUN_00c8c290(&reader, &object);
        if (object && !(object->flags16 & 0x20)) {
            FUN_00c89360(state, object);
            return 1;
        }
    }
    return 0;
}

namespace LuaBindings
{

// NONMATCHING: register assignment: the base materialises the 0 it returns again after the
// reader's call (`xor eax, eax` before the null test) and holds the guard's address in r14; the
// build keeps one 0 in r14 across the call (the guard in r15, a frame 8 bytes larger)
int ObjectToString(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0) {
        ArgumentReader00e778e0 reader(state, 0);
        Object016b9108 *object = 0;
        FUN_00c8c290(&reader, &object);
        if (object) {
            pushString(state, D_17ac870[object->name.index].string0);
            return 1;
        }
    }
    return 0;
}

int ObjectRelease(lua_State *state)
{
    Object016b9108 *object = 0;
    int count = state->top - state->base;
    if (count > 0) {
        ArgumentReader00e778e0 reader(state, 0);
        FUN_00c8c290(&reader, &object);
    }
    return 0;
}

// NONMATCHING: register assignment: the base materialises the 0 it returns again after the
// reader's call (`xor eax, eax` before the null test) and holds the guard's address in r14; the
// build keeps one 0 in r14 across the call (the guard in r15, a frame 8 bytes larger)
int ObjectGetClass(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0) {
        ArgumentReader00e778e0 reader(state, 0);
        Object016b9108 *object = 0;
        FUN_00c8c290(&reader, &object);
        if (object) {
            FUN_00c8ae90(state, object->type);
            return 1;
        }
    }
    return 0;
}

int ObjectEqual(lua_State *state)
{
    int count = state->top - state->base;
    if (count < 2)
        return 0;
    Object016b9108 *first = 0;
    ArgumentReader00e778e0 firstReader(state, 0);
    FUN_00c8c290(&firstReader, &first);
    Object016b9108 *second = 0;
    ArgumentReader00e778e0 secondReader(state, 1);
    FUN_00c8c290(&secondReader, &second);
    pushBoolean(state, first == second);
    return 1;
}

} // namespace LuaBindings
