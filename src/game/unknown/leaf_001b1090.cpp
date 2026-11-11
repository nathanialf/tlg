/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "SetMaxFps" (FUN_001bd010 registers it
 * through FUN_00c87e30, lea at 0x1db27d): with at least one argument, takes
 * the number FUN_00db6f40 reads from the first (0 when the frame is empty)
 * and stores its reciprocal, or 0 when it is not above 0 or absent, as the float at
 * +0x180 of the object the pointer at 0x57c9390 holds (the pointer read
 * before the argument); returns 0 (no results). The C function's own name
 * is unknown. */
struct Object057c9390 { /* derived name */
    u8 unknown0[0x180];
    float unknown180; /* +0x180: one over the rate given */
};

extern Object057c9390 *D_57c9390;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */

int FUN_001b1090(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        Object057c9390 *object = D_57c9390;
        float period = 0.0f;
        if (state->base < state->top) {
            float rate = FUN_00db6f40(state, state->base);
            if (rate > 0.0f)
                period = 1.0f / rate;
        }
        object->unknown180 = period;
    }
    return 0;
}
