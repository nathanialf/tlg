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
    /* +0x4 is padding: a value passed by value hands its type in a 32-bit
     * register (FUN_00db84e0's `mov esi, [rcx]`) */

    union {
        int boolean;                 /* derived name */
        float number;                /* derived name */
        void *pointer;               /* derived name */
        struct HksTable *table;      /* derived name: tag 5 */
        struct HksStruct *structure; /* derived name: tag 12 */
    } value;                         /* derived name */
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
    u8 unknown0[0x58];
    /* +0x58, derived name: what the collector marks a value into
     * (FUN_00dc6090 takes its address: FUN_00db9c70) */
    u8 gray[0xc];

    /* +0x64, derived name: the collector's weights, twelve ints that
     * getgcweights copies out (FUN_00dea130) and setgcweights copies back
     * (FUN_00de9ef0); their names are the strings of the table at
     * 0x16bba30, in the same order */
    struct HksGcWeights {
        int removeString;
        int finalizeUserdataNoMM;
        int finalizeUserdataGcMM;
        int cleanCoroutine;
        int removeWeak;
        int markObject;
        int traverseString;
        int traverseUserdata;
        int traverseCoroutine;
        int traverseWeakTable;
        int freeChunk;
        int sweepTraverse;
    } gcWeights;

    u8 unknown94[0x24];
    /* +0xb8, derived name: the collector's phase, 1 while it marks
     * (FUN_00db9c70) */
    int gcState;
    u8 unknownbc[0xdc];
    /* +0x198, derived name: an object whose +0x8 is compared with a new
     * userdata, which then takes its place (FUN_00dba890) */
    struct HksUserdata *unknown198;
    u8 unknown1a0[0x8];
    /* +0x1a8, derived name: the table of the VM's strings FUN_00db9de0
     * makes a string in (FUN_00dd06f0) */
    u8 strings[0x20];
    /* +0x1c8, derived name: the registry, its table linked as "Registry"
     * (FUN_00dd2900), the value debug.getregistry pushes (FUN_00deb2b0) */
    HksObject registry;
    u8 unknown1d8[0x20];
    /* +0x1f8, derived name: the list of userdata, each new one linked first
     * (FUN_00dba890) */
    struct HksUserdata *userdata;
    lua_State *mainThread;   /* +0x200, derived name */
    HksObject unknown208[1]; /* +0x208, derived name; its extent not traced */
    u8 unknown218[0x280];
    /* +0x498, derived name: the debugger print hands the arguments to
     * (FUN_00debd90), null without one */
    struct HksDebugger *debugger;
    u8 unknown4a0[0x8];
    /* +0x4a8 to +0x4ec, derived names: the API timer's state (HksApiTimer
     * below, from the entry and exit of every timed API function, the
     * first of them FUN_00d91880): two signed counters, the second set to
     * 0 for the call and its value put back at the end; the counter read
     * last; the cycles and the calls counted for each counter while it is
     * negative */
    s64 apiCounter;   /* +0x4a8, decremented for each call, incremented at its end */
    s64 apiCounter2;  /* +0x4b0 */
    u64 apiLastCycle; /* +0x4b8 */
    s64 apiCycles;    /* +0x4c0 */
    s64 apiCycles2;   /* +0x4c8 */
    u8 unknown4d0[0x18];
    int apiCalls;  /* +0x4e8 */
    int apiCalls2; /* +0x4ec */
    u8 unknown4f0[0x8];
    int userdataCount; /* +0x4f8, derived name: counted up for each new userdata (FUN_00dba890) */
    u8 unknown4fc[0x4];
    int unknown500; /* +0x500, derived name: counted up for each string FUN_00db9de0 makes */
    u8 unknown504[0x54];

    /* +0x558, derived name: the compiler's settings loadstring hands to
     * the loader (FUN_00dbe6c0); compilerSettings sets +0x558 and +0x568
     * (FUN_00de9e70) */
    struct HksCompilerSettings {
        int unknown0;
        u8 unknown4[0xc];
        int unknown10;
    } compilerSettings;
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

/* A call's record as the state keeps them (0x18 bytes, from +0x18 of the
 * state): the frame's base first (FUN_00db5b50). derived name. */
