/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c1cd0.h"

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x228 and empties the reference at +0x240;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_011f8010, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor: the register assignment differs from the start (`this` in r14, the base's
// in r13; 2065 bytes for 2049). The deleting destructor is equal and claimed
Object016c1cd0::~Object016c1cd0()
{
    if (registry)
        registry->remove(this);
    if (active228 != 0) {
        if (object2f8)
            object2f8->release();
        object2f8 = 0;
        if (object2f0)
            object2f0->release();
        object2f0 = 0;
        for (int i = 0; i < array290.size(); ++i)
            delete array290.at(i).object8;
        array290.clear();
        for (int i = 0; i < 4; ++i) {
            if (Node011f7800 *node = refs268[i].get()) {
                node->unknowna0 = 0;
                refs268[i].clear();
            }
        }
        active228 = 0;
    }
    held.clear();
}
