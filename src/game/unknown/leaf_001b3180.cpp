/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Trophy_SetupCondorEatenBarrels"
 * (FUN_001bd010 registers it through FUN_00c87e30, lea at 0x1db58a): with at
 * least one argument, the number FUN_00db6f40 reads from the first,
 * truncated to an int (0 when the frame is empty), is passed to FUN_00a1c8e0
 * with the record at +0x30 of the record at +0x108 of the object at
 * 0x57c9390, and again (the frame read anew) to FUN_00a18a70 with the
 * record at +0x38; returns 0 (no results). As FUN_001b37c0. The C
 * function's own name is unknown. */
struct Record057c9390_108_30; /* derived name */
struct Record057c9390_108_38; /* derived name */

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x30];
    Record057c9390_108_30 *unknown30;
    Record057c9390_108_38 *unknown38;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */
void FUN_00a1c8e0(Record057c9390_108_30 *record, int value);  /* derived name */
void FUN_00a18a70(Record057c9390_108_38 *record, int value);  /* derived name */

int FUN_001b3180(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        int value = 0;
        if (state->base < state->top)
            value = FUN_00db6f40(state, state->base);
        FUN_00a1c8e0(D_57c9390->unknown108->unknown30, value);
    }
    count = state->top - state->base;
    if (count > 0) {
        int value = 0;
        if (state->base < state->top)
            value = FUN_00db6f40(state, state->base);
        FUN_00a18a70(D_57c9390->unknown108->unknown38, value);
    }
    return 0;
}
