/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "PhysicsCondorStateGetNumSpearInfo"
 * ("get num spearinfo", registered through FUN_00c87e30 at 0x1d3125): pushes
 * the int at +0x158 of the record at +0x68 of the record at +0x38 of the
 * record at +0x108 of the object at 0x57c9390 as a number, and returns 1.
 * The records' types are not traced. */
struct Member057c9390_108_38_68 { /* derived name */
    u8 unknown0[0x158];
    int unknown158; /* +0x158: the count */
};

struct Member057c9390_108_38 { /* derived name */
    u8 unknown0[0x68];
    Member057c9390_108_38_68 *unknown68; /* +0x68 */
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_108_38 *unknown38; /* +0x38 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108; /* +0x108 */
};

extern Object057c9390 *D_57c9390;

int FUN_00a15c40(lua_State *state) /* derived name */
{
    pushInteger(state, D_57c9390->unknown108->unknown38->unknown68->unknown158);
    return 1;
}
