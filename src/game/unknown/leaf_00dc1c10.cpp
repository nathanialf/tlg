/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: opens the script library "profile": registers the 10 C functions
 * of its table (name and function pairs, a null entry last) under that name
 * through FUN_00ddc6b0, and returns one result; a C function itself, in the table of
 * library openers at 0x16bd1a0 (its pointer at 0x16bd2f8). The opener's own name is
 * unknown. */
int FUN_00de3a70(lua_State *state); /* derived name */
int FUN_00de43b0(lua_State *state); /* derived name */
int FUN_00de43c0(lua_State *state); /* derived name */
int FUN_00de43d0(lua_State *state); /* derived name */
int FUN_00de4790(lua_State *state); /* derived name */
int FUN_00de48b0(lua_State *state); /* derived name */
int FUN_00de4aa0(lua_State *state); /* derived name */
int FUN_00de4c30(lua_State *state); /* derived name */
int FUN_00de5050(lua_State *state); /* derived name */
int FUN_00de5260(lua_State *state); /* derived name */

static const HksLibraryEntry D_16bce20[11] = {
#include "gen/D_16bce20.inc"
};

void FUN_00ddc6b0(lua_State *state, const char *name, const HksLibraryEntry *entries,
                  int count); /* derived name */

int FUN_00dc1c10(lua_State *state) /* derived name */
{
    FUN_00ddc6b0(state, "profile", D_16bce20, 1);
    return 1;
}
