/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_object016b0448.h"

/* derived names: the script C function named "MSC_SetPatSpeedFade" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): stores its first two arguments' numbers
 * (0 for one it is not given) in patSpeedFade[0] and [1] of the object the
 * pointer at 0x581f740 holds; returns 0 (no results). The C function's own
 * name is unknown. */
// NONMATCHING: the second store's object pointer: the base reads 0x581f740 again only after the
// second number's call (the first read kept across the float store where there is no call), this
// build reads it again after the merge on both paths; the rest equal
int FUN_008e6190(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 2) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetPatSpeedFade", 2);
    }
    D_581f740->patSpeedFade[0] = toNumber(state, 1);
    D_581f740->patSpeedFade[1] = toNumber(state, 2);
    return 0;
}
