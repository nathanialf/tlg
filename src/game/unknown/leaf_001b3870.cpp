/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Trophy_IsAchieveHungryEvent"
 * (FUN_001bd010, lea at 0x1db692): the first argument's number as an int,
 * less one, indexes the ints at +0x70 (count +0x78) of the record at +0x38
 * of the record at +0x108 of the object the pointer at 0x57c9390 holds;
 * pushes whether the int there is nonzero (false past the count) and returns
 * one result. */
struct Record057c9390_108_38 { /* derived name */
    u8 unknown0[0x70];
    int *unknown70;     /* +0x70 */
    unsigned unknown78; /* +0x78 */
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x38];
    Record057c9390_108_38 *unknown38; /* +0x38 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108; /* +0x108 */
};

extern Object057c9390 *D_57c9390;

int FUN_001b3870(lua_State *state) /* derived name */
{
    int index = (int)toNumber(state, 1) - 1;
    Record057c9390_108_38 *record = D_57c9390->unknown108->unknown38;
    pushBoolean(state, record->unknown78 > (unsigned)index && record->unknown70[index] != 0);
    return 1;
}
