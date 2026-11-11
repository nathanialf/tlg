/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "GetNetworkIdleFrame" (FUN_001bd010, lea at 0x1db430):
 * pushes the number 1 and returns one result. The C function's own name is unknown. */
int FUN_001b2b00(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.number = 1.0f;
    top->type = 3;
    state->top = top + 1;
    return 1;
}