struct HksCallInfo {
    HksObject *base;    /* derived name */
    const u32 *savedPc; /* +0x8, derived name: the calling function's next instruction */
    /* +0x10, derived name: the tail calls the record stands for, each
     * counted as a level by hksi_lua_getstack (FUN_00dd3450) */
    short tailcalls;
    short
        unknown12; /* +0x12, derived name: counted back from the next record's base with the function's slot (FUN_00ddb700) */
    u8 unknown14[0x4];
};

struct lua_State {
    u8 unknown0[0x10];
    HksGlobal *global; /* +0x10, derived name */
    /* +0x18 and +0x28, derived names: the first call's record and the
     * running one's (the running call's depth is their difference,
     * FUN_00dba890, FUN_00db5b50); the first one's address is what
     * FUN_00dbb2e0 takes */
    HksCallInfo *callInfos;
    u8 unknown20[0x8];
    HksCallInfo *callInfo;
    /* +0x30 to +0x40, derived names: the running function's next
     * instruction, another one kept for the call at the depth at +0x40
     * (FUN_00ddb700) */
    const u32 *pc;
    const u32 *unknown38;
    int unknown40;
    u8 unknown44[0x4];
    HksObject *top;   /* derived name */
    HksObject *base;  /* derived name */
    HksObject *last;  /* +0x58, derived name: the end of the stack's room */
    HksObject *stack; /* +0x60, derived name: the first value FUN_00dd2900 links */
    u8 unknown68[0x8];
    /* +0x70, derived name: the globals' table, its value linked as "Global
     * Table" (FUN_00dd2900), the value LUA_GLOBALSINDEX reaches */
    HksObject globalTable;
    /* +0x80, derived name: the slot LUA_ENVIRONINDEX sets to the running
     * function's environment (indexToHksObjectSafe) */
    HksObject environment;
    u8 unknown90[0x8];
    /* +0x98, derived name: below 2 a running thread may yield (FUN_00ded070:
     * "attempt to yield across metamethod/C-call boundary" from 2 up) */
    int unknown98;
    u8 unknown9c[0xc];
    struct HksString
        *name; /* +0xa8, derived name: the state's name (hksi_hks_getname, FUN_00d964f0) */
    u8 unknownb0[0x10];
    /* +0xc0, derived name: the thread's state as coroutine.status reads it
     * (FUN_00decef0): 1 suspended unless its frame is empty, 2 normal, 3
     * suspended, 4 dead */
    int status;
    /* +0xc4, derived name: the API timer's mark (HksApiTimer below): 0
     * through a timed call, put back at its end unless it reads -500 then */
    int apiTimerMark;
};

/* The time-stamp counter, read through inline assembly as the script VM's
 * API timer reads it (the base joins the halves as `mov eax, eax; shl rdx,
 * 32; or`, the low half widened from its 32 bits, at every site of
 * FUN_00d91880's family; the compiler's __rdtsc() joins its 64-bit copies
 * of rax and rdx without that widening; docs/DECISIONS.md D34; the asm
 * emits the read itself and steers nothing). derived name. */
inline u64 hksReadTimeStampCounter()
{
    u32 low;
    u32 high;
    __asm__ __volatile__("rdtsc" : "=a"(low), "=d"(high));
    return low | (static_cast<u64>(high) << 32);
}

/* The VM's timer of an API call, a scope from just after the call's
 * argument checks to its return (FUN_00d91880, FUN_00db6f40,
 * FUN_00db84e0): at the start the cycles since the counter's last read
 * counted for each of the global's two counters that is negative, the
 * first counter decremented, the second and the state's mark set to 0; at
 * the end, unless the mark reads -500, the cycles counted for the first,
 * the first counter incremented and the second counter and the mark put
 * back. derived name. */
