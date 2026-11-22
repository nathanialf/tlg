/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* hks_obj_rawget_array and hks_obj_rawset_array (the names from their
 * assertion messages, FUN_00db9130 and FUN_00db9340, their bodies not
 * written): a table's or a structure's value at an index, read and
 * written raw */
HksObject FUN_00db9130(lua_State *state, const HksObject *table, int index);
void FUN_00db9340(lua_State *state, const HksObject *table, int index, const HksObject *value);

/* derived name: a light userdata (2) stored raw at an index of a table */
inline void setLightUserdata(lua_State *s, const HksObject *table, int index, void *pointer)
{
    HksObject value;
    value.value.pointer = pointer;
    value.type = 2;
    FUN_00db9340(s, table, index, &value);
}

/* hksi_luaL_unref (the name from its assertion message): a reference
 * freed, its slot of the registry taking the free list's head (index 2, a
 * light userdata) and the head the reference less one; the call timed */
// NONMATCHING: register assignment and order only: the base keeps the mark in r13d and the second counter
// in r15 (0xd92273), the compile the other way round, and adds the registry's offset right before each
// store's call (0xd92349)
void FUN_00d92240(lua_State *s, int ref)
{
    if (!(s != 0)) {
        printf("Havok Script Assertion [r 14332] 0x%08X failed:\n\tAssertion (%s) failed\n\tin "
               "%s() : \"%s\"\n\tat %s(%d)\n",
               0xa1da72, "s != NULL", "hksi_luaL_unref",
               "Parameter 's' must be a valid state pointer", HKS_VM_AUX_FILE, 1103);
        __builtin_trap();
    }
    HksApiTimer timer(s);
    if (ref >= 0) {
        const HksObject head = FUN_00db9130(s, &s->global->registry, 2);
        setLightUserdata(s, &s->global->registry, ref,
                         (head.type & 0xf) == 2 ? head.value.pointer : 0);
        setLightUserdata(s, &s->global->registry, 2,
                         reinterpret_cast<void *>(static_cast<s64>(ref - 1)));
    }
}
