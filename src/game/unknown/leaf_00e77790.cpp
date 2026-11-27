/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived name: a script C function: the first argument read as an object
 * and a property name (FUN_00c91760); for an object with a name, the name's
 * string is pushed (nil for none) and 1 returned, else 0. */
// NONMATCHING: 25/97, the class of FUN_00e66e40's handle end: the base reads the name's index once after
// FUN_00c91760 (`mov r14d, [rbp-0x58]`) and keeps it through the push and the release; the build reloads it
// Round 596D: under proposed atomic-02 (no write clause) the build keeps it too, in a fifth callee-saved register
// (push r13, frame 0x48) where the base has four: 4/93 by position
int FUN_00e77790(lua_State *state) /* derived name */
{
    if (argumentCount(state) > 0) {
        PropertyHandle00c91760 handle;
        ArgumentReader00c91760 reader(state);
        FUN_00c91760(&reader, &handle);
        if (handle.object && handle.name.index != 0) {
            pushString(state, handle.name.string());
            return 1;
        }
    }
    return 0;
}
