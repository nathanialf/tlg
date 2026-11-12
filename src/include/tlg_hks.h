/* Havok Script, the game's Lua-derived script VM. Its own strings name
 * lua_State and hks; the other names here are derived. */
#ifndef TLG_HKS_H
#define TLG_HKS_H

#include "tlg_libc.h"
#include "tlg_types.h"

/* A value on the VM's stack: a type tag, then the value (16 bytes). The tags
 * the bytes show: 0 nil, 1 a boolean, 3 a number (a float), 8 a thread.
 * derived name. */
struct HksObject {
    int type; /* derived name */
    u32 pad4; /* derived name; never written */

    union {
        int boolean;   /* derived name */
        float number;  /* derived name */
        void *pointer; /* derived name */
    } value;           /* derived name */
};

/* The VM's state as far as the bytes read it: the stack top at +0x48, the
 * slot the next pushed value takes, and at +0x50 the base of the running C
 * function's frame, its first argument (the count of arguments is top - base:
 * FUN_008f38f0, FUN_00e7d500; FUN_00845520 reads the first). */
struct lua_State;

/* The state the VM's threads share, as far as the bytes read it: the main
 * thread at +0x200 (FUN_00deceb0 compares the running thread with it) and an
 * array of values from +0x208 indexed by a value's type tag plus 27
 * (FUN_00dedab0). derived name. */
struct HksGlobal {
    u8 unknown0[0x200];
    lua_State *mainThread;   /* +0x200, derived name */
    HksObject unknown208[1]; /* +0x208, derived name; its extent not traced */
};

struct lua_State {
    u8 unknown0[0x10];
    HksGlobal *global; /* +0x10, derived name */
    u8 unknown18[0x30];
    HksObject *top;  /* derived name */
    HksObject *base; /* derived name */
};

/* One entry of a library's table of C functions, a name and its function,
 * the table ending in a null entry (the tables at 0x16bc8b0 to 0x16bd100 that
 * FUN_00ddc6b0 registers under a library's name). derived name. */
struct HksLibraryEntry {
    const char *name;                  /* derived name */
    int (*function)(lua_State *state); /* derived name */
};

/* derived names: the number a value holds (FUN_00db6f40), whether it holds
 * one (FUN_00db70c0), and the argument error naming the type expected
 * (FUN_00dd38c0); their bodies are not written */
float FUN_00db6f40(lua_State *state, const HksObject *value);
int FUN_00db70c0(lua_State *state, const HksObject *value);
void FUN_00dd38c0(lua_State *state, int argument, const char *type);

/* derived names: an argument's number (0 past the frame's top) and whether
 * it holds one, its slot found again each time */
inline float toNumber(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    return value < state->top ? FUN_00db6f40(state, value) : 0;
}

inline bool isNumber(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    return value < state->top && FUN_00db70c0(state, value);
}

/* The VM's source file, as its assertions pass it (`__FILE__` in
 * vm-aux.cpp, which defines luaL_checknumber). derived name. */
#define HKS_VM_AUX_FILE                                                                            \
    "D:\\trico\\engine\\anzu\\external\\havok\\HavokScriptVM-2013.3.0\\build/../source/"           \
    "virtualMachine/vm-aux.cpp"

/* luaL_checknumber (the name from its assertion message), inlined into
 * every caller (no out-of-line copy is in the executable: FUN_00dbf3f0,
 * FUN_00de6b60 to FUN_00de7c90): the first argument's number; when it is 0
 * and the argument holds no number, the argument error. The state must not
 * be null: the assertion prints the VM's message and stops on a trap. */
inline float luaL_checknumber(lua_State *s, int argument)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1a10f4a2, "s != NULL", "luaL_checknumber",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 343);
        __builtin_trap();
    }
    float number = toNumber(s, argument);
    if (number == 0 && !isNumber(s, argument))
        FUN_00dd38c0(s, argument, "number");
    return number;
}

/* derived name: the argument error with a message (FUN_00dd3450, its body
 * not written) */
void FUN_00dd3450(lua_State *state, int argument, const char *message);

/* luaL_checkany (the name from its assertion message), inlined: the
 * argument error "value expected" past the frame's top. */
inline void luaL_checkany(lua_State *s, int argument)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x131123a2, "s != NULL", "luaL_checkany",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 301);
        __builtin_trap();
    }
    if (!(s->base + (argument - 1) < s->top))
        FUN_00dd3450(s, argument, "value expected");
}

/* derived name: an argument's type, -1 past the frame's top; the tag's low
 * four bits, 9 and 10 read as 6 */
inline int typeOf(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    if (!(value < state->top))
        return -1;
    int type = value->type & 0xf;
    return type == 9 || type == 10 ? 6 : type;
}

/* derived name: pushes a boolean (tag 1) on the stack */
inline void pushBoolean(lua_State *state, bool b)
{
    HksObject *top = state->top;
    top->value.boolean = b;
    top->type = 1;
    state->top = top + 1;
}

/* derived name: pushes a number (tag 3) on the stack */
inline void pushNumber(lua_State *state, float number)
{
    HksObject *top = state->top;
    top->value.number = number;
    top->type = 3;
    state->top = top + 1;
}

#endif
