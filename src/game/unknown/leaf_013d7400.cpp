/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3e60.h"

/* derived name: the complete destructor (0x13d7400): the int cleared, the
 * records' references dropped and the count cleared, the object at +0x48
 * told and the one at +0x50 deleted, then the members' destructors (the
 * block at +0x20, then the array, its destructor a tail call). The
 * destructor is the class's key function, so this file emits the vtable
 * and the deleting destructor (0x13d9390). */
Object016d3e60::~Object016d3e60()
{
    records.clear();
    if (link48)
        link48->detach();
    if (owned50)
        delete owned50;
}
