/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object05945a38.h"
#include "tlg_game_string01331840.h"
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
 * (FUN_00c8ae90) and returns 1; both return 0 for no object. Both count their
 * results in a local returned once: the base makes the null object's 0 after
 * the reader's call apart from the entry's (`xor eax, eax` before the null
 * test). Equal pushes
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

int FUN_00e75b70(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        ArgumentReader00e778e0 reader(state, 0);
        Object016b9108 *object = 0;
        FUN_00c8c290(&reader, &object);
        if (object)
            return pushUnlessHidden(state, object);
    }
    return 0;
}

extern int D_5945a14; /* derived name: a counter of the objects made (leaf_008a9440.cpp) */

void FUN_00cb8d50(const Type00503fb0 *type, int unknown, Object016b9108 *source,
                  Object016b9108 *target, int serial, int properties,
                  int unknown2); /* derived name */

/* derived names: the script C functions "CloneToObj" and "CopyProperties"
 * of the same registration (lea at 0xe78679 and 0xe78708, the VM's names
 * for them): with exactly two arguments holding objects, FUN_00cb8d50
 * copies the first into the second with the next value of the counter
 * D_5945a14; CloneToObj only between objects of one type and with 0 where
 * CopyProperties (two arguments or more) passes 1. Both return 0 (no results). */
int FUN_00e769e0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count == 2) {
        Object016b9108 *source = 0;
        ArgumentReader00e778e0 sourceReader(state, 0);
        FUN_00c8c290(&sourceReader, &source);
        Object016b9108 *target = 0;
        ArgumentReader00e778e0 targetReader(state, 1);
        FUN_00c8c290(&targetReader, &target);
        if (source && target && source->type == target->type)
            FUN_00cb8d50(source->type, 1, source, target, __sync_add_and_fetch(&D_5945a14, 1), 0,
                         0);
    }
    return 0;
}

// NONMATCHING: instruction order only (60/62): the base reads the type (`mov rdi, [rdx+0x18]`)
// before the counter's increment `mov r8d, 1`; the build after it
// Round 560C, link-stage IR: the type's load is before the atomic add there (the arguments in
// order); the DAG schedules the add's constant (`mov r8d, 1`, no chain) above the load. Not
// compiled.
int FUN_00e76ae0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count >= 2) {
        Object016b9108 *source = 0;
        ArgumentReader00e778e0 sourceReader(state, 0);
        FUN_00c8c290(&sourceReader, &source);
        Object016b9108 *target = 0;
        ArgumentReader00e778e0 targetReader(state, 1);
        FUN_00c8c290(&targetReader, &target);
        if (source && target)
            FUN_00cb8d50(source->type, 1, source, target, __sync_add_and_fetch(&D_5945a14, 1), 1,
                         0);
    }
    return 0;
}

extern Type00503fb0 *D_5939080; /* derived name: the node's type (leaf_00e6d420.cpp) */

Object016b9108 *FUN_00cb8ac0(const Type00503fb0 *type, int unknown, Object016b9108 *source,
                             int serial);       /* derived name */
void FUN_00c57940(Object016b9108 *object, int); /* derived name */

/* derived names: the script C function "Clone" of the same registration
 * (lea at 0xe785ea): with exactly one argument holding an object whose type
 * may be copied (bit 1 of its flags clear), FUN_00cb8ac0 makes a copy with
 * the next value of the counter D_5945a14; a node copy is handed to
 * FUN_00c57940 with 1; the copy's name is pushed as a string. Nil is pushed
 * for no copy. Returns 1. */
int FUN_00e768a0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count == 1) {
        Object016b9108 *object = 0;
        ArgumentReader00e778e0 reader(state, 0);
        FUN_00c8c290(&reader, &object);
        if (object && !(object->type->flags & 2)) {
            Object016b9108 *copy =
                FUN_00cb8ac0(object->type, 1, object, __sync_add_and_fetch(&D_5945a14, 1));
            if (copy) {
                if (copy->isKindOf(D_5939080))
                    FUN_00c57940(copy, 1);
                pushString(state, D_17ac870[copy->name.index].string0);
                return 1;
            }
        }
    }
    pushNil(state);
    return 1;
}

