/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "UnlockTrophy" (FUN_001bd010 registers
 * it through FUN_00c87e30, lea at 0x1db6aa): with at least one argument,
 * passes the value FUN_00db6b20 reads from the first (third argument 0; a null
 * pointer when the frame is empty) to FUN_00cb5f90 with the pointer at +0xf68
 * of the object the pointer at 0x5938c40 holds, and returns 0 (no results).
 * FUN_00db6b20 is taken to read the value as a string. The C function's own
 * name is unknown. */
struct Member05938c40_f68; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf68];
    Member05938c40_f68 *unknownf68;
};

extern Object05938c40 *D_5938c40;

const char *FUN_00db6b20(lua_State *state, const HksObject *value, int); /* derived name */
void FUN_00cb5f90(Member05938c40_f68 *member, const char *name);         /* derived name */

int FUN_001b38f0(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        const char *name = 0;
        if (state->base < state->top)
            name = FUN_00db6b20(state, state->base, 0);
        FUN_00cb5f90(D_5938c40->unknownf68, name);
    }
    return 0;
}
