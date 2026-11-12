/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object0134a810.h"

/* derived name: the complete destructor of the class whose vtable is at
 * 0x16c7328 (tlg_game_object0134a810.h): it stores the vtable and releases
 * the block the pointer at +0x68 holds (tlg_game_block.h). The destructor is
 * the class's key function, so this file emits the vtable; the deleting one
 * is the compiler's. */
Object0134a810::~Object0134a810()
{
    releaseBlock(unknown68);
}
