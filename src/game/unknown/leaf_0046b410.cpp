/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that passes the state and the pointer at
 * +0xa8 of the record at +0x88 of the object the pointer at +0x900 of the
 * record at +0x38 of the object the pointer at 0x57c9390 holds to FUN_00c89360
 * and returns 1 (one result, the callee's push). FUN_002212a0 registers it
 * through FUN_00c89b70 under the script name "Soldier_GetSpellBulletConfig";
 * the VM's strings name lua_State. The C function's own name is unknown; the
 * callee's return type is not traced. */
struct lua_State;
struct Member057c9390_38_900_88_a8; /* derived name */

struct Member057c9390_38_900_88 { /* derived name */
    u8 unknown0[0xa8];
    Member057c9390_38_900_88_a8 *unknowna8;
};

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x88];
    Member057c9390_38_900_88 *unknown88;
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

void FUN_00c89360(lua_State *state, Member057c9390_38_900_88_a8 *value); /* derived name */

int FUN_0046b410(lua_State *state) /* derived name */
{
    FUN_00c89360(state, D_57c9390->unknown38->unknown900->unknown88->unknowna8);
    return 1;
}
