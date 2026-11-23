/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hksi_hks_getname (the name from its assertion message): the state's
 * name, its characters; the call timed */
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 320 at the
 * link, over its threshold of 175: one signature changes no row) */
const char *FUN_00d964f0(lua_State *s)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xab090604, "s != NULL", "hksi_hks_getname",
               "Parameter 's' must be a valid lua_State pointer", HKS_VM_CORE_FILE, 302);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    return s->name->data;
}
