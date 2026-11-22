/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aa220.h"

/* derived name: the complete destructor: the reference at +0x50 emptied
 * by compare-and-swap, then the members and the base released.
 * FUN_004b51b0, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016aa220::~Object016aa220()
{
    held50.clear();
}
