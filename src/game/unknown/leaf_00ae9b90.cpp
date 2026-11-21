/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b3fe0.h"

/* derived names: the complete destructor FUN_00ae9b90: the array at +0x68
 * emptied (each reference released, then the block given back with no
 * capacity), then the members and the other arrays and the base torn down. The class's
 * key function: this unit emits the vtable and the deleting destructor
 * FUN_00ae9d70. */
Object016b3fe0::~Object016b3fe0()
{
    array68.clear();
}
