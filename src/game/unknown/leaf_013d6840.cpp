/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object013d6840.h"

/* derived names: the complete destructor of Object013d6840
 * (tlg_game_object013d6840.h): it stores the vtable and releases the block
 * the pointer at +0x18 holds. The destructor is the class's key function, so
 * this file emits the vtable; the deleting one is the compiler's. */
Object013d6840::~Object013d6840()
{
    releaseBlock(unknown18);
}
