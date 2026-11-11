/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Trophy_AchieveHungryEvent" (FUN_001bd010
 * registers it through FUN_00c87e30, lea at 0x1db67a): with at least one
 * argument, takes the number FUN_00db6f40 reads from the first, truncated to
 * an int (0 when the frame is empty), and passes it less one to FUN_00a190f0
 * with the member at +0x70 of the record at +0x38 of the record at +0x108
 * of the object the pointer at 0x57c9390 holds and the string "HungryEvent";
 * returns 0 (no results). The C function's own name is unknown. */
struct Tracker057c9390_108_38_70 /* derived name */
{
    u8 unknown0[1]; /* its size is not traced */
};

struct Record057c9390_108_38 { /* derived name */
    u8 unknown0[0x70];
    Tracker057c9390_108_38_70 unknown70; /* +0x70 */
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x38];
    Record057c9390_108_38 *unknown38;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */
void FUN_00a190f0(Tracker057c9390_108_38_70 *tracker, int value,
                  const char *name); /* derived name */

int FUN_001b3810(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        int value = 0;
        if (state->base < state->top)
            value = FUN_00db6f40(state, state->base);
        FUN_00a190f0(&D_57c9390->unknown108->unknown38->unknown70, value - 1, "HungryEvent");
    }
    return 0;
}
