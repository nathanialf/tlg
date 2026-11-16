/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_object0581f740.h"

/* derived names: the script C function named "MSC_GetStepRestart" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes the int stepRestart of the
 * object the pointer at 0x581f740 holds, as a number, and returns 1 (one
 * result). The C function's own name is unknown. */
int FUN_008e6300(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetStepRestart", 0);
    }
    pushNumber(state, D_581f740->stepRestart);
    return 1;
}
