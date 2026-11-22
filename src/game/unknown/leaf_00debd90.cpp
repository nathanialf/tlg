/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the debug library's "print" (its entry in the table at
 * 0x16bc980): the arguments handed to the debugger, then the stack
 * emptied; no results */
int FUN_00debd90(lua_State *state)
{
    hksi_hks_debugprint(state, argumentCount(state));
    setTop(state, 0);
    return 0;
}
