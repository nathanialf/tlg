/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "StopAllVibration" (FUN_00c83870
 * registers it, lea at 0xc84efb): with exactly one argument, passes the
 * pointer the number FUN_00db6f40 reads from it selects (truncated to an int,
 * 0 when the frame is empty) in the array at +0x98 of the object the pointer
 * at 0x5938c40 holds to FUN_00c66970, and returns 0 (no results). The C
 * function's own name is unknown; the pointers' type is not traced. */
struct Member05938c40_98; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x98];
    Member05938c40_98 *unknown98[1]; /* +0x98: indexed by the argument */
};

extern Object05938c40 *D_5938c40;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */
void FUN_00c66970(Member05938c40_98 *member);                 /* derived name */

// NONMATCHING: the count test: the base shifts the byte difference and compares 32 bits
// (`shr rcx, 4; cmp ecx, 1; jne`); InstCombine folds `(int)(top - base) == 1` here into
// a mask test of the difference (`movabs rdx, 0xffffffff0; and rdx, rcx; cmp rdx, 16`),
// as do the prebuilt 3.8.1 and 3.9.1: the source form of the count is not found.
int FUN_00c87540(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count == 1) {
        int index = 0;
        if (state->base < state->top)
            index = FUN_00db6f40(state, state->base);
        FUN_00c66970(D_5938c40->unknown98[index]);
    }
    return 0;
}
