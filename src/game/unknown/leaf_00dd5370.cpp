/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_hksL_loadbuffer (the name from its assertion message, FUN_00dd4dd0,
 * its body not written) */
int FUN_00dd4dd0(lua_State *state, HksGlobal::HksCompilerSettings *settings, const char *buffer,
                 size_t size, const char *name);

/* hksi_hksL_loadstring (the name from its assertion message): a string
 * compiled as a chunk named by itself; the call timed */
int FUN_00dd5370(lua_State *s, HksGlobal::HksCompilerSettings *settings, const char *string)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xa1089716, "s != NULL", "hksi_hksL_loadstring",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 1380);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    return FUN_00dd4dd0(s, settings, string, strlen(string), string);
}
