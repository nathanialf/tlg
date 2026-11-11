/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the script C function "LoadProgress" (FUN_001bd010 registers
 * it through FUN_00c87e30, lea at 0x1db4ca): passes the object the pointer at
 * +0x108 of the object the pointer at 0x57c9390 holds to FUN_00a26970, then
 * sets that object's int at +0x5c to 1 (the pointer reloaded after the call),
 * and returns 0 (no results). The C function's own name is unknown; the
 * callee's return type is not traced. */
struct lua_State;

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x5c];
    int unknown5c;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

void FUN_00a26970(Member057c9390_108 *member); /* derived name */

int FUN_001b2ef0(lua_State *) /* derived name */
{
    FUN_00a26970(D_57c9390->unknown108);
    D_57c9390->unknown108->unknown5c = 1;
    return 0;
}
