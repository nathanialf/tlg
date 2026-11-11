/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

struct lua_State;

/* derived names: the script C function "input" of the table at 0x16bca90 (its
 * pointer at 0x16bcae8): passes 1 and the mode "r" to FUN_00de89f0 and returns one
 * result. The C function's own name is unknown. */
int FUN_00de89f0(lua_State *state, int which, const char *mode); /* derived name */

int FUN_00de8550(lua_State *state) /* derived name */
{
    FUN_00de89f0(state, 1, "r");
    return 1;
}
