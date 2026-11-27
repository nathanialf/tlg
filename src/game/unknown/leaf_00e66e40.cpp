/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived names: a script C function over an object's property: with two
 * arguments or more, the first read as an object and a property name
 * (FUN_00c91760); when the object's type has the property (FUN_00cb7e20),
 * each further argument is stored in it in turn (FUN_013ca090, mode 2).
 * Returns 0 (no results). */
// NONMATCHING: the handle's end (0xe66fd3): the base reads the name's index once, keeps it across the
// empty name's `lock inc` for the release and the free, and copies the end into both ways out (the
// object's null test's and the loop's); the build reloads it after the raise (atomic-01's rule answers
// ModRef: FUN_00c91760 is handed the handle and writes through it) and merges the two ends. Everything
// before it is the base's (the frame, the store of the count from 1, the registers)
int FUN_00e66e40(lua_State *state) /* derived name */
{
    const int count = argumentCount(state);
    if (count >= 2) {
        PropertyHandle00c91760 handle;
        ArgumentReader00c91760 reader(state);
        FUN_00c91760(&reader, &handle);
        if (Object016b9108 *object = handle.object) {
            Property00e78f90 property;
            if (FUN_00cb7e20(object->type, &handle.name, &property)) {
                for (int argument = 2; argument <= count; ++argument) {
                    ArgumentReader00c91760 value(state, &property, argument, 2, -1);
                    FUN_013ca090(&property, object, &value, 1);
                }
            }
        }
    }
    return 0;
}

/* derived name: the same in mode 3 (0xe67070, FUN_00e66e40's twin byte for byte but the mode) */
// NONMATCHING: the handle's end (0xe67203): the base reads the name's index once, keeps it across the
// empty name's `lock inc` for the release and the free, and copies the end into both ways out (the
// object's null test's and the loop's); the build reloads it after the raise (atomic-01's rule answers
// ModRef: FUN_00c91760 is handed the handle and writes through it) and merges the two ends. Everything
// before it is the base's (the frame, the store of the count from 1, the registers)
int FUN_00e67070(lua_State *state) /* derived name */
{
    const int count = argumentCount(state);
    if (count >= 2) {
        PropertyHandle00c91760 handle;
        ArgumentReader00c91760 reader(state);
        FUN_00c91760(&reader, &handle);
        if (Object016b9108 *object = handle.object) {
            Property00e78f90 property;
            if (FUN_00cb7e20(object->type, &handle.name, &property)) {
                for (int argument = 2; argument <= count; ++argument) {
                    ArgumentReader00c91760 value(state, &property, argument, 3, -1);
                    FUN_013ca090(&property, object, &value, 1);
                }
            }
        }
    }
    return 0;
}
