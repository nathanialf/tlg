/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b78f0.h"

/* derived name: the complete destructor FUN_00bde1c0: the three arrays
 * emptied to no capacity, then the members and the base torn down. The
 * class's key function: this unit emits the vtable and the deleting
 * destructor FUN_00bde4e0. */
Object016b78f0::~Object016b78f0()
{
    array28.clear();
    array48.clear();
    array60.clear();
}
