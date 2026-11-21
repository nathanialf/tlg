/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4ce0.h"

/* derived name: the complete destructor of Object016b4ce0
 * (tlg_game_object016b4ce0.h): stop() first, then the members are torn
 * down, last first. FUN_00b12fb0, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object016b4ce0::~Object016b4ce0()
{
    stop();
}
