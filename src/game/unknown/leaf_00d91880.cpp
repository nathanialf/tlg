/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the table made with room for its array and hash parts
 * (FUN_00d9c340, its body not written) */
void *FUN_00d9c340(lua_State *state, int arrayCount, int hashCount);

/* hksi_lua_createtable (the name from its assertion message): a new table
 * pushed, the call timed */
void FUN_00d91880(lua_State *s, int arrayCount, int hashCount)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xf001a876, "s != NULL", "hksi_lua_createtable",
               "Parameter 's' must be a valid state pointer", HKS_VM_CORE_FILE, 1403);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    void *table = FUN_00d9c340(s, arrayCount, hashCount);
    HksObject *top = s->top;
    top->type = 5;
    top->value.pointer = table;
    s->top = top + 1;
}
