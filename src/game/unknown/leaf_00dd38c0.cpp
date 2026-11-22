/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the names of the types, from none (-1) (D_16bbfa0) and
 * hksi_lua_pushfstring (FUN_00d96630) */
extern const char *const D_16bbfa0[14];
const char *FUN_00d96630(lua_State *s, const char *format, ...);

/* hksi_lua_typename (the name from its assertion message), inlined */
inline const char *hksi_lua_typename(int tp)
{
    if (!(tp >= -1 && tp < -1 + 14)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xee4233, "tp >= LUA_TNONE && tp < (LUA_TNONE + NUM_TYPE_OBJECTS)",
               "hksi_lua_typename", "Parameter 'tp' is not in the valid range", HKS_VM_CORE_FILE,
               1239);
        __builtin_trap();
    }
    return D_16bbfa0[tp + 1];
}

/* hksi_lua_type by its arguments (Lua's lua_type), inlined: the type at an
 * index, the two kinds of function (9, 10) read as 6 */
inline int hksi_lua_type(lua_State *s, int index)
{
    const int type = typeAt(s, index);
    return type == 9 || type == 10 ? 6 : type;
}

/* hksi_luaL_typerror (the name from its assertion message): the argument
 * error "<type> expected, got <its type>"; the call timed */
// NONMATCHING: the frame: the base keeps the mark in a 0x18-byte frame (`sub rsp, 0x18`), the build
// pushes one register (`push rax`); the pseudo-indices tested in another order, and the base branches
// around the type name's range check for a function (9, 10: read as 6)
void FUN_00dd38c0(lua_State *s, int argument, const char *type)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xa1ad082, "s != NULL", "hksi_luaL_typerror",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 1224);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    const char *message =
        FUN_00d96630(s, "%s expected, got %s", type, hksi_lua_typename(hksi_lua_type(s, argument)));
    FUN_00dd3450(s, argument, message);
}
