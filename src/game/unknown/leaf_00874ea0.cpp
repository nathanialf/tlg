/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "IsGuideSysMultiThread" (FUN_00874ec0, lea at 0x874ffa):
 * pushes true and returns one result. The C function's own name is unknown. */
int FUN_00874ea0(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.boolean = 1;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
