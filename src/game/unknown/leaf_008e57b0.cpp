/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_name.h"
#include "tlg_game_object0581f740.h"

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */
static inline Name argumentName(lua_State *state, int argument)
{
    HashedString string;
    FUN_00e81bd0(&string, state, argument);
    return Name(string);
}

/* derived names: the script C function named "MSC_SetCurrentStage" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): the current stage's Name of the object
 * the pointer at 0x581f740 holds becomes the previous one, and its first
 * argument's string becomes the current one; returns 0 (no results). The C
 * function's own name is unknown. */
// NONMATCHING: greedy's assignment: the state in rbx and the pointer read from 0x581f740 in r15,
// the base the other way round (from 0x8e57b0+0x17); the rest the same two registers (whole module too)
int FUN_008e57b0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 1) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_SetCurrentStage", 1);
    }
    D_581f740->previousStage = D_581f740->currentStage;
    D_581f740->currentStage = argumentName(state, 1);
    return 0;
}
