/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that passes the object the pointer at
 * 0x5828450 holds to FUN_00b73640 and returns 0 (no results). FUN_00a64050
 * registers it (lea at 0xa642d2) through FUN_00c87e30 under the script name
 * "Subtitle_End" (its description "Subtitle_End()"); the VM's strings name
 * lua_State. The C function's own name is unknown. */
struct lua_State;

struct Object05828450; /* derived name */

extern Object05828450 *D_5828450;

void FUN_00b73640(Object05828450 *object); /* derived name */

int FUN_00a645a0(lua_State *state) /* derived name */
{
    FUN_00b73640(D_5828450);
    return 0;
}
