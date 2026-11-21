/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the record at +0x30 of the record at +0x108 of the object
 * at 0x57c9390: the stages stroked so far, a bit each, at +0xc8 */
struct Record057c9390_108_30 { /* derived name */
    u8 unknown0[0xc8];
    unsigned stages; /* +0xc8 */
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

struct Trophies05938c40; /* derived name: what the object at 0x5938c40 holds at +0xf68 */

struct Object05938c40 { /* derived name: the object, seen from here */
    u8 unknown0[0xf68];
    Trophies05938c40 *trophies; /* +0xf68 */
};

extern Object05938c40 *D_5938c40;

float FUN_00db6f40(lua_State *state, const HksObject *value);    /* derived name */
void FUN_00a1cd10(const char *name, int stage);                  /* derived name */
void FUN_00cb5f90(Trophies05938c40 *trophies, const char *name); /* derived name */

/* derived names: the script C function "Trophy_AchieveCondorStrokeStage"
 * (FUN_001bd010 registers it through FUN_00c87e30, lea at 0x1db602): with at
 * least one argument, the stage its number gives (truncated to an int, 0
 * when the frame is empty), when not yet stroked, is marked and handed to
 * FUN_00a1cd10 with "TROPHY_Pet_Trico_in_All_Stages", and the trophy is
 * given (FUN_00cb5f90) once the stages 2 to 17 are all marked; returns 0
 * (no results). The C function's own name is unknown. */
// NONMATCHING: 32/40, the same size: instruction order and assignment: the base loads the
// record (`mov rax, [rax+0x108]; mov rbx, [rax+0x30]`) before the bit (`mov eax, 1; shl eax,
// cl`) and tests the stages in edx; the build forms the bit first, in edx, and tests in eax
// (the test written `(stages >> value) & 1` gives the same)
int FUN_001b3410(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        int value = 0;
        if (state->base < state->top)
            value = FUN_00db6f40(state, state->base);
        Record057c9390_108_30 *record = D_57c9390->unknown108->unknown30;
        if (!(record->stages & (1 << value))) {
            record->stages |= 1 << value;
            FUN_00a1cd10("TROPHY_Pet_Trico_in_All_Stages", value);
            if (record->stages == 0x3fffc)
                FUN_00cb5f90(D_5938c40->trophies, "TROPHY_Pet_Trico_in_All_Stages");
        }
    }
    return 0;
}
