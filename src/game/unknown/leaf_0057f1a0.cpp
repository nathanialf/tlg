/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ab858.h"

/* derived names: the complete destructor FUN_0057f1a0: the array at +0x60
 * emptied (each reference released, then the block given back with no
 * capacity), then the members and the other arrays and the base torn down. The class's
 * key function: this unit emits the vtable and the deleting destructor
 * FUN_0057f380. */
Object016ab858::~Object016ab858()
{
    array60.clear();
}