class HksApiTimer
{
  public:
    explicit HksApiTimer(lua_State *s)
        : state(s), global(s->global), savedCounter2(global->apiCounter2),
          savedMark(s->apiTimerMark)
    {
        const u64 now = hksReadTimeStampCounter();
        const s64 mask = global->apiCounter >> 63;
        const s64 mask2 = global->apiCounter2 >> 63;
        const s64 elapsed = now - global->apiLastCycle;
        global->apiCycles += elapsed & mask;
        global->apiCycles2 += elapsed & mask2;
        global->apiCalls += mask & 1;
        global->apiCalls2 += mask2 & 1;
        --global->apiCounter;
        global->apiCounter2 = 0;
        global->apiLastCycle = now;
        state->apiTimerMark = 0;
    }

    ~HksApiTimer()
    {
        if (state->apiTimerMark == -500)
            return;
        const u64 now = hksReadTimeStampCounter();
        global->apiCycles += now - global->apiLastCycle;
        ++global->apiCalls;
        ++global->apiCounter;
        global->apiCounter2 = savedCounter2;
        global->apiLastCycle = now;
        state->apiTimerMark = savedMark;
    }

  private:
    lua_State *state;
    HksGlobal *global;
    s64 savedCounter2;
    int savedMark;
};

/* A string as the VM holds it: its length in the low 62 bits of the word
 * at +0x8 (the top two bits are not the length), its hash (hashString in
 * tlg_hks_string.h, read back by FUN_00e81bd0) at +0x10, its characters from
 * +0x14 (FUN_00db6f40). derived name. */
struct HksString {
    u8 unknown0[0x8];
    u64 lengthAndFlags; /* derived name */
    u32 hash;           /* +0x10, derived name */
    char data[1];       /* +0x14, derived name */

    /* derived name: the length, the word's low 62 bits */
    size_t length() const
    {
        return lengthAndFlags & 0x3fffffffffffffff;
    }
};

/* derived name: a string made in the VM's table of strings (FUN_00dd06f0,
 * its body not written), found there when it is in it already */
void *FUN_00dd06f0(void *strings, lua_State *state, int unknown, const char *text, size_t length,
                   u32 hash);

/* A table and a structure as FUN_00db84e0 reads them: the metatable each
 * must lack for a raw store (+0x10 of a table, +0x20 of a structure; the
 * word's low bit set when the metatable is a structure: FUN_00d96dd0). derived
 * names. */
struct HksNode;

struct HksTable {
    u8 unknown0[0x10];
    void *metatable; /* +0x10, derived name: null without one (FUN_00d96dd0) */
    u8 unknown18[0x4];
    /* +0x1c to +0x30, derived names: the hash part (its nodes, null
     * without one, and the mask of their count) and the array part (its
     * values and their count; FUN_00db9130) */
    u32 mask;
    HksNode *nodes;
    HksObject *array;
    u32 arraySize;
};

/* derived names: a node of a table's hash part, its key and value; the
 * nodes' next links are kept before the nodes, the link of node i at index
 * ~i (FUN_00db9130) */
struct HksNode {
    HksObject key;
    HksObject value;
};

/* derived name: Lua's luaH_getn, the length of a table (leaf_00db9aa0.cpp) */
unsigned FUN_00db9aa0(HksTable *table);

/* derived names: a structure's type: its name (a string object, at +0x18;
 * FUN_00de0a90) and its named slots from +0x20, their count first: each
 * slot's name and its index among the structure's words (FUN_00db8650) */
struct HksStructSlot {
    HksString *name;
    u8 unknown8[0x9];
    u8 index; /* +0x11 */
    u8 unknown12[0x6];
};

struct HksStructType {
    size_t slotCount;
    u8 unknown8[0x10];
    void *name; /* +0x18 */
    HksStructSlot slots[1];
};

/* derived names: the structure, its type at +0x18; its words from +0x10 in
 * blocks of eight, the first word of each block holding the type tags of
 * the block's words, one byte each (FUN_00db8650) */
struct HksStruct {
    u8 unknown0[0x10];
    /* +0x10: the words run on past it (the type, the metatable and the
     * table are words 1 to 3) */
    u64 words[1];
    HksStructType *type; /* +0x18 */
    void *metatable;     /* +0x20, derived name: null without one (FUN_00d96dd0) */
    HksTable *table;     /* +0x28, derived name: its table, null without one (FUN_00d96ff0) */
};

