/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that sets the bool at 0x1e4 of the object
 * the pointer at +0x900 of the record at +0x38 of the object the pointer at
 * 0x57c9390 holds, when that pointer is not null, and returns 0 (no results).
 * FUN_002212a0 registers it through FUN_00c89b70 under the script name
 * "Soldier_SpearTargetOff"; the VM's strings name lua_State. The C function's
 * own name is unknown. */
struct lua_State;

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x1e4];
    bool unknown1e4;
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

int FUN_0046e570(lua_State *) /* derived name */
{
    Member057c9390_38_900 *member = D_57c9390->unknown38->unknown900;
    if (member)
        member->unknown1e4 = true;
    return 0;
}
