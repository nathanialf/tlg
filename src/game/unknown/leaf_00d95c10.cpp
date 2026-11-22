/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"

/* derived name: Lua's lua_getmetatable (FUN_013bd4e0, its body not
 * written): the metatable of the value at an index pushed (1), else
 * nothing pushed (0) */
int FUN_013bd4e0(lua_State *s, int index);

/* hksi_luaL_getmetafield (the name from its assertion message): the field
 * `event` of the metatable of the value at an index pushed (1), else
 * nothing pushed (0, also for a nil field); the call timed */
int FUN_00d95c10(lua_State *s, int index, const char *event)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x1f772402, "s != NULL", "hksi_luaL_getmetafield",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 529);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    if (!FUN_013bd4e0(s, index))
        return 0;
    pushString(s, event);
    getTableBelow(s);
    const HksObject *field = s->top - 1;
    if (field >= s->base && (field->type & 0xf) == 0) {
        pop(s, 2);
        return 0;
    }
    hksi_lua_remove(s, -2);
    return 1;
}
