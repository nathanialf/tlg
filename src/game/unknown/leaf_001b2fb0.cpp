/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "LoadOldData" (FUN_001bd010, lea at
 * 0x1db4fa): passes the state and what FUN_00a267c0 returns for the pointer at
 * +0x108 of the object the pointer at 0x57c9390 holds to FUN_00c89360, and
 * returns one result. The pointers' types and the callees' return types are not
 * traced. */
struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    void *unknown108;
};

extern Object057c9390 *D_57c9390;

void *FUN_00a267c0(void *record);                 /* derived name */
void FUN_00c89360(lua_State *state, void *value); /* derived name */

int FUN_001b2fb0(lua_State *state) /* derived name */
{
    FUN_00c89360(state, FUN_00a267c0(D_57c9390->unknown108));
    return 1;
}
