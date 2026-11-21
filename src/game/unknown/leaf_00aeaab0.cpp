/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4100.h"

/* derived names: the complete destructor FUN_00aeaab0: the array at +0x50
 * emptied (each reference released, then the block given back with no
 * capacity), then the members and the base torn down. The class's
 * key function: this unit emits the vtable and the deleting destructor
 * FUN_00aeac80. */
Object016b4100::~Object016b4100()
{
    array50.clear();
}
