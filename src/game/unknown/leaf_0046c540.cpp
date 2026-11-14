/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "SoldierMission_IsPIBarGateEventOK"
 * (FUN_002212a0, lea at 0x223396): pushes the bool at +0x1e5 of the record at
 * +0x900 of the record at +0x38 of the object the pointer at 0x57c9390 holds
 * and returns one result. */
struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x1e5];
    bool unknown1e5;
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38;
};

extern Object057c9390 *D_57c9390;

int FUN_0046c540(lua_State *state) /* derived name */
{
    pushBoolean(state, D_57c9390->unknown38->unknown900->unknown1e5);
    return 1;
}
