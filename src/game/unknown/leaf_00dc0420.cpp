/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "stdlib.h"

struct lua_State;

/* derived names: the script C function "exit" of the "os" library (the table
 * at 0x16bcd00): exits the program with the status FUN_00dc0440 reads from
 * argument 1, 1 when absent. The C function's own name is unknown. */
int FUN_00dc0440(lua_State *state, int index, int fallback); /* derived name */

int FUN_00dc0420(lua_State *state) /* derived name */
{
    exit(FUN_00dc0440(state, 1, 1));
}
