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
    u8 unknown0[0x1c8];
    /* +0x1c8, derived name: the registry, its table linked as "Registry"
     * (FUN_00dd2900), the value debug.getregistry pushes (FUN_00deb2b0) */
    HksObject registry;
    u8 unknown1d8[0x28];
    lua_State *mainThread;   /* +0x200, derived name */
    HksObject unknown208[1]; /* +0x208, derived name; its extent not traced */
    u8 unknown218[0x280];
    /* +0x498, derived name: the debugger print hands the arguments to
     * (FUN_00debd90), null without one */
    struct HksDebugger *debugger;
};

/* derived names: the debugger as print reaches it: the state it is
 * printing for (+0x8, set for the outermost print), its user data (+0x18,
 * handed to FUN_00d91230 first) and the depth of nested prints (+0x20) */
struct HksDebugger {
    u8 unknown0[0x8];
    lua_State *state; /* +0x8 */
    u8 unknown10[0x8];
    void *user; /* +0x18 */
    int depth;  /* +0x20 */
};

struct lua_State {
    u8 unknown0[0x10];
    HksGlobal *global; /* +0x10, derived name */
    u8 unknown18[0x30];
    HksObject *top;   /* derived name */
    HksObject *base;  /* derived name */
    HksObject *last;  /* +0x58, derived name: the end of the stack's room */
    HksObject *stack; /* +0x60, derived name: the first value FUN_00dd2900 links */
    u8 unknown68[0x10];
    void *globals; /* +0x78, derived name: linked as "Global Table" (FUN_00dd2900) */
    u8 unknown80[0x40];
    /* +0xc0, derived name: the thread's state as coroutine.status reads it
     * (FUN_00decef0): 1 suspended unless its frame is empty, 2 normal, 3
     * suspended, 4 dead */
    int status;
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

/* derived name: an argument's string and its length (FUN_00db6b20, its body
 * not written), null when it holds none */
const char *FUN_00db6b20(lua_State *state, const HksObject *value, size_t *length);

/* hksi_luaL_checklstring (the name from its assertion message), inlined:
 * an argument's string and its length; the argument error "string" when the
 * argument holds none */
inline const char *hksi_luaL_checklstring(lua_State *s, int argument, size_t *length)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1a10f3a2, "s != NULL", "hksi_luaL_checklstring",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 323);
        __builtin_trap();
    }
    const HksObject *value = s->base + (argument - 1);
    const char *string = value < s->top ? FUN_00db6b20(s, value, length) : 0;
    if (!string)
        FUN_00dd38c0(s, argument, "string");
    return string;
}

/* hksi_hksL_checktable (the name from its assertion message), inlined: the
 * argument error "table/struct" unless the argument is a table (5) or a
 * struct (12) */
inline void hksi_hksL_checktable(lua_State *s, int argument)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1f0924a2, "s != NULL", "hksi_hksL_checktable",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 423);
        __builtin_trap();
    }
    /* the type read for each test (`cmp ecx, 5; sete` and `cmp ecx, 0xc;
     * sete`, each beside the test for 9 and 10 at 0xdeda2d) */
    if (typeOf(s, argument) != 5 && typeOf(s, argument) != 12)
        FUN_00dd38c0(s, argument, "table/struct");
}

/* derived name: an argument's truth: false past the frame's top, for nil
 * (tag 0) and for a false boolean (tag 1), true for any other value (0x46b0d0
 * to 0x46b0fa: the slot made null past the top, `and 0xf; je`, `cmp 1; jne`,
 * `cmp [rcx+8], 0; setne`) */
inline bool toBoolean(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    if (!(value < state->top))
        value = 0;
    if (!value)
        return false;
    const int type = value->type & 0xf;
    if (type == 0)
        return false;
    if (type == 1)
        return value->value.boolean != 0;
    return true;
}

/* derived name: the count of the running function's arguments (the frame's
 * top less its base, `sub; shr 4` at 0xe73a57) */
inline int argumentCount(lua_State *state)
{
    return state->top - state->base;
}

/* derived name: pushes nil (tag 0) on the stack, its value left alone */
inline void pushNil(lua_State *state)
{
    HksObject *top = state->top;
    top->type = 0;
    state->top = top + 1;
}

/* derived name: pushes a boolean (tag 1) on the stack */
inline void pushBoolean(lua_State *state, bool b)
{
    HksObject *top = state->top;
    top->value.boolean = b;
    top->type = 1;
    state->top = top + 1;
}

/* derived name: pushes an integer as a number (tag 3), Lua's
 * lua_pushinteger */
