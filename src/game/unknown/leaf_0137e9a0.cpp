/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"
#include "tlg_game_object016ccdd0.h"

/* derived name: the complete destructor of the class whose vtable is at
 * 0x16ccdd0: when it holds a heap block at +0x8 it releases it
 * (tlg_game_block.h), clears the pointer and the count at +0x14. FUN_0137ea10,
 * slot 1, is the deleting one (the two stores dead before operator delete).
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016ccdd0::~Object016ccdd0()
{
    if (block8 != 0) {
        releaseBlock(block8);
        block8 = 0;
        count14 = 0;
    }
}
