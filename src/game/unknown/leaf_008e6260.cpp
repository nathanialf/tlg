/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_object016b0448.h"

/* derived names: the script C function named "MSC_SetStepRestart" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first argument's number (0
 * without one), truncated to an int, in stepRestart of the object the pointer
 * at 0x581f740 holds; returns 0 (no results). The C function's own name is
 * unknown. */
int FUN_008e6260(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetStepRestart", 1);
    }
    D_581f740->stepRestart = toNumber(state, 1);
    return 0;
}
