/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "TricoGame_IsBuildWindows" (FUN_001bd010, lea at 0x1db260):
 * pushes false and returns one result. The C function's own name is unknown. */
int FUN_001b1070(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.boolean = 0;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
