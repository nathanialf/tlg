/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: the script C function "SetSaveSlot" (FUN_001db8b0
 * registers it through FUN_00c87e30, lea at 0x1db46a): with an argument,
 * reads the first as a name (nameArgument),
 * which is dropped again: the slot is not kept in this build. Returns 0 (no
 * results). */
int FUN_001b2df0(lua_State *state) /* derived name */
{
    if (argumentCount(state) > 0) {
        const Name slot = nameArgument(state, 1);
    }
    return 0;
}
