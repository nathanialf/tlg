/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"
#include "tlg_game_object016d3dd0.h"

/* derived name: the complete destructor of the class whose vtable is at
 * 0x16d3dd0 (tlg_game_object016d3dd0.h): it stores the vtable, runs the
 * class's FUN_013d8be0 on the object, then releases the heap block it owns
 * at +0x8 (tlg_game_block.h). FUN_013d9060, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object016d3dd0::~Object016d3dd0()
{
    FUN_013d8be0();
    releaseBlock(block8);
}
