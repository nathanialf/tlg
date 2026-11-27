/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_command003e4440.h"
#include "tlg_game_property00e78f90.h"

/* derived name: a script C function: with two arguments or more, the first
 * read as an object (FUN_00c8c290) and the second, a string, as the name of
 * one of its type's properties; a property found that is neither of the
 * kinds bit 9 and the array flag mark gets the third argument
 * stored in it (FUN_013ca090, mode 0). Returns 0 (no results). */
int FUN_00e774f0(lua_State *state) /* derived name */
{
    if (argumentCount(state) >= 2) {
        Object016b9108 *read = 0;
        ArgumentReader003e4440 reader(state);
        FUN_00c8c290(&reader, &read);
        Object016b9108 *object = read;
        if (object && typeOf(state, 2) == 4) {
            HashedString string;
            FUN_00e81bd0(&string, state, 2);
            Name name(string);
            const Property00e78f90 *property = findProperty(object->type, name);
            if (property && !property->unknown9 && !property->isArray) {
                ArgumentReader00c91760 value(state, property, 3, 0, -1);
                FUN_013ca090(property, object, &value, 1);
            }
        }
    }
    return 0;
}
