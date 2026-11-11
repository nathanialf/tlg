/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that passes the object the pointer at
 * 0x581f4b8 holds to FUN_008db510 and returns 0 (no results). FUN_001db8b0
 * registers it (lea at 0x1ddf10) through FUN_00c87e30 under the script name
 * "ResetCheckList" (its description "ResetCheckList()"); the VM's strings name
 * lua_State. The C function's own name is unknown. */
struct lua_State;

struct Object0581f4b8; /* derived name */

extern Object0581f4b8 *D_581f4b8;

void FUN_008db510(Object0581f4b8 *object); /* derived name */

int FUN_008d5e20(lua_State *state) /* derived name */
{
    FUN_008db510(D_581f4b8);
    return 0;
}
