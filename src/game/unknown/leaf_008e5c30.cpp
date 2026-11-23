/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_hks_string.h"
#include "tlg_libc.h"
#include "tlg_game_object016b0448.h"

/* derived names: the script C function named "MSC_GetPreviousStage" by its
 * parameter-count message: with any argument it formats that message into a
 * local buffer that nothing reads, then pushes the string of the Name at
 * +0x10 of the object the pointer at 0x581f740 holds (nil when the name has
 * no string) and returns 1 (one result). The C function's own name is
 * unknown. */
int FUN_008e5c30(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetPreviousStage", 0);
    }
    pushString(state, D_17ac870[D_581f740->previousStage.index].string0);
    return 1;
}
