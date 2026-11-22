/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* The script table library's "getn" (its table at 0x16bd0f0, name and
 * function in turn): the length of its table argument, 0 past the frame's
 * top. */
// NONMATCHING: hksi_hksL_checktable's type test: the base branches twice on (not 9 or 10) and 5, then
// (not 9 or 10) and 12 (`test dl, al; jne; and cl, al; jne`), the build joins 5 and 12 in one `or`
// and tests 9 or 10 after (InstCombine's distribution); one typeOf for both gives a `cmov` of 6
int FUN_00ddf4a0(lua_State *state) /* derived name */
{
    hksi_hksL_checktable(state, 1);
    const HksObject *table = state->base;
    pushInteger(state, table < state->top ? FUN_00d96ff0(state, table) : 0);
    return 1;
}
