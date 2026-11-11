/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script function registered by FUN_00a27090 under the
 * script name "Treasure_Lua_DbgReset" with no usage string as a Havok Script
 * C function (the VM's strings name lua_State): resets the four 24-byte
 * records from +0x38 of the object at +0x30 of the record at +0x108 of the
 * object the pointer at 0x57c9390 holds, each through FUN_01344d90 with 0,
 * and returns 0 (no results). The records, FUN_01344d90's second parameter
 * and its return type are not traced. The C function's own name is
 * unknown. */
struct lua_State;

struct Record01344d90 { /* derived name */
    u8 unknown0[0x18];
};

struct Object00a27850 { /* derived name */
    u8 unknown0[0x38];
    Record01344d90 unknown38[4]; /* +0x38 */
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x30];
    Object00a27850 *unknown30; /* +0x30 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108; /* +0x108 */
};

extern Object057c9390 *D_57c9390;

void FUN_01344d90(Record01344d90 *record, int value); /* derived name */

int FUN_00a27850(lua_State *) /* derived name */
{
    Object00a27850 *object = D_57c9390->unknown108->unknown30;
    for (int i = 0; i < 4; i++)
        FUN_01344d90(&object->unknown38[i], 0);
    return 0;
}
