/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: a script C function that takes one value (luaL_checkany),
 * drops it and pushes whether its type is 5 or 12; one result */
// NONMATCHING: the base keeps the type test as branches storing 1 or 0 in two arms (the
// build makes `sete; sete; or`: FoldTwoEntryPHINode's class) and keeps the pop's store of
// the top before the pushed value's stores (the build drops it)
int FUN_00dedaf0(lua_State *state) /* derived name */
{
    luaL_checkany(state, 1);
    int type = typeOf(state, 1);
    --state->top;
    pushBoolean(state, type == 5 || type == 12);
    return 1;
}
