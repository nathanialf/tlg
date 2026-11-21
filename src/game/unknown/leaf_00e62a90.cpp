/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bdd60.h"

/* derived names: the complete destructor FUN_00e62a90: the array at +0x30
 * emptied (each reference released, then the block given back with no
 * capacity), then the members and the base torn down. The class's
 * key function: this unit emits the vtable and the deleting destructor
 * FUN_00e62c60. */
Object016bdd60::~Object016bdd60()
{
    array30.clear();
}
