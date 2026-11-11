/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Subtitle_SetParam" (FUN_00a64050
 * registers it through FUN_00c87e30, lea at 0xa6430c; its description
 * "Subtitle_SetParam()"): the numbers FUN_00db6f40 reads from its first two
 * arguments (0 for an argument the frame does not hold) become the pair of
 * floats at +0x70 of the object the pointer at 0x5828450 holds, stored as
 * one pair; returns 0 (no results). The C function's own name and the pair's
 * meaning are unknown. */
struct Pair05828450 { /* derived name */
    float first;
    float second;
};

struct Object05828450 { /* derived name */
    u8 unknown0[0x70];
    Pair05828450 parameters; /* +0x70 */
};

extern Object05828450 *D_5828450;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */

// NONMATCHING: the base holds the two results across the second call as integers in callee-saved
// registers (`vmovd r15d, xmm0`, `xor r15d, r15d` for the empty frame, two 32-bit stores), the build
// as floats (a spill slot and `vmovss` stores): the pair's type at the store is not found (a zero
// aggregate initializer gives the same floats)
int FUN_00a64680(lua_State *state) /* derived name */
{
    Pair05828450 parameters = {0.0f, 0.0f};
    if (state->base < state->top)
        parameters.first = FUN_00db6f40(state, state->base);
    if (state->base + 1 < state->top)
        parameters.second = FUN_00db6f40(state, state->base + 1);
    D_5828450->parameters = parameters;
    return 0;
}