/* derived names: a table's or a structure's raw store of a value under a
 * key (FUN_00d9c0e0 for a table, FUN_013be510 for a structure) and the
 * store through the metamethods (FUN_00dc8b40, the table passed by
 * value: FUN_00db84e0 hands its words in rsi and rdx); their bodies not
 * written */
void FUN_00d9c0e0(HksTable *table, lua_State *state, const HksObject *key, const HksObject *value);
void FUN_013be510(HksStruct *structure, lua_State *state, const HksObject *key,
                  const HksObject *value);
void FUN_00dc8b40(lua_State *state, HksObject table, const HksObject *key, const HksObject *value,
                  int unknown);

/* derived name: a table's raw read of the value under a key (FUN_00d9bf30,
 * its body not written; the value returned in rax and rdx) */
HksObject FUN_00d9bf30(HksTable *table, const HksObject *key);

/* derived names: a structure's word at an index and its type tag (the
 * byte of the block's first word), and the structure's raw read of the
 * value under a key: a named slot's for a string key (tag 4), else its
 * table's, nil (both words 0) without a table (FUN_00db8650) */
inline void structureWord(const HksStruct *structure, size_t index, HksObject &value)
{
    value.value.pointer = reinterpret_cast<void *>(structure->words[index]);
    value.type = reinterpret_cast<const u8 *>(structure->words)[index / 8 * 64 + index % 8] & 0xf;
}

inline HksObject structureGet(const HksStruct *structure, const HksObject *key)
{
    HksObject value;
    if ((key->type & 0xf) == 4) {
        const HksStructType *type = structure->type;
        for (size_t i = 0; i < type->slotCount; ++i) {
            if (type->slots[i].name == key->value.pointer) {
                structureWord(structure, type->slots[i].index, value);
                return value;
            }
        }
    }
    if (HksTable *table = structure->table) {
        value = FUN_00d9bf30(table, key);
    } else {
        value.value.pointer = 0;
        value.type = 0;
    }
    return value;
}

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

/* The VM's core source, as its assertions pass it (`__FILE__` in
 * vm-core.cpp, which defines hksi_lua_createtable: FUN_00d91880). derived
 * name. */
#define HKS_VM_CORE_FILE                                                                           \
    "D:\\trico\\engine\\anzu\\external\\havok\\HavokScriptVM-2013.3.0\\build/../source/"           \
    "virtualMachine/vm-core.cpp"

/* The VM's object source and its call's inline file, as their assertions
 * pass them (`__FILE__` in hksObject.cpp: hks_obj_rawset, FUN_00db8af0;
 * in vm-core.inl: vm_call, FUN_00d95e60). derived names. */
#define HKS_OBJECT_FILE                                                                            \
    "D:\\trico\\engine\\anzu\\external\\havok\\HavokScriptVM-2013.3.0\\build/../source/"           \
    "virtualMachine/hksObject.cpp"
#define HKS_VM_CORE_INL_FILE                                                                       \
    "D:\\trico\\engine\\anzu\\external\\havok\\HavokScriptVM-2013.3.0\\build/../source/"           \
    "virtualMachine/Compiler/../vm-core.inl"

/* The VM's source file, as its assertions pass it (`__FILE__` in
 * vm-aux.cpp, which defines luaL_checknumber). derived name. */
#define HKS_VM_AUX_FILE                                                                            \
    "D:\\trico\\engine\\anzu\\external\\havok\\HavokScriptVM-2013.3.0\\build/../source/"           \
    "virtualMachine/vm-aux.cpp"

/* The VM's debugger source, as its assertions pass it (`__FILE__` in
 * vm-debug.cpp). derived name. */
#define HKS_VM_DEBUG_FILE                                                                          \
    "D:\\trico\\engine\\anzu\\external\\havok\\HavokScriptVM-2013.3.0\\build/../source/"           \
    "virtualMachine/Debug/vm-debug.cpp"

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

/* derived name: Lua's lua_tolstring by its value: the string a value reads
 * as and its length, a number made a string in its slot (FUN_00db6b20,
 * leaf_00db6b20.cpp); null and the length 0 for any other value */
