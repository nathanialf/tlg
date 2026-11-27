/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_property00e78f90.h"

/* derived names: pushes a table describing a property: "type", the name of
 * its kind (the table of fifteen names at 0x16b9f00, "<error>" past it; a
 * Uint32 with an enumeration is a "Flag", a Sint32 with one an "Enum" or,
 * for an enumeration of kind 3, a "ShiftMaskedEnum"); "isArray", bit 0 of
 * the flags at +0x6; "className", the string of the name at +0x18 (nil for
 * none). An enumeration of another kind leaves the type unpushed, so the
 * table's store takes the key's slot for the value. The callers are not
 * traced. */
// The base tests the kinds 1 then 0 and the enumeration's 3 then 0: 3.7.1's switch lowering sorts
// the cases by value, then moves a case whose block comes next to the end to fall through to it
// (SelectionDAGBuilder.cpp:7938-7948), so case 0 is written first in both switches
void FUN_00e78f90(lua_State *state, const Property00e78f90 *property) /* derived name */
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
    PUSH_KNOWN_STRING(state, D_14c2f2d);
    pushString(state, D_17ac870[property->className.index].string0);
    setTable(state);
}
