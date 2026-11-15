/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a95d8.h"

/* derived name: the constructor (tlg_game_object016a95d8.h): its base
 * Object016b9108 is built from the name passed on, the arrays and the Names
 * start empty; then the body, in the order of its bytes: each Name made from
 * its string, appended to its array (grown first when full) or assigned. */
Object016a95d8::Object016a95d8(const Name &name) : Object016b9108(name)
{
    names28.push(Name("B_A_struggle_legR_start"));
    names28.push(Name("B_A_struggle_legL_start"));
    name88 = Name("ControlCommand_P_rapid_input_circle");
    names40.push(Name("B_A_struggle_legR_start"));
    names40.push(Name("B_A_struggle_legL_start"));
    name8c = Name("ControlCommand_P_rapid_input_triangle");
    names58.push(Name("B_A_struggle_armR_start"));
    names58.push(Name("B_A_struggle_armL_start"));
    name90 = Name("ControlCommand_P_rapid_input_cross");
    names70.push(Name("B_A_struggle_armR_start"));
    names70.push(Name("B_A_struggle_armL_start"));
    name94 = Name("ControlCommand_P_rapid_input_square");
}

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_003f3fd0, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016a95d8::~Object016a95d8() {}