inline void pushInteger(lua_State *state, int integer)
{
    HksObject *top = state->top;
    top->value.number = integer;
    top->type = 3;
    state->top = top + 1;
}

/* derived name: Lua's lua_createtable by its arguments: pushes a new table
 * with room for `arrayCount` array and `hashCount` hash entries
 * (FUN_00d91880) */
void FUN_00d91880(lua_State *state, int arrayCount, int hashCount);

/* derived name: Lua's luaV_settable by its arguments: table[key] = value
 * (FUN_00db84e0) */
void FUN_00db84e0(lua_State *state, HksObject *table, HksObject *key, HksObject *value);

/* derived name: Lua's lua_settable(state, -3): the table under the key and
 * the value on the stack's top gets the value at the key, then the key and
 * the value are popped (0x8eb424 to 0x8eb438) */
inline void setTable(lua_State *state)
{
    HksObject *top = state->top;
    FUN_00db84e0(state, top - 3, top - 2, top - 1);
    state->top -= 2;
}

/* derived name: pushes a number (tag 3) on the stack */
inline void pushNumber(lua_State *state, float number)
{
    HksObject *top = state->top;
    top->value.number = number;
    top->type = 3;
    state->top = top + 1;
}

/* derived names: the block a full userdata's value follows (0x20 bytes,
 * not traced), Lua's lua_touserdata: an argument's light userdata (tag 2)
 * as it is, a full userdata's (tag 7) value past its block, else null
 * (null past the frame's top: 0xe7f3e2 to 0xe7f3f9) */
struct HksUserdata { /* derived name */
    u8 unknown0[0x20];
};

/* derived name: Lua's lua_isuserdata: whether an argument holds a full
 * (tag 7) or a light (tag 2) userdata (false past the frame's top) */
inline bool isUserdata(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    if (!(value < state->top))
        return false;
    const int type = value->type & 0xf;
    return type == 7 || type == 2;
}

inline void *toUserdata(lua_State *state, int argument) /* derived name */
{
    const HksObject *value = state->base + (argument - 1);
    if (!(value < state->top))
        return 0;
    const int type = value->type & 0xf;
    if (type == 7)
        return static_cast<HksUserdata *>(value->value.pointer) + 1;
    if (type == 2)
        return value->value.pointer;
    return 0;
}

/* derived name: Lua's lua_tolstring by its arguments: the string a value
 * reads as (FUN_00db6b20; a null value for an argument past the frame's
 * top, `cmovae rsi, rbx` at 0xe7f2eb) */
const char *FUN_00db6b20(lua_State *state, const HksObject *value, size_t *length);

inline const char *stringOf(lua_State *state, int argument) /* derived name */
{
    const HksObject *value = state->base + (argument - 1);
    if (!(value < state->top))
        value = 0;
    return FUN_00db6b20(state, value, 0);
}

/* derived names: Lua's lua_getmetatable by its arguments: whether an object
 * has a metatable, which is written to `metatable` (FUN_00d96dd0), and the
 * metatable of an argument pushed (1), else nothing pushed (0; nothing asked
 * past the frame's top) */
int FUN_00d96dd0(lua_State *state, const HksObject *object, HksObject *metatable);

inline int getMetatable(lua_State *state, int argument) /* derived name */
{
    const HksObject *object = state->base + (argument - 1);
    if (!(object < state->top))
        return 0;
    HksObject *top = state->top;
    if (!FUN_00d96dd0(state, object, top))
        return 0;
    state->top = top + 1;
    return 1;
}

/* derived name: Lua's lua_pushvalue: a copy of an argument pushed */
inline void pushValue(lua_State *state, int argument)
{
    HksObject *top = state->top;
    *top = state->base[argument - 1];
    state->top = top + 1;
}

/* derived names: Lua's luaV_gettable by its arguments: table[key] written to
 * `value` (FUN_00db8650), and lua_gettable(state, -2): the table under the
 * key on the stack's top indexed by it, the key replaced by the value */
void FUN_00db8650(lua_State *state, const HksObject *table, const HksObject *key, HksObject *value);

inline void getTableBelow(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    FUN_00db8650(state, top - 2, top - 1, top - 1);
}

/* derived name: whether the stack's top value is a C function (tag 10;
 * false for an empty frame) */
inline bool topIsCFunction(lua_State *state)
{
    const HksObject *value = state->top - 1;
    if (!(value >= state->base))
        return false;
    return (value->type & 0xf) == 10;
}

