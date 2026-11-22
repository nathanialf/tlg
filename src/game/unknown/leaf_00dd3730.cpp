/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_luaL_checklstring (the name from its assertion message), its
 * out-of-line copy: the string and its length at an index (any index, as
 * indexToHksObjectSafe reads it); the argument error "string" when it holds
 * none */
// NONMATCHING: the base tests LUA_GLOBALSINDEX before LUA_REGISTRYINDEX among the pseudo-indices
// (as in FUN_00dc0440, which matches); the build tests the registry first here
const char *FUN_00dd3730(lua_State *s, int argument, size_t *length)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1a10f3a2, "s != NULL", "hksi_luaL_checklstring",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 323);
        __builtin_trap();
    }
    HksObject *value;
    if (indexToHksObjectSafe(s, argument, &value)) {
        FUN_00dd38c0(s, argument, "string");
        return 0;
    }
    const char *string = FUN_00db6b20(s, value, length);
    if (!string) {
        FUN_00dd38c0(s, argument, "string");
        return 0;
    }
    return string;
}
