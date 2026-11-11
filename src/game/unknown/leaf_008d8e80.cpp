/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that clears bit 0 of the 32-bit word at
 * +0x2e90 of the record at +0x70 of the object the pointer at 0x57c9390 holds
 * and returns 0 (no results). FUN_001db8b0 registers it (lea at 0x1de1f4)
 * through FUN_00c87e30 under the script name "MSC_Demo_Start" (its description
 * "MSC_Demo_Start()"); the VM's strings name lua_State. The C function's own
 * name is unknown. */
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

int FUN_008d8e80(lua_State *state) /* derived name */
{
    D_57c9390->unknown70->unknown2e90 &= ~1u;
    return 0;
}
