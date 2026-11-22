/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_entry00a925e0.h"

/* 0xa925e0, in a file of its own as its two callers call it */
Entry00a925e0::~Entry00a925e0()
{
    pool.resetAndShutdown();
}