/* The VM's API source, as its assertions pass it (`__FILE__` in the
 * file that includes lua_impl.inl). derived name. */
#define HKS_LUA_IMPL_FILE                                                                          \
    "D:\\trico\\engine\\anzu\\external\\havok\\HavokScriptVM-2013.3.0\\build/../source/"           \
    "Debugger/../Platform/String/../../virtualMachine/Kernel/../../virtualMachine/lua_impl.inl"

/* hksi_lua_pop (the name from its assertion message), inlined: n values
 * popped from the stack's top */
inline void hksi_lua_pop(lua_State *s, int n)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xa238a, "s != NULL", "hksi_lua_pop", "Parameter 's' must be a valid state pointer",
               HKS_LUA_IMPL_FILE, 822);
        __builtin_trap();
    }
    s->top -= n;
}

/* derived name: grows the stack's room by n values (FUN_00dbb2e0, its body
 * not written; the first argument is the address of +0x18) */
void FUN_00dbb2e0(void *unknown18, lua_State *state, int n);

/* hksi_lua_checkstack (the name from its assertion message), inlined: room
 * made for n more values */
inline void hksi_lua_checkstack(lua_State *s, int n)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xc238a, "s != NULL", "hksi_lua_checkstack",
               "Parameter 's' must be a valid state pointer", HKS_LUA_IMPL_FILE, 1124);
        __builtin_trap();
    }
    if (s->top + n > s->last)
        FUN_00dbb2e0(s->unknown18, s, n);
}

/* derived name: Lua's lua_topointer(state, -1): the stack's top value's
 * object for a table (5), a thread (8), a function (9, 10) or a structure's
 * object (12), a light userdata (2) as it is, a full userdata's (7) value
 * past its block, else null (null for an empty frame) */
inline void *topPointer(lua_State *state)
{
    const HksObject *value = state->top - 1;
    if (!(value >= state->base))
        value = 0;
    if (!value)
        return 0;
    switch (value->type & 0xf) {
    case 5:
    case 8:
    case 9:
    case 10:
    case 12:
        return value->value.pointer;
    case 2:
        return value->value.pointer;
    case 7:
        return static_cast<HksUserdata *>(value->value.pointer) + 1;
    default:
        return 0;
    }
}

/* hksi_lua_pushvalue (the name from its assertion message) of the
 * registry's index, inlined: a copy of the registry pushed */
inline void hksi_lua_pushRegistry(lua_State *s) /* derived name */
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1238a, "s != NULL", "hksi_lua_pushvalue",
               "Parameter 's' must be a valid state pointer", HKS_LUA_IMPL_FILE, 837);
        __builtin_trap();
    }
    HksObject *top = s->top;
    *top = s->global->registry;
    s->top = top + 1;
}

/* hksi_luaL_checktype (the name from its assertion message), inlined: the
 * argument error naming the type expected unless the argument's type (as
 * typeOf reads it) is `type`; `name` is the type's name, the constant the
 * base passes */
inline void hksi_luaL_checktype(lua_State *s, int argument, int type, const char *name)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1f9924a2, "s != NULL", "hksi_luaL_checktype",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 406);
        __builtin_trap();
    }
    if (typeOf(s, argument) != type)
        FUN_00dd38c0(s, argument, name);
}

/* derived name: Lua's lua_settop for a count of arguments: nil pushed up to
 * the frame's base plus `count`, which becomes the top */
inline void setTop(lua_State *state, int count)
{
    HksObject *newTop = state->base + count;
    for (HksObject *top = state->top; top < newTop; ++top)
        top->type = 0;
    state->top = newTop;
}

/* derived name: Lua's lua_isthread: whether an argument is a thread (tag
 * 8; false past the frame's top) */
inline bool isThread(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    return value < state->top && (value->type & 0xf) == 8;
}

/* derived name: Lua's lua_tothread: an argument's thread (tag 8), else
 * null (null past the frame's top) */
inline lua_State *toThread(lua_State *state, int argument)
{
    const HksObject *value = state->base + (argument - 1);
    if (!(value < state->top))
        value = 0;
    if (!value)
        return 0;
    if ((value->type & 0xf) == 8)
        return static_cast<lua_State *>(value->value.pointer);
    return 0;
}

/* hksi_lua_remove (the name from its assertion message), inlined: the
 * value at an index taken out, the ones above it moved down (a positive
 * index made relative to the top first) */
