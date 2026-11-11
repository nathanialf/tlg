/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "CustomWaterTarget_HasDataWarning"
 * (FUN_008f61f0 registers it through FUN_00c87e30, lea at 0x9007de, signature
 * string "CustomWaterTarget_HasDataWarning(waterTarget)"): with at least one
 * argument (the stack top less the frame's base, in 16-byte values), pushes
 * false and returns one result, else returns 0. The C function's own name is
 * unknown. */
int FUN_008f38f0(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    if (static_cast<int>(top - state->base) <= 0)
        return 0;
    top->value.boolean = 0;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
