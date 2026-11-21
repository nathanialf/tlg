/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Trophy_AchieveCondorEatenBarrels"
 * (FUN_001bd010 registers it through FUN_00c87e30, lea at 0x1db5a2): with at
 * least one argument, the number FUN_00db6f40 reads from the first,
 * truncated to an int (0 when the frame is empty), less one, is passed to
 * FUN_00a1cb50 with the tracker at +0xe8 of the record at +0x30 of the
 * record at +0x108 of the object at 0x57c9390 and "TROPHY_All_Barrels_Eaten",
 * and again (the frame read anew) to FUN_00a190f0 with the barrels at +0x88
 * of the record at +0x38 and the empty string; returns 0 (no results). As
 * FUN_001b3120. The C function's own name is unknown. */
struct Tracker057c9390_108_30_e8 /* derived name */
{
    u8 unknown0[1]; /* its size is not traced */
};

struct Barrels057c9390_108_38_88 /* derived name */
{
    u8 unknown0[1]; /* its size is not traced */
};

struct Record057c9390_108_30 { /* derived name */
    u8 unknown0[0xe8];
    Tracker057c9390_108_30_e8 unknowne8; /* +0xe8 */
};

struct Record057c9390_108_38 { /* derived name */
    u8 unknown0[0x88];
    Barrels057c9390_108_38_88 barrels; /* +0x88 */
};

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
void FUN_00a1cb50(Tracker057c9390_108_30_e8 *tracker, int value,
                  const char *name); /* derived name */
void FUN_00a190f0(Barrels057c9390_108_38_88 *barrels, int value,
                  const char *name); /* derived name */

int FUN_001b3220(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        int value = 0;
        if (state->base < state->top)
            value = FUN_00db6f40(state, state->base);
        FUN_00a1cb50(&D_57c9390->unknown108->unknown30->unknowne8, value - 1,
                     "TROPHY_All_Barrels_Eaten");
    }
    count = state->top - state->base;
    if (count > 0) {
        int value = 0;
        if (state->base < state->top)
            value = FUN_00db6f40(state, state->base);
        FUN_00a190f0(&D_57c9390->unknown108->unknown38->barrels, value - 1, "");
    }
    return 0;
}
