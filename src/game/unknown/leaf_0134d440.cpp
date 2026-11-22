/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object016a87b8.h"

/* derived names: the complete destructor of Object016a87b8
 * (tlg_game_object016a87b8.h): it stores the vtable, releases the heap block
 * it owns at +0x260 (tlg_game_block.h), then tail-calls its base's destructor
 * (0x822440). FUN_0134d4b0, slot 1, is the deleting one. The destructor is
 * the class's key function, so this file emits the vtable. */
Object016a87b8::~Object016a87b8()
{
    FUN_00ebf3f0(block260);
}
