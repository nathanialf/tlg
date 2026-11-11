/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: opens the script library "os": registers the 11 C functions
 * of its table (name and function pairs, a null entry last) under that name
 * through FUN_00ddc6b0, and returns one result; a C function itself, in the table of
 * library openers at 0x16bd1a0 (its pointer at 0x16bd308). The opener's own name is
 * unknown. */
int FUN_00dc03d0(lua_State *state); /* derived name */
int FUN_00dc0420(lua_State *state); /* derived name */
int FUN_00dc06b0(lua_State *state); /* derived name */
int FUN_00dc08a0(lua_State *state); /* derived name */
int FUN_00dc0b30(lua_State *state); /* derived name */
int FUN_00de65e0(lua_State *state); /* derived name */
int FUN_00de67e0(lua_State *state); /* derived name */
int FUN_00de6860(lua_State *state); /* derived name */
int FUN_00de6990(lua_State *state); /* derived name */
int FUN_00de69d0(lua_State *state); /* derived name */
int FUN_00de69f0(lua_State *state); /* derived name */

static const HksLibraryEntry D_16bcd00[12] = {
#include "gen/D_16bcd00.inc"
};

void FUN_00ddc6b0(lua_State *state, const char *name, const HksLibraryEntry *entries,
                  int count); /* derived name */

int FUN_00dc1200(lua_State *state) /* derived name */
{
    FUN_00ddc6b0(state, "os", D_16bcd00, 1);
    return 1;
}
