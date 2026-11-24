/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3b98.h"

Object016d3b98::~Object016d3b98() {}

void Object016d3b98::reset()
{
    values18.resize(64);
    for (unsigned i = 0; i < values18.size(); ++i)
        values18[i] = 0;
    unknown30.reset();
}
