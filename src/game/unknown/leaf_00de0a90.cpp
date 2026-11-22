/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the structure library's "name" (its entry in the table at
 * 0x16bd0d0): the first argument, a struct, replaced by its type's name */
int FUN_00de0a90(lua_State *state)
{
    hksi_luaL_checktype(state, 1, 12, "struct");
    HksObject *value = state->base;
    value->value.pointer = static_cast<HksStruct *>(value->value.pointer)->type->name;
    state->base->type = 4;
    return 1;
}
