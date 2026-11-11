/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: opens the script library "table": registers the 9 C functions
 * of its table (name and function pairs, a null entry last) under that name
 * through FUN_00ddc6b0, and returns one result; a C function itself, in the table of
 * library openers at 0x16bd1a0 (its pointer at 0x16bd2a8). The opener's own name is
 * unknown. */
int FUN_00dde760(lua_State *state); /* derived name */
int FUN_00dde930(lua_State *state); /* derived name */
int FUN_00ddeaf0(lua_State *state); /* derived name */
int FUN_00ddedd0(lua_State *state); /* derived name */
int FUN_00ddef70(lua_State *state); /* derived name */
int FUN_00ddf100(lua_State *state); /* derived name */
int FUN_00ddf300(lua_State *state); /* derived name */
int FUN_00ddf460(lua_State *state); /* derived name */
int FUN_00ddf4a0(lua_State *state); /* derived name */

static const HksLibraryEntry D_16bd100[10] = {
#include "gen/D_16bd100.inc"
};

void FUN_00ddc6b0(lua_State *state, const char *name, const HksLibraryEntry *entries,
                  int count); /* derived name */

int FUN_00dc2db0(lua_State *state) /* derived name */
{
    FUN_00ddc6b0(state, "table", D_16bd100, 1);
    return 1;
}
