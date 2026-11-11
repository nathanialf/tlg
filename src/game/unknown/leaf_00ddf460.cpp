/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script library "table"'s C function "create" (its entry
 * in the table at 0x16bd100 that FUN_00dc2db0 registers): reads the integers
 * of arguments 1 and 2 through FUN_00dbf960 and creates a table with them as
 * its array and hash sizes through FUN_00d91880 (lua_createtable's shape),
 * returning the one result. The callees' names are not verified. */
int FUN_00dbf960(lua_State *state, int index);                    /* derived name */
void FUN_00d91880(lua_State *state, int arraySize, int hashSize); /* derived name */

int FUN_00ddf460(lua_State *state) /* derived name */
{
    int arraySize = FUN_00dbf960(state, 1);
    int hashSize = FUN_00dbf960(state, 2);
    FUN_00d91880(state, arraySize, hashSize);
    return 1;
}
