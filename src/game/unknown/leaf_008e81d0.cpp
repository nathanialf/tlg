/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_name.h"
#include "tlg_game_object0581f740.h"

/* derived names: the script C function named "MSC_GetIncludeCurrentState" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes whether a state of the object
 * the pointer at 0x581f740 holds has the Name its first argument's string
 * makes, as a boolean; returns 1 (one result). The C function's own name is
 * unknown. */
int FUN_008e81d0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetIncludeCurrentState", 1);
    }
    HashedString string;
    FUN_00e81bd0(&string, state, 1);
    Name wanted(string);
    for (unsigned i = 0; i < D_581f740->states.size(); ++i) {
        if (D_581f740->states.at(i) == wanted) {
            pushBoolean(state, true);
            return 1;
        }
    }
    pushBoolean(state, false);
    return 1;
}
