/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Soldier_GetPlayerEscapeStatus"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x2232e6): when the
 * record at +0x18 of the record at +0x50 of the object the pointer at +0x900
 * of the record at +0x38 of the object the pointer at 0x57c9390 holds is set
 * and its int at +0x5ac is not 0, passes the state and its pointer at +0x4e0
 * to FUN_00c89360 (the callee's push), pushes whether that int is 1 as a
 * boolean and returns 2 (two results); else returns 0. The C function's own
 * name is unknown; the fields' meaning is not traced. */
struct Value057c9390_38_900_50_18_4e0; /* derived name */

struct Escape057c9390_38_900_50_18 { /* derived name */
    u8 unknown0[0x4e0];
    Value057c9390_38_900_50_18_4e0 *unknown4e0; /* +0x4e0 */
    u8 unknown4e8[0xc4];
    int unknown5ac; /* +0x5ac */
};

struct Member057c9390_38_900_50 { /* derived name */
    u8 unknown0[0x18];
    Escape057c9390_38_900_50_18 *unknown18; /* +0x18 */
};

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x50];
    Member057c9390_38_900_50 *unknown50; /* +0x50 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;

void FUN_00c89360(lua_State *state, Value057c9390_38_900_50_18_4e0 *value); /* derived name */

int FUN_00468e60(lua_State *state) /* derived name */
{
    Escape057c9390_38_900_50_18 *escape = D_57c9390->unknown38->unknown900->unknown50->unknown18;
    if (!escape)
        return 0;
    int status = escape->unknown5ac;
    if (!status)
        return 0;
    FUN_00c89360(state, escape->unknown4e0);
    pushBoolean(state, status == 1);
    return 2;
}
