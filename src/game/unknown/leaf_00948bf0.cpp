/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: a script C function: with at least one argument, stores the
 * number FUN_00db6f40 reads from the first (0 when the frame is empty) as the
 * float at 0x16dcd68 (written also by FUN_008e85f0 and FUN_0094d230, which
 * sets it to 1, and read by FUN_0094a290: the game's object, reached
 * directly), and returns 1 (the result slot is not written). */
extern float D_16dcd68;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */

int FUN_00948bf0(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        float value = 0.0f;
        if (state->base < state->top)
            value = FUN_00db6f40(state, state->base);
        D_16dcd68 = value;
    }
    return 1;
}
