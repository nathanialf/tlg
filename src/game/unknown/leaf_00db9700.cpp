/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the entry after a key of a table and of a structure, the
 * key replaced by the next one and the value returned (FUN_00db98e0,
 * FUN_00db99b0; their bodies not written) */
HksObject FUN_00db98e0(HksTable *table, HksObject *key);
HksObject FUN_00db99b0(HksStruct *structure, HksObject *key);

/* hks_obj_next (the name from its assertion messages): the entry after
 * `key` of a table or a structure, its value written to `value`, the key
 * nil past the last entry; the call timed */
void FUN_00db9700(lua_State *state, const HksObject *tbl, HksObject *key, HksObject *value)
{
    HksApiTimer timer(state);
    if (!(tbl != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xdbc0aa30, "tbl != NULL", "hks_obj_next",
               "The item indexed with lua_next is not a table.", HKS_OBJECT_FILE, 472);
        __builtin_trap();
    }
    if (!((tbl->type & 0xf) == 5 || (tbl->type & 0xf) == 12)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xdbc0aa31, "HKS_GET_TYPE(*tbl) == TTABLE || (HKS_GET_TYPE(*tbl) == TSTRUCT)",
               "hks_obj_next", "The item indexed with lua_next is not a struct/table.",
               HKS_OBJECT_FILE, 475);
        __builtin_trap();
    }
    if ((tbl->type & 0xf) == 5)
        *value = FUN_00db98e0(tbl->value.table, key);
    else
        *value = FUN_00db99b0(tbl->value.structure, key);
    if (!(value->type & 0xf))
        key->type = 0;
}
