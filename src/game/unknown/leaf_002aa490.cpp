/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a7e28.h"

/* derived name: the constructor (tlg_game_object016a7e28.h): its base
 * Object016b9108 is built from the name passed on, the arrays and the
 * references start empty; then the body: the two ints at +0x24 cleared (one
 * `mov qword [rbx+0x24], 0`) and each reference emptied by compare-and-swap,
 * the one at +0x48 first. */
Object016a7e28::Object016a7e28(const Name &name) : Object016b9108(name)
{
    unknown24 = 0;
    unknown28 = 0;
    held48.clear();
    held68.clear();
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_002aa630, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a7e28::~Object016a7e28() {}
