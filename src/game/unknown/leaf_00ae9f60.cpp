/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4028.h"

/* derived names: the complete destructor FUN_00ae9f60: the array at +0x48
 * emptied (each reference released, then the block given back with no
 * capacity), then the members and the other arrays and the base torn down. The class's
 * key function: this unit emits the vtable and the deleting destructor
 * FUN_00aea140. */
Object016b4028::~Object016b4028()
{
    array48.clear();
}
