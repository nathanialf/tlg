/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013d35e0.h"

/* the destructor of Object016d39f0 (tlg_game_object013d35e0.h), 0x13d3970: the pool
 * given up, then the reference released; its holder's destructor (0xf59820)
 * calls it */
Object016d39f0::~Object016d39f0()
{
    pool.shutdown();
}
