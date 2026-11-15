/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9638.h"

/* derived name: the constructor (tlg_game_object016a9638.h): its base
 * Object016b9108 is built from the name passed on, the arrays and the Names
 * start empty; then the body: a Name appended to each array, the array grown
 * first when it is full, and the two Names set, each made from its string and
 * added (`mov ecx, 1`). */
Object016a9638::Object016a9638(const Name &name) : Object016b9108(name)
{
    names28.push(Name("RunToItemVolume"));
    names40.push(Name("ItemPickupVolume"));
    name58 = Name("ControlCommand_P_item_pickup");
    name5c = Name("candidateOfItemPickup");
}

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_003f4bd0, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016a9638::~Object016a9638() {}
