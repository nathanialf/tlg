/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "PhysicsGetNumAttachedProjectile"
 * (FUN_001bd010 registers it through FUN_00c87e30, lea at 0x1d2f90): pushes
 * the int FUN_009fa6c0 returns for the pointer at +0x18 of the record at +0x58
 * of the object the pointer at 0x57c9390 holds, as a number (tag 3), and
 * returns 1 (one result). The C function's own name is unknown. */
struct Record057c9390_58_18; /* derived name */

struct Member057c9390_58 { /* derived name */
    u8 unknown0[0x18];
    Record057c9390_58_18 *unknown18;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x58];
    Member057c9390_58 *unknown58;
};

extern Object057c9390 *D_57c9390;

int FUN_009fa6c0(Record057c9390_58_18 *record); /* derived name */

int FUN_00a14710(lua_State *state) /* derived name */
{
    int count = FUN_009fa6c0(D_57c9390->unknown58->unknown18);
    HksObject *top = state->top;
    top->value.number = count;
    top->type = 3;
    state->top = top + 1;
    return 1;
}
