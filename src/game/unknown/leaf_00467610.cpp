/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that, when the object the pointer at
 * +0x900 of the record at +0x38 of the object the pointer at 0x57c9390 holds
 * is not null, returns what FUN_004a8e50 gives for that object's pointer at
 * +0x68 and the state, a tail call, and else 0 (no results). FUN_002212a0
 * registers it through FUN_00c89b70 under the script name
 * "Soldier_SetupSoldierSetupParams"; the VM's strings name lua_State. The C
 * function's own name is unknown. */
struct lua_State;
struct Member057c9390_38_900_68; /* derived name */

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x68];
    Member057c9390_38_900_68 *unknown68;
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

int FUN_004a8e50(Member057c9390_38_900_68 *member, lua_State *state); /* derived name */

int FUN_00467610(lua_State *state) /* derived name */
{
    Member057c9390_38_900 *member = D_57c9390->unknown38->unknown900;
    if (!member)
        return 0;
    return FUN_004a8e50(member->unknown68, state);
}
