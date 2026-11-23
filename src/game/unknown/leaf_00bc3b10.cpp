/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00bc3b10.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b76b0 (tlg_game_object00bc3b10.h): it stores the vtable, releases
 * what the object holds (FUN_00bc3b40) and runs its base's destructor
 * FUN_00bc3780 as a tail call. FUN_00bc3d70, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object00bc3b10::~Object00bc3b10()
{
    releaseResources();
}
