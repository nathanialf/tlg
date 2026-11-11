/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that increments the int at +0x54 of the
 * record at +0x38 of the record at +0x108 of the object the pointer at
 * 0x57c9390 holds and returns 0 (no results). FUN_002212a0 registers it (lea
 * at 0x2235a6) through FUN_00c89b70 under the script name
 * "Soldier_TROPHY_IncCount_SoldierKill"; the VM's strings name lua_State. The
 * C function's own name is unknown. */
struct lua_State;

struct Member057c9390_108_38 { /* derived name */
    u8 unknown0[0x54];
    int unknown54;
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_108_38 *unknown38;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

int FUN_0046ffe0(lua_State *state) /* derived name */
{
    ++D_57c9390->unknown108->unknown38->unknown54;
    return 0;
}
