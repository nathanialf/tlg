/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the barrels the record at +0x38 of the record at +0x108 of
 * the object at 0x57c9390 keeps at +0x88: a flag per barrel and their count */
struct Barrels057c9390_108_38_88 { /* derived name */
    int *eaten;                    /* +0x0 */
    unsigned count;                /* +0x8 */
};

struct Record057c9390_108_38 { /* derived name */
    u8 unknown0[0x88];
    Barrels057c9390_108_38_88 barrels; /* +0x88 */
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

/* derived names: the script C function "Trophy_IsAchieveCondorEatenBarrels"
 * (FUN_001bd010 registers it through FUN_00c87e30, lea at 0x1db5ba): pushes
 * whether the barrel the first argument numbers (from 1; truncated to an
 * int) is eaten, false past the barrels' count or with no argument; returns
 * 1 (one result). The C function's own name is unknown. */
int FUN_001b32e0(lua_State *state) /* derived name */
{
    const int index = (int)toNumber(state, 1) - 1;
    const Barrels057c9390_108_38_88 &barrels = D_57c9390->unknown108->unknown38->barrels;
    pushBoolean(state, barrels.count > (unsigned)index && barrels.eaten[index] != 0);
    return 1;
}
