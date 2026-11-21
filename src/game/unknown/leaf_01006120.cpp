/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c0b40.h"

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x20c and empties the reference at +0x228;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_01006760, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c0b40::~Object016c0b40()
{
    if (registry)
        registry->remove(this);
    if (active20c != 0) {
        if (Refs01006120 *refs = owner220->refs28) {
            refs->ref28.clear();
            refs->ref30.clear();
            refs->ref38.clear();
        }
        if (object290)
            object290->release();
        object290 = 0;
        active20c = 0;
    }
    held.clear();
}
