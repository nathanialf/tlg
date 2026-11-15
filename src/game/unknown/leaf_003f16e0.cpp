/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9518.h"

/* derived name: the constructor (tlg_game_object016a9518.h): its base
 * Object016b9108 is built from the name passed on, the arrays and the Names
 * start empty; then the body, in the order of its bytes: each Name made from
 * its string, appended to its array (grown first when full) or assigned. */
Object016a9518::Object016a9518(const Name &name) : Object016b9108(name)
{
    names28.push(Name("B_pickup_item_sync"));
    names28.push(Name("B_swim_item_in"));
    names28.push(Name("B_pickup_trigger"));
    names28.push(Name("B_stand_to_push_pull"));
    names28.push(Name("B_pickup_feather"));
    name40 = Name("ItemPickupStartVolume");
    name44 = Name("ControlCommand_P_item_pickup_cancel");
    name48 = Name("candidateOfItemPickup");
}

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_003f18b0, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016a9518::~Object016a9518() {}
