/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_lua_getlocal (the name from its assertion messages): the value of
 * the n-th local variable of the call ar describes pushed, its name
 * returned (null and nothing pushed without one); the call timed */
const char *FUN_00d96010(lua_State *s, const lua_Debug *ar, int n)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x23088436, "s != NULL", "hksi_lua_getlocal",
               "Parameter 's' must be a valid state pointer", HKS_VM_DEBUG_FILE, 826);
        __builtin_trap();
    }
    if (!(ar != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x23023907, "ar != NULL", "hksi_lua_getlocal",
               "Parameter 'ar' must be a valid lua_Debug pointer", HKS_VM_DEBUG_FILE, 827);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    const char *name = FUN_00ddb700(s, ar, n);
    if (name) {
        const HksObject *value = &(*frameBaseSlot(s, ar->i_ci))[n - 1];
        HksObject *top = s->top;
        *top = *value;
        s->top = top + 1;
    }
    return name;
}
