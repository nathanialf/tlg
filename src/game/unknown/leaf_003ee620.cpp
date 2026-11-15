/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9458.h"

/* derived name: the constructor (tlg_game_object016a9458.h): its base
 * Object016b9108 is built from the name passed on, the Name at +0x24 starts
 * empty and is set to "checkGrabInput" (the string at 0x1568ca9, its length
 * 14 passed: `mov edx, 0xe`). */
Object016a9458::Object016a9458(const Name &name) : Object016b9108(name)
{
    name24 = Name("checkGrabInput");
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_003ee6e0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a9458::~Object016a9458() {}
