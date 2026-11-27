/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived name: a script C function storing one element of an object's
 * property: with three arguments or more, the first read as an object and a
 * property name (FUN_00c91760); when the second is a number and the
 * object's type has the property (FUN_00cb7e20), the third is stored in
 * the element the second counts from 1 (FUN_013ca090, mode 1). Returns 0
 * (no results). */
// NONMATCHING: 131/137, 577 bytes as the base; one difference, at both copies of the handle's end: the schedulers'
// order at the empty name's raise: the build takes the `lock inc` before the `lea` of the table and the `mov edx,
// -1` that the base places above it; decided after the IR (with -post-RA-scheduler=false the pre-RA order is `lock
// inc; lea; mov rcx`, and the post-RA pass lifts only the `mov rcx`): D97's two rules for `lock dec`, not `lock inc`
// (round 600D, scratch d600/lockinc_drafts.txt) (the early return for no object, the type's test inside the scope:
// round 600D)
int FUN_00e678b0(lua_State *state) /* derived name */
{
    if (argumentCount(state) >= 3) {
        PropertyHandle00c91760 handle;
        ArgumentReader00c91760 reader(state);
        FUN_00c91760(&reader, &handle);
        Object016b9108 *object = handle.object;
        if (!object)
            return 0;
        if (typeOf(state, 2) == 3) {
            Property00e78f90 property;
            if (FUN_00cb7e20(object->type, &handle.name, &property)) {
                ArgumentReader00c91760 value(state, &property, 3, 1, (int)toNumber(state, 2) - 1);
                FUN_013ca090(&property, object, &value, 1);
            }
        }
    }
    return 0;
}
