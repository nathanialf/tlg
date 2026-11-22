/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: names a thread (FUN_00dd0320, its body not written) */
void FUN_00dd0320(lua_State *thread, const char *name);

/* derived name: the coroutine library's "setname" (its entry in the table
 * at 0x16bc890): the thread given first, which is taken off the stack, or
 * the calling one, named by the string on the stack's top; no results */
// NONMATCHING: hksi_lua_remove's assertion: the base computes the offset as `~(count - 1)` in 64 bits and keeps both
// compares (`test edx, edx; jns`, `cmp ecx, -offset; jl`); here the offset folds to -count and the second compare with it
int FUN_00ded3d0(lua_State *state)
{
    lua_State *thread = state;
    if (isThread(state, 1)) {
        thread = toThread(state, 1);
        hksi_lua_remove(state, 1);
    }
    const HksObject *value = state->top - 1;
    const char *name = value >= state->base ? FUN_00db6b20(state, value, 0) : 0;
    if (!name)
        FUN_00dd38c0(state, -1, "string");
    FUN_00dd0320(thread, name);
    return 0;
}
