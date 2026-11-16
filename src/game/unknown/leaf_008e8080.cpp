/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_object0581f740.h"

/* derived names: the script C function named "MSC_SetNeedStageChangeProc" by
 * its parameter-count message (with the wrong count it formats that message
 * into a local buffer that nothing reads): stores its first argument's truth
 * (false without one) in the int needStageChangeProc of the object the
 * pointer at 0x581f740 holds; returns 0 (no results). The C function's own
 * name is unknown. */
int FUN_008e8080(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetNeedStageChangeProc", 1);
    }
    const HksObject *value = state->base < state->top ? state->base : 0;
    int type = state->base < state->top ? value->type & 0xf : 0;
    bool need = false;
    if (type != 0) {
        need = true;
        if (type == 1)
            need = value->value.boolean != 0;
    }
    D_581f740->needStageChangeProc = need;
    return 0;
}
