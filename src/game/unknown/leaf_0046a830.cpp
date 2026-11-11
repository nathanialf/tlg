/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that passes the object the pointer at
 * +0x900 of the record at +0x38 of the object the pointer at 0x57c9390 holds
 * to FUN_0048bcd0 when it is not null and returns 0 (no results). FUN_002212a0
 * registers it through FUN_00c89b70 under the script name
 * "Soldier_DisconnectDropSoldierParts"; the VM's strings name lua_State. The C
 * function's own name is unknown. */
struct lua_State;
struct Member057c9390_38_900; /* derived name */

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38;
};

extern Object057c9390 *D_57c9390;

void FUN_0048bcd0(Member057c9390_38_900 *member); /* derived name */

int FUN_0046a830(lua_State *) /* derived name */
{
    Member057c9390_38_900 *member = D_57c9390->unknown38->unknown900;
    if (member)
        FUN_0048bcd0(member);
    return 0;
}
