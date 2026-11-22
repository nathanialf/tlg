/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a8618.h"

/* 0x325ed0: the pool given up, its word at +0x48 reset first; then the
 * members, the last first, and the root class's body */
Object016a8618::~Object016a8618()
{
    pool.resetAndShutdown();
}