inline void hksi_lua_remove(lua_State *s, int index)
{
    if (index > 0)
        index = index - argumentCount(s) - 1;
    if (!(-index > 0 && -index <= argumentCount(s))) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x111fff22, "-offset > 0 && -offset <= hks::S_API_STACK_FRAMESIZE(s)",
               "hksi_lua_remove", "Parameter 'index' is invalid", HKS_LUA_IMPL_FILE, 874);
        __builtin_trap();
    }
    HksObject *top = s->top;
    for (int i = index; i < 0; ++i)
        top[i] = top[i + 1];
    s->top = top - 1;
}

/* derived name: the debugger's print of the stack's values
 * (FUN_00d91230, its body not written) */
void FUN_00d91230(void *user, HksDebugger *debugger, int count);

/* The VM's debugger source, as its assertions pass it (`__FILE__` in
 * vm-debug.cpp). derived name. */
#define HKS_VM_DEBUG_FILE                                                                          \
    "D:\\trico\\engine\\anzu\\external\\havok\\HavokScriptVM-2013.3.0\\build/../source/"           \
    "virtualMachine/Debug/vm-debug.cpp"

/* hksi_hks_debugprint (the name from its assertion message), inlined: the
 * frame's values handed to the debugger, if there is one, the state set
 * for the outermost print */
inline void hksi_hks_debugprint(lua_State *s, int count)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x89716, "s != NULL", "hksi_hks_debugprint",
               "Parameter 's' must be a valid state pointer", HKS_VM_DEBUG_FILE, 40);
        __builtin_trap();
    }
    HksDebugger *debugger = s->global->debugger;
    if (debugger) {
        if (debugger->depth) {
            ++debugger->depth;
            FUN_00d91230(debugger->user, debugger, count);
            --debugger->depth;
        } else {
            debugger->state = s;
            debugger->depth = 1;
            FUN_00d91230(debugger->user, debugger, count);
            --debugger->depth;
            debugger->state = 0;
        }
    }
}

/* luaL_Buffer as the bytes lay it out: the next free character, the count
 * of pieces pushed, the state and the characters (0x200) */
struct luaL_Buffer {
    char *p;
    int lvl;
    lua_State *L;
    char buffer[0x200];
};

/* derived names: the buffer's text flushed onto the stack (FUN_00ddb460,
 * Lua's luaL_prepbuffer by its argument) and Lua's lua_concat
 * (FUN_00d94bc0); their bodies not written */
char *FUN_00ddb460(luaL_Buffer *b);
void FUN_00d94bc0(lua_State *state, int n);

/* hksi_luaL_buffinit (the name from its assertion message), inlined */
inline void hksi_luaL_buffinit(lua_State *s, luaL_Buffer *b)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x12112382, "s != NULL", "hksi_luaL_buffinit",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 252);
        __builtin_trap();
    }
    b->L = s;
    b->lvl = 0;
    b->p = b->buffer;
}

/* Lua's luaL_addchar, the buffer flushed when it is full */
inline void luaL_addchar(luaL_Buffer *b, char c)
{
    if (b->p == b->buffer + sizeof b->buffer)
        FUN_00ddb460(b);
    *b->p = c;
    ++b->p;
}

/* hksi_luaL_addlstring (the name from its assertion messages), inlined:
 * the characters added piece by piece, the buffer flushed whenever it is
 * full */
inline void hksi_luaL_addlstring(luaL_Buffer *buffer, const char *s, size_t len)
{
    if (!(buffer != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xdbc82653, "buffer", "hksi_luaL_addlstring",
               "Parameter 'buffer' must be a valid luaL_Buffer pointer", HKS_VM_AUX_FILE, 105);
        __builtin_trap();
    }
    if (!(len == 0 || s)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xdbc82654, "len == 0 || s", "hksi_luaL_addlstring",
               "Parameter 's' can not be NULL unless 'len' is 0", HKS_VM_AUX_FILE, 106);
        __builtin_trap();
    }
    while (len) {
        size_t n = buffer->buffer + sizeof buffer->buffer - buffer->p;
        if (n > len)
            n = len;
        if (n == 0) {
            FUN_00ddb460(buffer);
            continue;
        }
        memcpy(buffer->p, s, n);
        s += n;
        buffer->p += n;
        len -= n;
    }
}

/* Lua's luaL_pushresult: the text flushed and its pieces joined */
inline void luaL_pushresult(luaL_Buffer *b)
{
    FUN_00ddb460(b);
    FUN_00d94bc0(b->L, b->lvl);
}

/* derived name: Lua's lua_pop */
inline void pop(lua_State *state, int count)
{
    state->top -= count;
}

#endif
