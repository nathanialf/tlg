/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: opens the script library "debug": registers the 15 C functions
 * of its table (name and function pairs, a null entry last) under that name
 * through FUN_00ddc6b0, and returns one result; a C function itself, in the table of
 * library openers at 0x16bd1a0 (its pointer at 0x16bd2d8). The opener's own name is
 * unknown. */
int FUN_00dea220(lua_State *state); /* derived name */
int FUN_00dea270(lua_State *state); /* derived name */
int FUN_00deae90(lua_State *state); /* derived name */
int FUN_00deb200(lua_State *state); /* derived name */
int FUN_00deb2b0(lua_State *state); /* derived name */
int FUN_00deb320(lua_State *state); /* derived name */
int FUN_00deb490(lua_State *state); /* derived name */
int FUN_00deb520(lua_State *state); /* derived name */
int FUN_00deb840(lua_State *state); /* derived name */
int FUN_00deb930(lua_State *state); /* derived name */
int FUN_00deba50(lua_State *state); /* derived name */
int FUN_00debba0(lua_State *state); /* derived name */
int FUN_00debd80(lua_State *state); /* derived name */
int FUN_00debd90(lua_State *state); /* derived name */
int FUN_00debe70(lua_State *state); /* derived name */

static const HksLibraryEntry D_16bc8b0[16] = {
#include "gen/D_16bc8b0.inc"
};

void FUN_00ddc6b0(lua_State *state, const char *name, const HksLibraryEntry *entries,
                  int count); /* derived name */

int FUN_00dbeaf0(lua_State *state) /* derived name */
{
    FUN_00ddc6b0(state, "debug", D_16bc8b0, 1);
    return 1;
}
