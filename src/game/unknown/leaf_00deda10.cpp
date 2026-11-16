/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the step of a table's traversal after the key on the stack
 * (FUN_00dbc000, its body not written) */
void FUN_00dbc000(lua_State *state);

/* The script base library's "next" (its table at 0x16bc670, name and
 * function in turn): the key and the value after the key it is given in its
 * table argument; two results. */
// NONMATCHING: hksi_hksL_checktable's type test: the base branches twice on (not 9 or 10) and 5, then
// (not 9 or 10) and 12 (`test dl, al; jne; and cl, al; jne`), the build joins 5 and 12 in one `or`
// and tests 9 or 10 after (InstCombine's distribution); one typeOf for both gives a `cmov` of 6
int FUN_00deda10(lua_State *state) /* derived name */
{
    hksi_hksL_checktable(state, 1);
    FUN_00dbc000(state);
    return 2;
}
