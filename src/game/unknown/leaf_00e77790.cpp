/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived name: a script C function: the first argument read as an object
 * and a property name (FUN_00c91760); for an object with a name, the name's
 * string is pushed (nil for none) and 1 returned, else 0. */
// NONMATCHING: 81/84, 325 bytes as the base; one difference, at the handle's end: the schedulers' order at the empty
// name's raise: the build takes the `lock inc` before the `lea` of the table and the `mov edx, -1` that the base
// places above it; decided after the IR (with -post-RA-scheduler=false the pre-RA order is `lock inc; lea; mov rcx`,
// and the post-RA pass lifts only the `mov rcx`): D97's two rules for `lock dec`, not `lock inc` (round 600D,
// scratch d600/lockinc_drafts.txt) (both returns inside the handle's scope, one cleanup destination, one release as
// in the base: round 600D)
int FUN_00e77790(lua_State *state) /* derived name */
{
    if (argumentCount(state) <= 0)
        return 0;
    PropertyHandle00c91760 handle;
    ArgumentReader00c91760 reader(state);
    FUN_00c91760(&reader, &handle);
    if (handle.object && handle.name.index != 0) {
        pushString(state, handle.name.string());
        return 1;
    }
    return 0;
}
