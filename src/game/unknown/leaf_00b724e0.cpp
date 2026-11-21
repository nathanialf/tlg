/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b6bc8.h"

/* derived name: the complete destructor of the subtitles' class
 * (tlg_game_object016b6bc8.h): FUN_00b728c0 stops them, then the members
 * are torn down, last first. FUN_00b72bf0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016b6bc8::~Object016b6bc8()
{
    FUN_00b728c0();
}
