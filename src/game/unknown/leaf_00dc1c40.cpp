/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: opens the script library "serialize": registers the 2 C functions
 * of its table (name and function pairs, a null entry last) under that name
 * through FUN_00ddc6b0, and returns one result; a C function itself, in the table of
 * library openers at 0x16bd1a0 (its pointer at 0x16bd2e8). The opener's own name is
 * unknown. */
int FUN_00de3030(lua_State *state); /* derived name */
int FUN_00de32b0(lua_State *state); /* derived name */

static const HksLibraryEntry D_16bced0[3] = {
#include "gen/D_16bced0.inc"
};

void FUN_00ddc6b0(lua_State *state, const char *name, const HksLibraryEntry *entries,
                  int count); /* derived name */

int FUN_00dc1c40(lua_State *state) /* derived name */
{
    FUN_00ddc6b0(state, "serialize", D_16bced0, 1);
    return 1;
}
