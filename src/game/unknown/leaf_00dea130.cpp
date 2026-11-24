/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"

/* derived names: the weights' names, a null last (the table setgcweights
 * checks its option against, FUN_00de9ef0), and each weight's offset in
 * HksGlobal::HksGcWeights, in the same order */
extern const char *const D_16bba30[13];
extern const size_t D_151f030[12];

/* The script library "havokscript"'s C function "getgcweights" (its entry in
 * the table at 0x16bc9b0, leaf_00dbeb20.cpp): a table of the collector's
 * twelve weights by name, each a number, returned as the one result. The
 * weights are copied out of the global state first. derived name. */
int FUN_00dea130(lua_State *state)
{
    FUN_00d91880(state, 0, 12);
    const HksGlobal::HksGcWeights weights = state->global->gcWeights;
    for (int i = 0; i < 12; ++i) {
        const char *name = D_16bba30[i];
        FUN_013aacc0(state, name, strlen(name));
        pushInteger(state, *reinterpret_cast<const int *>(reinterpret_cast<const char *>(&weights) +
                                                          D_151f030[i]));
        setTable(state);
    }
    return 1;
}
