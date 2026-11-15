/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9578.h"

/* derived name: the constructor (tlg_game_object016a9578.h): its base
 * Object016b9108 is built from the name passed on, the array of Names at
 * +0x28 and the Name at +0x40 start empty; then the body: two names
 * appended to the array, the Name at +0x40 set. */
Object016a9578::Object016a9578(const Name &name) : Object016b9108(name)
{
    names28.push(Name("B_climb_loop"));
    names28.push(Name("B_climb_move_sync"));
    name40 = Name("ControlCommand_P_pullout_spear");
}

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_003f24b0, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016a9578::~Object016a9578() {}
