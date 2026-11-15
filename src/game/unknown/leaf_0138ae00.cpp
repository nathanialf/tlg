/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ce208.h"

/* derived name: the constructor (tlg_game_object016ce208.h): its base
 * Object016b9108 is built from the name passed on, the array at +0x28
 * starts empty; then two Names of the same string "dummySave" (the string at
 * 0x15a39bf, its length 9 passed, not added), each a guarded static of this
 * function registered with Name's destructor, are passed to FUN_00a174c0, a
 * tail call. */
Object016ce208::Object016ce208(const Name &name) : Object016b9108(name)
{
    static Name D_5826ee0("dummySave", false);
    static Name D_5826ef0("dummySave", false);
    FUN_00a174c0(D_5826ee0, D_5826ef0);
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_0138aea0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ce208::~Object016ce208() {}
