/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: a string made in the VM's table of strings (FUN_00dd06f0,
 * its body not written) */
void *FUN_00dd06f0(void *strings, lua_State *state, int unknown, const char *text, size_t length,
                   u32 hash);

/* derived name: a string of a text of known length and hash, the global's
 * count at +0x500 counted up first; the call timed */
void *FUN_00db9de0(lua_State *state, const char *text, size_t length, u32 hash)
{
    HksApiTimer timer(state);
    ++state->global->unknown500;
    return FUN_00dd06f0(state->global->strings, state, 0, text, length, hash);
}
