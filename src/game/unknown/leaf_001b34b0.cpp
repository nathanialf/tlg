/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Trophy_SetupCondorTouched" (FUN_001bd010
 * registers it through FUN_00c87e30, lea at 0x1db61a): with at least one
 * argument, passes the number FUN_00db6f40 reads from the first, truncated to
 * an int (0 when the frame is empty), to FUN_00a1ca80 with the pointer at +0x30
 * of the record at +0x108 of the object the pointer at 0x57c9390 holds, and
 * returns 0 (no results). The count of arguments is top - base as an int. The C
 * function's own name is unknown. */
struct Record057c9390_108_30; /* derived name */

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x30];
    Record057c9390_108_30 *unknown30;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */
void FUN_00a1ca80(Record057c9390_108_30 *record, int value);  /* derived name */

int FUN_001b34b0(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        int value = 0;
        if (state->base < state->top)
            value = FUN_00db6f40(state, state->base);
        FUN_00a1ca80(D_57c9390->unknown108->unknown30, value);
    }
    return 0;
}
