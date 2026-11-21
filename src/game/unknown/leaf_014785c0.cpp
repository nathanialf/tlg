/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013d35e0.h"

/* the destructor of Object016d6a50 (tlg_game_object013d35e0.h), 0x14785c0: the pool
 * given up, then the reference released; its holder's destructor (0x1216120)
 * calls it */
Object016d6a50::~Object016d6a50()
{
    pool.shutdown();
}
