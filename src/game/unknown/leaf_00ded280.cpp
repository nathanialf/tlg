/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"
#include "tlg_hks_string.h"

/* derived name: a thread's name, null when it has none (FUN_00d964f0, its
 * body not written) */
const char *FUN_00d964f0(lua_State *thread);

/* derived name: the coroutine library's "getname" (its entry in the table
 * at 0x16bc880): the name of the thread given, which is taken off the
 * stack, or of the calling one, pushed (nil when it has none) */
// NONMATCHING: hksi_lua_remove's assertion: the base computes the offset as `~(count - 1)` in 64 bits and keeps both
// compares (`test edx, edx; jns`, `cmp ecx, -offset; jl`); here the offset folds to -count and the second compare with it
int FUN_00ded280(lua_State *state)
{
    lua_State *thread = state;
    if (argumentCount(state) > 0) {
        if (!isThread(state, 1))
            FUN_00dd3450(state, 1, "coroutine expected");
        thread = toThread(state, 1);
        hksi_lua_remove(state, 1);
    }
    pushString(state, FUN_00d964f0(thread));
    return 1;
}