const char *FUN_00db6b20(lua_State *state, HksObject *value, size_t *length);

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
    HksObject *value = s->base + (argument - 1);
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
 * `cmp [rcx+8], 0; setne`). The slot is a select of null past the top and
 * the type is read under the same test, so the branch is on the frame's
 * test and the select stays for the loads (`cmovae; jae` on one compare,
 * 19 sites of the base, FUN_00a44f20's form); with the slot made null in a
 * branch and tested for null, the test is threaded and the type read from
 * the frame (`jae` alone) */
inline bool toBoolean(lua_State *state, int argument)
{
    const HksObject *slot = state->base + (argument - 1);
    const HksObject *value = slot < state->top ? slot : 0;
    const int type = slot < state->top ? value->type & 0xf : 0;
    bool truth = false;
    if (type != 0) {
        truth = true;
        if (type == 1)
            truth = value->value.boolean != 0;
    }
    return truth;
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
struct HksUserdata {   /* derived name */
    u64 flags;         /* derived name: the low bit cleared when it is made (FUN_00dba890) */
    HksUserdata *next; /* +0x8, derived name: the next in the global's list */
    void *environment; /* +0x10, derived name: the table getfenv reads (FUN_00db7b30) */
    void *metatable;   /* +0x18, derived name: null without one (FUN_00d96dd0) */
};

/* A script function (tag 9) and a C function (tag 10) as getfenv reads
 * them: each one's environment's table at +0x18 (FUN_00db7b30, a case of
 * its own for each). derived names. */
struct HksClosure {
    u8 unknown0[0x10];
    struct HksProto *proto; /* +0x10, derived name: the function's code (FUN_00ddb700) */
    void *environment;      /* derived name */
    u8 unknown20[0x18];
    /* +0x38, derived name: its upvalues, as many as its code's count
     * (FUN_00d96220) */
    struct HksUpvalue *upvalues[1];
};

/* derived name: an upvalue of a script function: the value it reaches at
 * +0x20 (FUN_00d96220) */
struct HksUpvalue {
    u8 unknown0[0x20];
    HksObject *value; /* derived name */
};

/* derived names: a script function's code as FUN_00ddb700 reads it: its
 * instructions (4 bytes each) from +0x20, its debug information at +0x48
 * (null without one): the count of its local variables at +0x38 and their
 * records from +0x40: the name (a string), the first instruction and the
 * last that see it */
struct HksLocalVariable {
    HksString *name;
    int startPc;
    int endPc;
};

struct HksDebugInfo {
    u8 unknown0[0x18];
    /* +0x18 and +0x20, derived names: the count of its upvalues' names
     * and the names (FUN_00d96220) */
    int upvalueNameCount;
    HksString **upvalueNames;
    HksString *source; /* +0x28, derived name: a string the collector marks (FUN_00dc57d0) */
    HksString *name;   /* +0x30, derived name: what hksi_hks_setfname sets (FUN_00db6800) */
    int localVariableCount;
    HksLocalVariable *localVariables;
};

struct HksProto {
    u8 unknown0[0x10];
    u16 upvalueCount; /* +0x10, derived name (FUN_00d96220) */
    u8 unknown12[0xe];
    const u32 *code;
    /* +0x28 to +0x40, derived names: its constants (16-byte values) and the
     * functions defined in it, each count first (FUN_00dc57d0) */
    int constantCount;
    HksObject *constants;
    int protoCount;
    HksProto **protos;
    HksDebugInfo *debugInfo;
};

/* Lua's lua_Debug as far as the bytes read it: the depth of the call it
 * describes at +0x240, and +0x244, which must be 0 to reach its locals
 * (FUN_00ddb700). */
struct lua_Debug {
    /* the fields the constructor sets (FUN_00dd3450, FUN_00dd41f0), named
     * as Lua 5.1 names them where the offsets agree; derived names */
    lua_Debug()
    {
        name = 0;
        namewhat = "";
        what = 0;
        source = 0;
        currentline = -1;
        nups = 0;
        linedefined = 0;
        unknown38 = -1;
        unknown3c = -1;
        short_src[0] = 0;
        i_ci = -1;
        unknown244 = -1;
    }

    int event;
    const char *name;     /* +0x8 */
    const char *namewhat; /* +0x10 */
    const char *what;     /* +0x18 */
    const char *source;   /* +0x20 */
    int currentline;      /* +0x28 */
    int nups;             /* +0x2c */
    int linedefined;      /* +0x30 */
    u8 unknown34[0x4];
    int unknown38;
    int unknown3c;
    char short_src[0x200]; /* +0x40 */
    int i_ci;              /* +0x240 */
    int unknown244;        /* derived name */
};

/* hksi_lua_getstack (the name from its assertion message), inlined: the
 * call `level` levels below the running one (a record's tail calls count
 * as levels) described in `ar` (its record's depth, and whether it is
 * inside the record's tail calls), 0 when there are not that many */
inline int hksi_lua_getstack(lua_State *s, int level, lua_Debug *ar)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x23238436, "s != NULL", "hksi_lua_getstack",
               "Parameter 's' must be a valid state pointer", HKS_VM_DEBUG_FILE, 851);
        __builtin_trap();
    }
    if (level < 0)
        return 0;
    for (int i = s->callInfo - s->callInfos; i >= 0; --i) {
        const int calls = s->callInfos[i].tailcalls + 1;
        if (level < calls) {
            ar->unknown244 = level > 0;
            ar->i_ci = i;
            return 1;
        }
        level -= calls;
    }
    return 0;
}

