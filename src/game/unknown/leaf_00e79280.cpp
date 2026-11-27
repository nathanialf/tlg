/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived name: a script C function: with two arguments or more, the first
 * is read twice into one handle (FUN_00c91760, a reader made for each read)
 * and whether the handle holds no property name is pushed; returns 1, or 0
 * with fewer arguments. */
// NONMATCHING: 39/75, the handle's end as FUN_00e66e40's: the base tests the index it read once
// (`mov edi, [rbp-0x70]`) for the push and the release; the build reloads it after the empty name's raise
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
