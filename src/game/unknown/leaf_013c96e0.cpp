/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c96e0.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d2d40 (tlg_game_object013c96e0.h): it stores the vtable, releases
 * what the object holds (FUN_00bc4600) and runs its base's destructor
 * FUN_00bc3780 as a tail call. FUN_013c9710, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object013c96e0::~Object013c96e0()
{
    releaseResources();
}