/* derived name: the object an argument holds, read through FUN_00c8c290
 * (as leaf_00e6d420.cpp's: one load after the call) */
static inline Object016b9108 *objectArgument(lua_State *state, int first)
{
    Object016b9108 *object = 0;
    ArgumentReader00e778e0 reader(state, first);
    FUN_00c8c290(&reader, &object);
    return object;
}

/* derived name: an argument's string, null past the frame's top (as
 * leaf_00e7d320.cpp's) */
static inline const char *toString(lua_State *state, int argument)
{
    HksObject *value = state->base + (argument - 1);
    return value < state->top ? FUN_00db6b20(state, value, 0) : 0;
}

/* derived names: the script C function "SaveObject" of the same
 * registration (lea at 0xe78201): with one to three arguments, the first
 * holding an object, the path "_backup/" and the second argument's string
 * (with exactly two arguments) or else the object's name is formatted into
 * a local string through FUN_01331840 and not used further. Pushes 0 and
 * returns 1 in every case. */
int FUN_00e76100(lua_State *state) /* derived name */
{
    String01331840 path;
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count >= 1 && count <= 3) {
        Object016b9108 *object = objectArgument(state, 0);
        if (object) {
            const char *name = count == 2 ? toString(state, 2) : 0;
            pushInteger(state, 0);
            if (!name)
                name = D_17ac870[object->name.index].string0;
            FUN_01331840(&path, "_backup/%s", name);
            return 1;
        }
    }
    pushInteger(state, 0);
    return 1;
}

/* derived name: Lua's lua_isstring: an argument holding a string or a
 * number */
static inline bool isString(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    if (!(value < state->top))
        return false;
    const int type = value->type & 0xf;
    return type == 4 || type == 3;
}

/* derived name: the name of a string interned as a copy, the
 * empty name for an empty string (as leaf_004eadf0.cpp's) */
static inline Name nameOf(const char *string)
{
    Name name;
    name.index = string[0] ? FUN_013baad0(string, FUN_013bad90(string), strlen(string), false) : 0;
    return name;
}

/* derived names: the script C function "IsObjTypeOf" of the same
 * registration (lea at 0xe77cfa): with two arguments or more, the first
 * holding an object and the second a string naming a type of the table at
 * 0x5945a38, pushes whether the object is of that type or one derived from
 * it and returns 1; else returns 0 (no results). */
// NONMATCHING: register assignment only (module, 445 against 444 bytes): the base holds the
// state in r14 and the result in ebx (0 made again after the reader's call, as ObjectToString's
// note says; 1 set before the type walk), the build the reverse
int FUN_00e73bb0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count >= 2) {
        Object016b9108 *object = objectArgument(state, 0);
        if (object && isString(state, 2)) {
            const char *string = toString(state, 2);
            if (string) {
                Type00503fb0 *type = D_5945a38->type(nameOf(string));
                if (type) {
                    pushBoolean(state, object->isKindOf(type));
                    return 1;
                }
            }
        }
    }
    return 0;
}

namespace LuaBindings
{

int ObjectToString(lua_State *state)
{
    int results = 0;
    int count = state->top - state->base;
    if (count > 0) {
        ArgumentReader00e778e0 reader(state, 0);
        Object016b9108 *object = 0;
        FUN_00c8c290(&reader, &object);
        if (object) {
            pushString(state, D_17ac870[object->name.index].string0);
            results = 1;
        }
    }
    return results;
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

int ObjectGetClass(lua_State *state)
{
    int results = 0;
    int count = state->top - state->base;
    if (count > 0) {
        ArgumentReader00e778e0 reader(state, 0);
        Object016b9108 *object = 0;
        FUN_00c8c290(&reader, &object);
        if (object) {
            FUN_00c8ae90(state, object->type);
            results = 1;
        }
    }
    return results;
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
