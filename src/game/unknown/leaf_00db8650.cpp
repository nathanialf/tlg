/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hks_obj_rawget (the name from its assertion message): the value of a
 * table or a structure under a key, without metamethods, written to the
 * value given; the call timed */
// NONMATCHING: the base keeps the table arm's call apart from the structure's table call (the build
// tail-merges the two `mov rsi, r8; call FUN_00d9bf30`) and sets the nil words type first
void FUN_00db8650(lua_State *s, const HksObject *tbl, const HksObject *key, HksObject *value)
{
    HksApiTimer timer(s);
    if (!((tbl->type & 0xf) == 5 || (tbl->type & 0xf) == 12)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xdbb0aa29, "HKS_GET_TYPE(*tbl) == TTABLE || (HKS_GET_TYPE(*tbl) == TSTRUCT)",
               "hks_obj_rawget", "index does not point to a struct/table", HKS_OBJECT_FILE, 303);
        __builtin_trap();
    }
    if ((tbl->type & 0xf) == 5)
        *value = FUN_00d9bf30(tbl->value.table, key);
    else
        *value = structureGet(tbl->value.structure, key);
}
