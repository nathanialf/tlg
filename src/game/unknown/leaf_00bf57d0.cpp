/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b7d50.h"

/* derived name: the complete destructor of Object016b7d50
 * (tlg_game_object016b7d50.h): the first two arrays' references are
 * released with their blocks kept and the reference at +0x58 emptied by
 * compare-and-swap, then the members are torn down, last first, then the
 * base. FUN_00bf5dc0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016b7d50::~Object016b7d50()
{
    array28.removeAll();
    array40.removeAll();
    held58.clear();
}
