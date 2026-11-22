/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"

/* derived name: the value of a table under a key, both passed by value
 * (FUN_00db8210, its body not written) */
HksObject FUN_00db8210(lua_State *state, HksObject table, HksObject key);

/* luaL_getmetatable (the name from its assertion message): the registry's
 * value under a name pushed in the name's place; the call timed */
void FUN_00dd4020(lua_State *s, const char *name)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1f772412, "s != NULL", "luaL_getmetatable",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 561);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    const HksObject registry = s->global->registry;
    pushString(s, name);
    const HksObject value = FUN_00db8210(s, registry, s->top[-1]);
    HksObject *top = s->top - 1;
    *top = value;
    s->top = top + 1;
}
