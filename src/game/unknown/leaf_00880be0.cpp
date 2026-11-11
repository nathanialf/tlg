/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that passes the pointer at +0xd0 of the
 * object the pointer at 0x57c9390 holds to FUN_00880c00 and returns 0 (no
 * results). FUN_008817d0 registers it (lea at 0x88180f) through FUN_00c87e30
 * under the script name "GameMenu_LoadResident"; the VM's strings name
 * lua_State. The C function's own name is unknown. */
struct lua_State;

struct Member057c9390_d0; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0xd0];
    Member057c9390_d0 *unknownd0;
};

extern Object057c9390 *D_57c9390;

void FUN_00880c00(Member057c9390_d0 *member); /* derived name */

int FUN_00880be0(lua_State *state) /* derived name */
{
    FUN_00880c00(D_57c9390->unknownd0);
    return 0;
}