/* derived name: hksi_lua_getinfo by its arguments (FUN_00d908f0, its body
 * not written) */
int FUN_00d908f0(lua_State *s, const char *what, lua_Debug *ar);

struct HksCClosure {
    u8 unknown0[0x18];
    void *environment;  /* derived name */
    short upvalueCount; /* +0x20, derived name (FUN_00d96220) */
    u8 unknown22[0x6];
    HksString *name; /* +0x28, derived name: what hksi_hks_setfname sets (FUN_00db6800) */
    HksObject
        upvalues[1]; /* +0x30, derived name: the pseudo-indices below LUA_GLOBALSINDEX reach them */
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

/* derived name: an argument's string (FUN_00db6b20; a null value for an
 * argument past the frame's top, `cmovae rsi, rbx` at 0xe7f2eb) */
inline const char *stringOf(lua_State *state, int argument) /* derived name */
{
    HksObject *value = state->base + (argument - 1);
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
void FUN_00dbb2e0(HksCallInfo **callInfos, lua_State *state, int n);

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
        FUN_00dbb2e0(&s->callInfos, s, n);
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

/* hksi_lua_insert (the name from its assertion message), inlined: the
 * stack's top value moved down to an index, the ones from there up moved
 * up one (a negative index made relative to the base for the check) */
inline void hksi_lua_insert(lua_State *s, int index)
{
    const int offset = index < 0 ? index + 1 + argumentCount(s) : index;
    if (!(offset > 0 && offset <= argumentCount(s))) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x211fff22, "offset > 0 && offset <= hks::S_API_STACK_FRAMESIZE(s)",
               "hksi_lua_insert", "Parameter 'index' is invalid", HKS_LUA_IMPL_FILE, 912);
        __builtin_trap();
    }
    HksObject *p = index < 0 ? s->top + index : s->base + (index - 1);
    HksObject *q = s->top - 1;
    const HksObject value = *q;
    for (; q != p; --q)
        *q = q[-1];
    *p = value;
}

/* derived names: the depth of the running call and the slot that holds
 * the base of the call at a depth (the state's own for the running call,
 * else kept in the next call's record) */
inline int callDepth(lua_State *s)
{
    return s->callInfo - s->callInfos;
}

inline HksObject **frameBaseSlot(lua_State *s, int level)
{
    return level == callDepth(s) ? &s->base : &s->callInfos[level + 1].base;
}

/* derived name: Lua's findlocal (FUN_00ddb700): the name of a call's n-th
 * local variable, "(*temporary)" for a slot of its frame without one, else
 * null; it reads and writes nothing else */
const char *FUN_00ddb700(lua_State *s, const lua_Debug *ar, int n);

/* derived name: Lua's lua_objlen by its arguments: the length of a value
 * (FUN_00d96ff0) */
