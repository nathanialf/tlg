/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d3868 (config/vtables.derived.base.txt): it stores the vtable and releases
 * the block the pointer at +0x18 holds (tlg_game_block.h). The destructor is
 * the class's key function, so this file emits the vtable; the deleting one
 * is the compiler's. The class is in tlg_game_block.h. */
Object013d2f90::~Object013d2f90()
{
    releaseBlock(unknown18);
}
