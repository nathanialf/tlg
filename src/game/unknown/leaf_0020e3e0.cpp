/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that sets the byte at +0x101 of the
 * record at +0x128 of the object the pointer at 0x57c9390 holds to 1 and
 * returns 0 (no results). FUN_001db8b0 registers it (lea at 0x1dd42d) through
 * FUN_00c87e30 under the script name "Overlay_NotifyEnd"; the VM's strings
 * name lua_State. The C function's own name is unknown. */
struct lua_State;

struct Member057c9390_128 { /* derived name */
    u8 unknown0[0x101];
    u8 unknown101;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x128];
    Member057c9390_128 *unknown128;
};

extern Object057c9390 *D_57c9390;

int FUN_0020e3e0(lua_State *state) /* derived name */
{
    D_57c9390->unknown128->unknown101 = 1;
    return 0;
}
