/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9290.h"

/* derived name: the constructor (tlg_game_object016a9290.h): its base
 * Object016b9108 is built from the name passed on, the arrays start empty
 * and every cell is built; then the body: three null pointers appended to
 * the array at +0x28. */
Object016a9290::Object016a9290(const Name &name) : Object016b9108(name)
{
    array28.push(0);
    array28.push(0);
    array28.push(0);
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_003eacf0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a9290::~Object016a9290() {}