size_t FUN_00d96ff0(lua_State *state, const HksObject *value);

/* The pseudo-indices (Lua 5.1's, by the values the bytes compare with) */
#define LUA_REGISTRYINDEX (-10000)
#define LUA_ENVIRONINDEX (-10001)
#define LUA_GLOBALSINDEX (-10002)

/* indexToHksObjectSafe (the name from its assertion message), inlined:
 * whether an index reaches a value, and the value: an argument (from 1) or
 * one from the stack's top (from -1), null and false outside the frame;
 * the globals, the registry, the running function's environment (set in
 * the state's slot for it) or one of its upvalues for a pseudo-index */
inline int indexToHksObjectSafe(lua_State *s, int index, HksObject **object)
{
    if (index > LUA_REGISTRYINDEX) {
        if (index > 0) {
            HksObject *value = s->base + index - 1;
            const int outside = !(value < s->top);
            *object = outside ? 0 : value;
            return outside;
        }
        if (index < 0) {
            HksObject *value = s->top + index;
            const int outside = !(value >= s->base);
            *object = outside ? 0 : value;
            return outside;
        }
        *object = 0;
        return 1;
    }
    if (index == LUA_GLOBALSINDEX) {
        *object = &s->globalTable;
    } else if (index == LUA_REGISTRYINDEX) {
        *object = &s->global->registry;
    } else {
        /* the running function, below the frame's base */
        HksObject *base = s->base;
        if (index == LUA_ENVIRONINDEX) {
            if (!(base > s->stack)) {
                printf(
                    "Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
                    "%s() : \"%s\"\n\tat %s(%d)\n",
                    0x47daca3b, "S_API_STACK_BASE(s) > S_API_STACK_BOTTOM(s)",
                    "indexToHksObjectSafe", "No context for LUA_ENVIRONINDEX", HKS_LUA_IMPL_FILE,
                    87);
                __builtin_trap();
            }
            s->environment.value.pointer =
                static_cast<HksCClosure *>(base[-1].value.pointer)->environment;
            s->environment.type = 5;
            *object = &s->environment;
        } else {
            *object = static_cast<HksCClosure *>(base[-1].value.pointer)->upvalues +
                      (LUA_GLOBALSINDEX - index - 1);
        }
    }
    return 0;
}

/* derived name: indexToHksObjectSafe without its assertion, as the game's
 * own script functions resolve an index (FUN_00e81bd0: the environment's
 * pseudo-index reads the running function below the frame's base with no
 * test of the stack's bottom), the registry tested before the globals as
 * in indexToHksObjectFast (the base compares -10002 first: the case
 * written first is tested last) */
inline int indexToHksObjectUnchecked(lua_State *s, int index, HksObject **object)
{
    if (index > LUA_REGISTRYINDEX) {
        if (index > 0) {
            HksObject *value = s->base + index - 1;
            const int outside = !(value < s->top);
            *object = outside ? 0 : value;
            return outside;
        }
        if (index < 0) {
            HksObject *value = s->top + index;
            const int outside = !(value >= s->base);
            *object = outside ? 0 : value;
            return outside;
        }
        *object = 0;
        return 1;
    }
    if (index == LUA_REGISTRYINDEX) {
        *object = &s->global->registry;
    } else if (index == LUA_GLOBALSINDEX) {
        *object = &s->globalTable;
    } else {
        /* the running function, below the frame's base */
        HksObject *base = s->base;
        if (index == LUA_ENVIRONINDEX) {
            s->environment.value.pointer =
                static_cast<HksCClosure *>(base[-1].value.pointer)->environment;
            s->environment.type = 5;
            *object = &s->environment;
        } else {
            *object = static_cast<HksCClosure *>(base[-1].value.pointer)->upvalues +
                      (LUA_GLOBALSINDEX - index - 1);
        }
    }
    return 0;
}

/* indexToHksObjectFast (the name from its assertion message), inlined:
 * the value an index reaches, unchecked: an argument (from 1) or one from
 * the stack's top (0 and below); the globals, the registry, the running
 * function's environment (set in the state's slot for it) or one of its
 * upvalues for a pseudo-index */
