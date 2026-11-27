/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived name: a script C function storing one element of an object's
 * property: with three arguments or more, the first read as an object and a
 * property name (FUN_00c91760); when the second is a number and the
 * object's type has the property (FUN_00cb7e20), the third is stored in
 * the element the second counts from 1 (FUN_013ca090, mode 1). Returns 0
 * (no results). */
// NONMATCHING: 98/137, the handle's end as FUN_00e66e40's (leaf_00e66e40.cpp): the base keeps the name's
// index across the empty name's `lock inc`; the build reloads it and merges the two ends
// Round 596D: under proposed atomic-02 (no write clause) the build keeps it too, 103/137; the two ends stay merged
int FUN_00e678b0(lua_State *state) /* derived name */
{
    if (argumentCount(state) >= 3) {
        PropertyHandle00c91760 handle;
        ArgumentReader00c91760 reader(state);
        FUN_00c91760(&reader, &handle);
        if (Object016b9108 *object = handle.object) {
            if (typeOf(state, 2) == 3) {
                Property00e78f90 property;
                if (FUN_00cb7e20(object->type, &handle.name, &property)) {
                    ArgumentReader00c91760 value(state, &property, 3, 1,
                                                 (int)toNumber(state, 2) - 1);
                    FUN_013ca090(&property, object, &value, 1);
                }
            }
        }
    }
    return 0;
}
