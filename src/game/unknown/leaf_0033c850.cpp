/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a86d8.h"

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_0033cb30, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a86d8::~Object016a86d8() {}

/* derived name: the constructor: the base built from the name and the nine
 * parts by their constructor, then flag 0 of the base's flags at +0x16 set
 * and the fields after the parts given their first values. Its creator
 * FUN_0033b3f0 calls it. */
Object016a86d8::Object016a86d8(const Name &name) : Object016b9108(name)
{
    flags16 |= 1;
    unknown430 = 20;
    unknown438[0] = 0;
    unknown438[1] = 0;
    unknown438[2] = 0;
    unknown444 = 24;
    unknown434 = 2.0f;
    unknown448 = 2.0f;
    unknown454 = 0;
    unknown44c = 0;
    unknown450 = 0;
}
