/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"

/* derived name: the value of a table under a key, both passed by value
 * (FUN_00db8210, its body not written) */
HksObject FUN_00db8210(lua_State *state, HksObject table, HksObject key);

/* luaL_newmetatable (the name from its assertion message): the registry's
 * value under a name pushed; when that is nil, a new table in its place,
 * which the registry keeps under the name; the call timed (the base's body
 * sets no result) */
void FUN_00dbf130(lua_State *s, const char *tname)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1361b472, "s != NULL", "luaL_newmetatable",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 865);
        __builtin_trap();
    }
    if (!(tname != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1361b412, "tname != NULL", "luaL_newmetatable",
               "Parameter 'tname' must not be NULL", HKS_VM_AUX_FILE, 866);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    const HksObject registry = s->global->registry;
    pushString(s, tname);
    const HksObject value = FUN_00db8210(s, registry, s->top[-1]);
    HksObject *top = s->top - 1;
    *top = value;
    s->top = top + 1;
    if (typeAt(s, -1) != 0)
        return;
    pop(s, 1);
    FUN_00d91880(s, 0, 0);
    hksi_lua_pushvalue(s, -1);
    hksi_lua_checkstack(s, 2);
    pushString(s, tname);
    top = s->top;
    const HksObject name = top[-1];
    top[-1] = top[-2];
    top[-2] = name;
    s->top = top;
    FUN_00db84e0(s, &s->global->registry, top - 2, top - 1);
    s->top -= 2;
}
