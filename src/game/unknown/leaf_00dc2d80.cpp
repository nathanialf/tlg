/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: opens the script library "struct": registers the 5 C functions
 * of its table (name and function pairs, a null entry last) under that name
 * through FUN_00ddc6b0, and returns one result; a C function itself, in the table of
 * library openers at 0x16bd1a0 (its pointer at 0x16bd2b8). The opener's own name is
 * unknown. */
int FUN_00ddff40(lua_State *state); /* derived name */
int FUN_00de02e0(lua_State *state); /* derived name */
int FUN_00de0410(lua_State *state); /* derived name */
int FUN_00de0a90(lua_State *state); /* derived name */
int FUN_00de0b40(lua_State *state); /* derived name */

static const HksLibraryEntry D_16bd0a0[6] = {
#include "gen/D_16bd0a0.inc"
};

void FUN_00ddc6b0(lua_State *state, const char *name, const HksLibraryEntry *entries,
                  int count); /* derived name */

int FUN_00dc2d80(lua_State *state) /* derived name */
{
    FUN_00ddc6b0(state, "struct", D_16bd0a0, 1);
    return 1;
}
