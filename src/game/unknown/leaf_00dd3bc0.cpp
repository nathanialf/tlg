/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"
#include "tlg_hks.h"

/* hksi_luaL_optlstring (the name from its assertion message, FUN_00dd50c0,
 * its body not written): an argument's string, `def` when it is absent or
 * nil */
const char *FUN_00dd50c0(lua_State *s, int argument, const char *def, size_t *length);

/* luaL_checkoption (the name from its assertion message): the index of an
 * argument's string in a null-ended list of names (`def` when the argument
 * is absent), else the argument error; the call timed */
// NONMATCHING: the argument error for a missing string returns what is left in ebx (the base sets no
// value on that path); the build returns 0 there (`xor ebx, ebx`)
int FUN_00dd3bc0(lua_State *s, int argument, const char *def, const char *const *names)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1a99f4a2, "s != NULL", "luaL_checkoption",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 355);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    const char *name = FUN_00dd50c0(s, argument, 0, 0);
    if (!name) {
        name = def;
        if (!name) {
            FUN_00dd38c0(s, argument, "string");
            return 0;
        }
    }
    for (int i = 0; names[i]; ++i) {
        if (strcmp(names[i], name) == 0)
            return i;
    }
    char message[64];
    FUN_00d95b60(message, sizeof(message), "invalid option '%s'", name);
    FUN_00dd3450(s, argument, message);
    return 0;
}
