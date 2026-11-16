/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_hks_string.h"
#include "tlg_libc.h"
#include "tlg_game_name.h"
#include "tlg_game_object0581f740.h"

/* derived names: the script C function named "MSC_GetCurrentStates" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes a table holding, at 1 to the
 * count, a table for each state of the object the pointer at 0x581f740
 * holds, its "stage_name" the string of the state's Name at +0x14 and its
 * "state_name" the string of its Name at +0x18 (nil for a Name without
 * one); returns 1 (one result). The C function's own name is unknown. */
int FUN_008eb2f0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetCurrentStates", 0);
    }
    FUN_00d91880(state, D_581f740->states.size(), 0);
    for (unsigned i = 0; i < D_581f740->states.size(); ++i) {
        pushInteger(state, i + 1);
        FUN_00d91880(state, 2, 0);
        pushString(state, "stage_name");
        pushString(state, D_17ac870[D_581f740->states.at(i).unknown14.index].string0);
        setTable(state);
        pushString(state, "state_name");
        pushString(state, D_17ac870[D_581f740->states.at(i).name.index].string0);
        setTable(state);
        setTable(state);
    }
    return 1;
}
