/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the script C function "MSC_Demo_Stop" (FUN_001db8b0 registers
 * it through FUN_00c87e30, lea at 0x1de1cf, signature string
 * "MSC_Demo_Stop()"): passes the object the pointer at +0x70 of the object the
 * pointer at 0x57c9390 holds to FUN_007f1290, then sets bit 0 of that object's
 * int at +0x2e90 (the pointer reloaded after the call), and returns 0 (no
 * results). The C function's own name is unknown. */
struct lua_State;

struct Member057c9390_70 { /* derived name */
    u8 unknown0[0x2e90];
    unsigned unknown2e90;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x70];
    Member057c9390_70 *unknown70;
};

extern Object057c9390 *D_57c9390;

void FUN_007f1290(Member057c9390_70 *member); /* derived name */

int FUN_008d8e50(lua_State *) /* derived name */
{
    FUN_007f1290(D_57c9390->unknown70);
    D_57c9390->unknown70->unknown2e90 |= 1;
    return 0;
}
