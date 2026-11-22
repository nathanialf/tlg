/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hks_obj_rawset (the name from its assertion message): a value stored raw
 * under a key of a table (5) or a structure (12); the call timed */
void FUN_00db8af0(lua_State *state, const HksObject *tbl, const HksObject *key,
                  const HksObject *value)
{
    HksApiTimer timer(state);
    if (!((tbl->type & 0xf) == 5 || (tbl->type & 0xf) == 12)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0x9a3be711, "HKS_GET_TYPE(*tbl) == TTABLE || HKS_GET_TYPE(*tbl) == TSTRUCT",
               "hks_obj_rawset", "index does not point to a struct/table", HKS_OBJECT_FILE, 363);
        __builtin_trap();
    }
    if ((tbl->type & 0xf) == 5)
        FUN_00d9c0e0(tbl->value.table, state, key, value);
    else
        FUN_013be510(tbl->value.structure, state, key, value);
}
