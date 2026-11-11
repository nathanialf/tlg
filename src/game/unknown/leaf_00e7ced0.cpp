/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "SoundSetMasterVolume" (FUN_00e7d5a0
 * registers it through FUN_00dd6ba0, lea at 0xe7d6e9): with at least one
 * argument, stores the number FUN_00db6f40 reads from the first (0 when the
 * frame is empty) as the float at +0x12c of the object at +0x100 of the object
 * the pointer at 0x5938c40 holds, and returns 0 (no results). The C
 * function's own name is unknown. */
struct Member05938c40_100 { /* derived name */
    u8 unknown0[0x12c];
    float unknown12c; /* +0x12c: the master volume */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x100];
    Member05938c40_100 *unknown100;
};

extern Object05938c40 *D_5938c40;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */

int FUN_00e7ced0(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        float volume = 0.0f;
        if (state->base < state->top)
            volume = FUN_00db6f40(state, state->base);
        D_5938c40->unknown100->unknown12c = volume;
    }
    return 0;
}
