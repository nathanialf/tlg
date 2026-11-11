/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "SoundStop" (FUN_00e7d5a0 registers it
 * through FUN_00dd6ba0, lea at 0xe7d65a): with at least one argument, passes
 * the number FUN_00db6f40 reads from the first, truncated to an int (0 when
 * the frame is empty), to FUN_00d63370 with the object at +0x100 of the object
 * the pointer at 0x5938c40 holds, and returns 0 (no results). The C function's
 * own name is unknown. */
struct Member05938c40_100; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x100];
    Member05938c40_100 *unknown100;
};

extern Object05938c40 *D_5938c40;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */
void FUN_00d63370(Member05938c40_100 *member, int value);     /* derived name */

int FUN_00e7ce80(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        int value = 0;
        if (state->base < state->top)
            value = FUN_00db6f40(state, state->base);
        FUN_00d63370(D_5938c40->unknown100, value);
    }
    return 0;
}
