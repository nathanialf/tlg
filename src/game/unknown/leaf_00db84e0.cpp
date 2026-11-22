/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: Lua's lua_settable by its operands: a table (5) without
 * the word at +0x10 and a structure (12) without the word at +0x20 store the
 * value raw, any other value through the metamethods; the call timed */
void FUN_00db84e0(lua_State *state, HksObject *table, HksObject *key, HksObject *value)
{
    HksApiTimer timer(state);
    const HksObject object = *table;
    const int type = object.type & 0xf;
    if (type == 5 && !object.value.table->metatable)
        FUN_00d9c0e0(object.value.table, state, key, value);
    else if (type == 12 && !object.value.structure->metatable)
        FUN_013be510(object.value.structure, state, key, value);
    else
        FUN_00dc8b40(state, object, key, value, 0);
}
