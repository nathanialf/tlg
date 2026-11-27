/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived name: a script C function: with two arguments or more, the first
 * is read twice into one handle (FUN_00c91760, a reader made for each read)
 * and whether the handle holds no property name is pushed; returns 1, or 0
 * with fewer arguments. */
// NONMATCHING: 69/72, 287 bytes as the base; one difference, at the handle's end: the schedulers' order at the empty
// name's raise: the build takes the `lock inc` before the `lea` of the table and the `mov edx, -1` that the base
// places above it; decided after the IR (with -post-RA-scheduler=false the pre-RA order is `lock inc; lea; mov rcx`,
// and the post-RA pass lifts only the `mov rcx`): D97's two rules for `lock dec`, not `lock inc` (round 600D,
// scratch d600/lockinc_drafts.txt)
int FUN_00e79280(lua_State *state) /* derived name */
{
    if (argumentCount(state) < 2)
        return 0;
    PropertyHandle00c91760 handle;
    ArgumentReader00c91760 reader(state);
    FUN_00c91760(&reader, &handle);
    ArgumentReader00c91760 again(state);
    FUN_00c91760(&again, &handle);
    pushBoolean(state, handle.name.index == 0);
    return 1;
}
