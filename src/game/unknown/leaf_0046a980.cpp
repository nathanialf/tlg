/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Soldier_SetHitVolumeDrawFlag"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x2231b2): reads
 * the numbers of its first two arguments where they are given (FUN_00db6f40,
 * the values unused) and sets the byte at +0x1f4 of the record at +0x900 of
 * the record at +0x38 of the object the pointer at 0x57c9390 holds; returns
 * 0 (no results). The C function's own name is unknown. */
struct Record057c9390_38_900 { /* derived name */
    u8 unknown0[0x1f4];
    bool unknown1f4; /* +0x1f4 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Record057c9390_38_900 *unknown900;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38;
};

extern Object057c9390 *D_57c9390;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */

int FUN_0046a980(lua_State *state) /* derived name */
{
    if (state->base < state->top)
        FUN_00db6f40(state, state->base);
    if (state->base + 1 < state->top)
        FUN_00db6f40(state, state->base + 1);
    D_57c9390->unknown38->unknown900->unknown1f4 = true;
    return 0;
}
