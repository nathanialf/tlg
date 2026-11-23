/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bd3b0.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16bd3b0 (tlg_game_object016bd3b0.h): the body hands the object to
 * releaseResources (FUN_00df1030); then the references are dropped, last
 * first. FUN_00df1930, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016bd3b0::~Object016bd3b0()
{
    releaseResources();
}
