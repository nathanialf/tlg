/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived names: a script C function over an object's property: with two
 * arguments or more, the first read as an object and a property name
 * (FUN_00c91760); when the object's type has the property (FUN_00cb7e20),
 * each further argument is stored in it in turn (FUN_013ca090, mode 2).
 * Returns 0 (no results). */
// NONMATCHING: 119/125, 548 bytes as the base; one difference, at both copies of the handle's end: the schedulers'
// order at the empty name's raise: the build takes the `lock inc` before the `lea` of the table and the `mov edx,
// -1` that the base places above it; decided after the IR (with -post-RA-scheduler=false the pre-RA order is `lock
// inc; lea; mov rcx`, and the post-RA pass lifts only the `mov rcx`): D97's two rules for `lock dec`, not `lock inc`
// (round 600D, scratch d600/lockinc_drafts.txt) (the early return for no object gives the handle two cleanup
// destinations, so the end is copied into both ways out as in the base; round 600D)
int FUN_00e66e40(lua_State *state) /* derived name */
{
    const int count = argumentCount(state);
    if (count >= 2) {
        PropertyHandle00c91760 handle;
        ArgumentReader00c91760 reader(state);
        FUN_00c91760(&reader, &handle);
        Object016b9108 *object = handle.object;
        if (!object)
            return 0;
        Property00e78f90 property;
        if (FUN_00cb7e20(object->type, &handle.name, &property)) {
            for (int argument = 2; argument <= count; ++argument) {
                ArgumentReader00c91760 value(state, &property, argument, 2, -1);
                FUN_013ca090(&property, object, &value, 1);
            }
        }
    }
    return 0;
}

/* derived name: the same in mode 3 (0xe67070, FUN_00e66e40's twin byte for byte but the mode) */
// NONMATCHING: 119/125, 548 bytes as the base; one difference, at both copies of the handle's end: the schedulers'
// order at the empty name's raise: the build takes the `lock inc` before the `lea` of the table and the `mov edx,
// -1` that the base places above it; decided after the IR (with -post-RA-scheduler=false the pre-RA order is `lock
// inc; lea; mov rcx`, and the post-RA pass lifts only the `mov rcx`): D97's two rules for `lock dec`, not `lock inc`
// (round 600D, scratch d600/lockinc_drafts.txt) (the early return for no object gives the handle two cleanup
// destinations, so the end is copied into both ways out as in the base; round 600D)
int FUN_00e67070(lua_State *state) /* derived name */
{
    const int count = argumentCount(state);
    if (count >= 2) {
        PropertyHandle00c91760 handle;
        ArgumentReader00c91760 reader(state);
        FUN_00c91760(&reader, &handle);
        Object016b9108 *object = handle.object;
        if (!object)
            return 0;
        Property00e78f90 property;
        if (FUN_00cb7e20(object->type, &handle.name, &property)) {
            for (int argument = 2; argument <= count; ++argument) {
                ArgumentReader00c91760 value(state, &property, argument, 3, -1);
                FUN_013ca090(&property, object, &value, 1);
            }
        }
    }
    return 0;
}
