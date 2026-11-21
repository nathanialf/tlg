/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4148.h"

/* derived names: the complete destructor FUN_00aeae40: the array emptied (each
 * reference released, then the block given back with no capacity), then the
 * members and the base torn down. The class's key function: this unit emits
 * the vtable and the deleting destructor FUN_00aeb010. */
Object016b4148::~Object016b4148()
{
    array30.clear();
}
