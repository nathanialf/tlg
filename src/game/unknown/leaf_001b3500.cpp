/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Trophy_AchieveCondorTouched" (FUN_001bd010
 * registers it through FUN_00c87e30, lea at 0x1db632): with at least one
 * argument, takes the number FUN_00db6f40 reads from the first, truncated to
 * an int (0 when the frame is empty), and passes it less one to FUN_00a1cb50
 * with the member at +0x100 of the record at +0x30 of the record at +0x108
 * of the object the pointer at 0x57c9390 holds and the string "TROPHY_Touch_All_Gryphons";
 * returns 0 (no results). The C function's own name is unknown. */
struct Tracker057c9390_108_30_100 /* derived name */
{
    u8 unknown0[1]; /* its size is not traced */
};

struct Record057c9390_108_30 { /* derived name */
    u8 unknown0[0x100];
    Tracker057c9390_108_30_100 unknown100; /* +0x100 */
};

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
void FUN_00a1cb50(Tracker057c9390_108_30_100 *tracker, int value,
                  const char *name); /* derived name */

int FUN_001b3500(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        int value = 0;
        if (state->base < state->top)
            value = FUN_00db6f40(state, state->base);
        FUN_00a1cb50(&D_57c9390->unknown108->unknown30->unknown100, value - 1,
                     "TROPHY_Touch_All_Gryphons");
    }
    return 0;
}