inline HksObject *indexToHksObjectFast(lua_State *s, int index)
{
    if (index > LUA_REGISTRYINDEX) {
        if (index > 0)
            return s->base + index - 1;
        return s->top + index;
    }
    if (index == LUA_REGISTRYINDEX)
        return &s->global->registry;
    if (index == LUA_GLOBALSINDEX)
        return &s->globalTable;
    /* the running function, below the frame's base */
    HksObject *base = s->base;
    if (index == LUA_ENVIRONINDEX) {
        if (!(base > s->stack)) {
            printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
                   "%s() : \"%s\"\n\tat %s(%d)\n",
                   0x47daca3a, "S_API_STACK_BASE(s) > S_API_STACK_BOTTOM(s)",
                   "indexToHksObjectFast", "No context for LUA_ENVIRONINDEX", HKS_LUA_IMPL_FILE,
                   125);
            __builtin_trap();
        }
        s->environment.value.pointer =
            static_cast<HksCClosure *>(base[-1].value.pointer)->environment;
        s->environment.type = 5;
        return &s->environment;
    }
    return static_cast<HksCClosure *>(base[-1].value.pointer)->upvalues +
           (LUA_GLOBALSINDEX - index - 1);
}

/* hksi_lua_pushvalue (the name from its assertion message), inlined: a
 * copy of the value at an index pushed */
inline void hksi_lua_pushvalue(lua_State *s, int index)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1238a, "s != NULL", "hksi_lua_pushvalue",
               "Parameter 's' must be a valid state pointer", HKS_LUA_IMPL_FILE, 837);
        __builtin_trap();
    }
    const HksObject *value = indexToHksObjectFast(s, index);
    HksObject *top = s->top;
    *top = *value;
    s->top = top + 1;
}

/* derived names: the head every collected object starts with, its low bit
 * the collector's mark, and the marking of a value's object (FUN_00dc6090,
 * its body not written) */
struct HksGcObject {
    u64 flags;
};

void FUN_00dc6090(void *gray, const HksObject *value);

/* derived name: the collector's barrier, inlined (FUN_00db9c70 times it as
 * a call; FUN_00db6800): while it marks, a value stored in a marked object
 * has its own object marked (a string only marked, a fixed string, its
 * length's top bit set, left alone) */
inline void gcBarrier(lua_State *s, HksGcObject *parent, const HksObject *value)
{
    HksGlobal *global = s->global;
    const int type = value->type & 0xf;
    if (global->gcState == 1) {
        switch (type) {
        case 4: /* a string, table, function, userdata, thread or structure */
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 12:
            break;
        default:
            return;
        }
        if (parent->flags & 1) {
            if (type == 4 &&
                static_cast<s64>(static_cast<HksString *>(value->value.pointer)->lengthAndFlags) <
                    0)
                return;
            HksGcObject *object = static_cast<HksGcObject *>(value->value.pointer);
            if (!(object->flags & 1)) {
                object->flags |= 1;
                if (type != 4)
                    FUN_00dc6090(global->gray, value);
            }
        }
    }
}

/* derived name: the tag of the value at an index (its low four bits), -1
 * (none) outside the frame */
inline int typeAt(lua_State *s, int index) /* derived name */
{
    HksObject *value;
    if (indexToHksObjectSafe(s, index, &value))
        return -1;
    return value->type & 0xf;
}

/* hksi_lua_type by its arguments (Lua's lua_type; the name from an
 * assertion's text: FUN_00db6800), inlined: the type at an index, the two
 * kinds of function (9, 10) read as 6 */
inline int hksi_lua_type(lua_State *s, int index)
{
    const int type = typeAt(s, index);
    return type == 9 || type == 10 ? 6 : type;
}

/* Lua's lua_isnoneornil, as a macro over lua_isnone and lua_isnil: the
 * type read twice (the base stores the environment's slot once for each) */
#define lua_isnoneornil(s, n) (typeAt(s, n) == -1 || typeAt(s, n) == 0)

/* derived name: Lua's lua_pop */
inline void pop(lua_State *state, int count)
{
    state->top -= count;
}

#endif
