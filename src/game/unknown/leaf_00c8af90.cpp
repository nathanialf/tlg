/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived names: FUN_00e78f90's table without the class name (its one
 * caller FUN_00e793a0): "type", the name of the property's kind, and
 * "isArray", bit 0 of its flags */
// case 0 first in both switches, as FUN_00e78f90 (the base tests 1 then 0 and 3 then 0)
void FUN_00c8af90(lua_State *state, const Property00e78f90 *property) /* derived name */
{
    FUN_00d91880(state, 0, 0);
    PUSH_KNOWN_STRING(state, D_14b2cd2);
    switch (property->kind) {
    case 0:
        if (property->enumeration) {
            switch (property->enumeration->kind) {
            case 0:
                PUSH_KNOWN_STRING(state, D_14baa92);
                break;
            case 3:
                PUSH_KNOWN_STRING(state, D_15c07a5);
                break;
            }
        } else {
            PUSH_KNOWN_STRING(state, D_15b6065);
        }
        break;
    case 1:
        if (property->enumeration)
            PUSH_KNOWN_STRING(state, D_15c07b5);
        else
            PUSH_KNOWN_STRING(state, D_15b6073);
        break;
    default: {
        const int kind = property->kind;
        const char *name = (unsigned)kind < 15 ? D_16b9f00[kind] : D_15b605d;
        FUN_013aacc0(state, name, strlen(name));
    }
    }
    setTable(state);
    PUSH_KNOWN_STRING(state, D_15c07ba);
    pushBoolean(state, property->isArray);
    setTable(state);
}
