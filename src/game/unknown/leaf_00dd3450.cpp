/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_luaL_error (the name from its assertion message, FUN_00d9cfb0, its
 * body not written) */
int FUN_00d9cfb0(lua_State *s, const char *format, ...);

/* hksi_luaL_argerror (the name from its assertion message): the error
 * "bad argument #<n> to '<the function's name>' (<message>)", the argument
 * counted from the receiver of a method, "bad argument #<n> (<message>)"
 * outside a call; the call timed */
void FUN_00dd3450(lua_State *s, int narg, const char *extramsg)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x12112381, "s != NULL", "hksi_luaL_argerror",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 220);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    lua_Debug ar;
    if (!hksi_lua_getstack(s, 0, &ar)) {
        FUN_00d9cfb0(s, "bad argument #%d (%s)", narg, extramsg);
        return;
    }
    FUN_00d908f0(s, "n", &ar);
    if (ar.name == 0)
        ar.name = "?";
    else if (strcmp(ar.name, "method") == 0)
        --narg;
    FUN_00d9cfb0(s, "bad argument #%d to '%s' (%s)", narg, ar.name, extramsg);
}
