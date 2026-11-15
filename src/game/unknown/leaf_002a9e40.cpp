/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a7df0.h"

/* derived name: the constructor (tlg_game_object016a7df0.h): its base
 * Object016b9108 is built from the name passed on, the Name at +0x24 starts
 * empty, the three arrays cleared; then the body: the Name emptied again
 * (`cmp dword [rbx+0x24], 0`: an assignment from the empty name), the
 * pointers at +0x28, +0x78 and +0x80 cleared. */
Object016a7df0::Object016a7df0(const Name &name) : Object016b9108(name)
{
    name24 = Name();
    unknown28 = 0;
    unknown78 = 0;
    unknown80 = 0;
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_002a9fc0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a7df0::~Object016a7df0() {}
