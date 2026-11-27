/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"
#include "tlg_game_object013c8500.h"

/* derived names: the script's file handle (as leaf_00de9a00.cpp names it):
 * the stream and the allocation function, with its user data, that made the
 * 0x18-byte handle (called with the handle, its size and 0 to free it). */
struct FileHandle00de9a50 /* derived name */
{
    FILE *file;                                                              /* +0x0 */
    void *(*allocate)(void *user, void *block, size_t size, size_t newSize); /* +0x8 */
    void *user;                                                              /* +0x10 */
};

extern const char D_15bccf7[35]; /* an object's opening tag: its address and type */
extern const char D_15bcdf1[12]; /* its closing tag */
extern const char D_15bcd1a[50]; /* a link: field, destination, weak */
extern const char D_15bcd4c[40]; /* a link: destination, label */
extern const char D_15bce1c[21]; /* a size */
extern const char D_15bce3c[27]; /* a count of upvalues */
extern const char D_15bce62[27]; /* a count of upvalues, as an attribute */
extern const char D_15bce13[9];  /* "UserData" */
extern const char D_15bce31[11]; /* "c_function" */
extern const char D_15bce57[11]; /* "HksClosure" */
extern const char D_15b94f0[12]; /* "environment" */
extern const char D_15bce7d[7];  /* "method" */
extern const char D_15bce84[8];  /* "upvalue" */
extern const char D_14b31f3[6];  /* "false" */
extern const char D_15bce8c[7];  /* "Method" */
extern const char D_15bce93[8];  /* "unnamed" */
extern const char D_14b3105[8];  /* "unknown" */
extern const char D_15bcdc8[19]; /* a name */
extern const char D_15bce9b[11]; /* a source's opening tag */
extern const char D_15bcea6[11]; /* its closing tag */
extern const char D_15bcdbe[10]; /* "lua_State" */
extern const char D_15bcddb[9];  /* "Registry" */
extern const char D_15bcde4[13]; /* "Global Table" */

/* derived name: a thread's name (the body is not written) */
const char *FUN_00d964f0(const lua_State *state);

/* derived name: writes a source name into the buffer (the body is not
 * written; 0xdd2f70 hands it a 512-byte buffer and prints what it holds) */
void FUN_00db3a90(char *buffer, const char *source);

/* derived names: the object at +0x20 of the writer, whose pointer at +0x78
 * is the environment a link is not written for */
struct State00dd2cf0 {
    u8 unknown0[0x78];
    const void *environment; /* +0x78 */
};

class Object016bba90 : public Object013c8500 /* derived name */
{
  public:
    virtual ~Object016bba90();
    void FUN_00dd2590(const char *format, ...); /* derived name */
    virtual void enterThread(const lua_State *state);
    virtual void enterUserData(const UserData00dd2cf0 *userData);
    virtual void enterCFunction(const Record00dd13d0 *function);
    virtual void enterClosure(const Record00dd1460 *closure);
    virtual void enterMethod(const Record00dd1510 *method);

  private:
    FileHandle00de9a50 *handle18; /* +0x18 */
    State00dd2cf0 *state;         /* +0x20 */
};

/* derived names: 0xdd2590, the writer's print: the format and its arguments
 * to the file of its handle */
void Object016bba90::FUN_00dd2590(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vfprintf(handle18->file, format, args);
    va_end(args);
}

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16bba90 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00dd2650), a writer of the script heap's dump: it writes the closing
 * tag (the string at 0x15bcdaa, "</havokscriptheap>" and a newline) through
 * its own FUN_00dd2590 (variadic: `xor eax, eax` before the call), closes
 * the file of its handle at +0x18 and frees the handle through its
 * allocation function, then runs its base's destructor (tlg_game_object013c8500.h,
 * inlined in the module). FUN_00dd2890, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
extern const char D_15bcdaa[20];

Object016bba90::~Object016bba90()
{
    FUN_00dd2590(D_15bcdaa);
    FileHandle00de9a50 *handle = handle18;
    fclose(handle->file);
    handle->allocate(handle->user, handle, sizeof(FileHandle00de9a50), 0);
}

/* derived names: slot 81, 0xdd2900: a thread's tag, its name, the links to
 * the registry and to its global table, a link to each value of a collected
 * kind from the bottom of its stack to its top (read again at each step),
 * the links numbered from 1, the closing tag */
void Object016bba90::enterThread(const lua_State *state)
{
    FUN_00dd2590(D_15bccf7, state, D_15bcdbe);
    FUN_00dd2590(D_15bcdc8, FUN_00d964f0(state));
    FUN_00dd2590(D_15bcd4c, state->global->registry.value.pointer, D_15bcddb);
    FUN_00dd2590(D_15bcd4c, state->globalTable.value.pointer, D_15bcde4);
    int field = 1;
    for (const HksObject *value = state->stack; value < state->top; ++value) {
        switch (value->type & 0xf) {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 12:
            FUN_00dd2590(D_15bcd1a, field, value->value.pointer, D_14b31f3);
            ++field;
            break;
        }
    }
    FUN_00dd2590(D_15bcdf1);
}

