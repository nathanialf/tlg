/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that passes the object the pointer at
 * 0x5827ee0 holds to FUN_00b61cc0 and returns 0 (no results). FUN_00a5d530
 * registers it (lea at 0xa5e119) through FUN_00c87e30 under the script name
 * "Spell_End" (its description "Spell_End()"); the VM's strings name
 * lua_State. The C function's own name is unknown. */
struct lua_State;

struct Object05827ee0; /* derived name */

extern Object05827ee0 *D_5827ee0;

void FUN_00b61cc0(Object05827ee0 *object); /* derived name */

int FUN_00a5ebc0(lua_State *state) /* derived name */
{
    FUN_00b61cc0(D_5827ee0);
    return 0;
}
