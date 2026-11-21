/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ab810.h"

/* derived names: the complete destructor FUN_0057edc0: the array at +0x50
 * emptied (each reference released, then the block given back with no
 * capacity), then the members and the base torn down. The class's
 * key function: this unit emits the vtable and the deleting destructor
 * FUN_0057ef90. */
Object016ab810::~Object016ab810()
{
    array50.clear();
}