/* derived names: slot 86, 0xdd2cf0: a userdata's tag, its size, the link to
 * its environment unless it is the state's, the closing tag */
void Object016bba90::enterUserData(const UserData00dd2cf0 *userData)
{
    FUN_00dd2590(D_15bccf7, userData, D_15bce13);
    FUN_00dd2590(D_15bce1c, (userData->header >> 10) - 0x20);
    if (userData->environment != state->environment)
        FUN_00dd2590(D_15bcd4c, userData->environment, D_15b94f0);
    FUN_00dd2590(D_15bcdf1);
}

/* derived names: slot 87, 0xdd2d70: a C function's tag, its count of
 * upvalues, a link (numbered from 1) to each upvalue of a collected kind
 * (4 to 10 and 12), the
 * link to its environment unless it is the state's, the closing tag */
// NONMATCHING: the base walks a pointer at +0x38 and keeps the field number
// (i + 1) a 32-bit add apart from the widened counter's increment; the build
// indexes from the record and shares the increment (`inc` in both arms), 238
// bytes for 236 (an index form, a pointer form and a 16-bit counter compiled)
void Object016bba90::enterCFunction(const Record00dd13d0 *function)
{
    FUN_00dd2590(D_15bccf7, function, D_15bce31);
    FUN_00dd2590(D_15bce3c, function->count);
    for (int i = 0; i < function->count; ++i) {
        const HksObject *value = &function->values[i];
        switch (value->type & 0xf) {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 12:
            FUN_00dd2590(D_15bcd1a, i + 1, value->value.pointer, D_14b31f3);
            break;
        }
    }
    if (function->environment != state->environment)
        FUN_00dd2590(D_15bcd4c, function->environment, D_15b94f0);
    FUN_00dd2590(D_15bcdf1);
}

/* derived names: slot 88, 0xdd2e60: a closure's tag, its function's count of
 * upvalues, the link to its function, a link to each upvalue's value of a
 * collected kind, the link to its environment unless it is the state's, the
 * closing tag */
void Object016bba90::enterClosure(const Record00dd1460 *closure)
{
    FUN_00dd2590(D_15bccf7, closure, D_15bce57);
    FUN_00dd2590(D_15bce62, closure->function->count);
    FUN_00dd2590(D_15bcd4c, closure->function, D_15bce7d);
    for (int i = 0; i < closure->function->count; ++i) {
        const HksObject *value = closure->pointers[i]->value;
        switch (value->type & 0xf) {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 12:
            FUN_00dd2590(D_15bcd4c, value->value.pointer, D_15bce84);
            break;
        }
    }
    if (closure->environment != state->environment)
        FUN_00dd2590(D_15bcd4c, closure->environment, D_15b94f0);
    FUN_00dd2590(D_15bcdf1);
}

/* derived names: slot 89, 0xdd2f70: a method's tag, its name and its source
 * from its debug record ("unnamed" and "unknown" without one), the source
 * written into a buffer first, a link (numbered from 3) to each pointer it
 * holds, the closing tag */
// NONMATCHING: the base checks the canary before its last print and makes
// that print a sibling call. Two things stop it here (round 603E, scratch
// e603/lt.ll: with both changed in the linked module the function is equal):
// the print is not marked `tail` (the unit's TailCallElim sees the buffer
// escape into FUN_00db3a90, defined in another unit), and the buffer's
// llvm.lifetime.end follows it, which code generation will not move past
// (isInTailCallPosition, CodeGen/Analysis.cpp:507-520). So the buffer is not
// this function's local in the unit: a helper's, which the unit does not
// inline and the link does. TailCallElim at the link is not the base's (22
// rows lost, e603/notes.md)
void Object016bba90::enterMethod(const Record00dd1510 *method)
{
    FUN_00dd2590(D_15bccf7, method, D_15bce8c);
    const char *source;
    const char *name;
    if (const Record00dd2190 *debug = method->debug) {
        name = debug->name->chars;
        source = debug->source->chars;
    } else {
        name = D_15bce93;
        source = D_14b3105;
    }
    FUN_00dd2590(D_15bcdc8, name);
    FUN_00dd2590(D_15bce9b);
    char buffer[512];
    FUN_00db3a90(buffer, source);
    FUN_00dd2590(buffer);
    FUN_00dd2590(D_15bcea6);
    for (u32 i = 0; i < method->items.count; ++i)
        FUN_00dd2590(D_15bcd1a, i + 3, method->items.items[i], D_14b31f3);
    FUN_00dd2590(D_15bcdf1);
}
