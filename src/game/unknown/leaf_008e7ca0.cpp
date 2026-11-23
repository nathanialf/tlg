/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b0448.h"

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */
static inline Name argumentName(lua_State *state, int argument)
{
    HashedString string;
    FUN_00e81bd0(&string, state, argument);
    return Name(string);
}

/* derived names: the script C function named "MSC_UnRegisterState2" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): finds the first state of the object
 * the pointer at 0x581f740 holds whose Names at +0x14 and +0x18 are the ones
 * its two arguments' strings make, and sets that state's int at +0x28 and
 * the object's int at +0x24 to 1; returns 0 (no results). The C function's
 * own name is unknown. */
int FUN_008e7ca0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 2) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_UnRegisterState2", 2);
    }
    Name first;
    first = argumentName(state, 1);
    Name second;
    second = argumentName(state, 2);
    Object016b0448 *object = D_581f740;
    for (unsigned i = 0; i < object->states.size(); ++i) {
        State0581f740 &entry = object->states.at(i);
        if (entry.unknown14 == first && entry.name == second) {
            entry.unknown28 = 1;
            object->unknown24 = 1;
            break;
        }
    }
    return 0;
}
