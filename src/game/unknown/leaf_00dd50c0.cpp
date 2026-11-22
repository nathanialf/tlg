/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_luaL_checklstring's out-of-line copy (FUN_00dd3730) */
const char *FUN_00dd3730(lua_State *s, int argument, size_t *length);

/* hksi_luaL_optlstring (the name from its assertion message): an
 * argument's string and its length, `def` (and its length) when it is
 * absent or nil; the call timed */
const char *FUN_00dd50c0(lua_State *s, int argument, const char *def, size_t *length)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xcfa1bc72, "s != NULL", "hksi_luaL_optlstring",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 940);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    if (lua_isnoneornil(s, argument)) {
        if (def && length)
            *length = strlen(def);
        return def;
    }
    return FUN_00dd3730(s, argument, length);
}
