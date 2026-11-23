/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_object016b0448.h"

/* derived names: the script C function named "MSC_GetNeedStageChangeProc" by
 * its parameter-count message (with the wrong count it formats that message
 * into a local buffer that nothing reads): pushes whether the int
 * needStageChangeProc of the object the pointer at 0x581f740 holds is not 0,
 * as a boolean, and returns 1 (one result). The C function's own name is
 * unknown. */
int FUN_008e8130(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetNeedStageChangeProc", 0);
    }
    pushBoolean(state, D_581f740->needStageChangeProc != 0);
    return 1;
}
