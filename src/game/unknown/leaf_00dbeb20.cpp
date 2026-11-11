/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: opens the script library "havokscript": registers the 3 C functions
 * of its table (name and function pairs, a null entry last) under that name
 * through FUN_00ddc6b0, and returns one result; a C function itself, in the table of
 * library openers at 0x16bd1a0 (its pointer at 0x16bd318). The opener's own name is
 * unknown. */
int FUN_00de9e70(lua_State *state); /* derived name */
int FUN_00de9ef0(lua_State *state); /* derived name */
int FUN_00dea130(lua_State *state); /* derived name */

static const HksLibraryEntry D_16bc9b0[4] = {
#include "gen/D_16bc9b0.inc"
};

void FUN_00ddc6b0(lua_State *state, const char *name, const HksLibraryEntry *entries,
                  int count); /* derived name */

int FUN_00dbeb20(lua_State *state) /* derived name */
{
    FUN_00ddc6b0(state, "havokscript", D_16bc9b0, 1);
    return 1;
}
