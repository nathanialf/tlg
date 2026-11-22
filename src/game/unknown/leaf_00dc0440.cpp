/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: luaL_checkinteger (FUN_00dbf960, its body not written) */
int FUN_00dbf960(lua_State *s, int argument);

/* luaL_optinteger (the name from its assertion message): an argument's
 * integer, `def` when it is absent or nil; the call timed */
int FUN_00dc0440(lua_State *s, int argument, int def)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1fa1bc72, "s != NULL", "luaL_optinteger",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 928);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    if (lua_isnoneornil(s, argument))
        return def;
    return FUN_00dbf960(s, argument);
}
