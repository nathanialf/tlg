/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013ef2e0.h"

/* derived name: the complete destructor (tlg_game_object013ef2e0.h). The
 * destructor is the class's key function, so this file emits the vtable;
 * the deleting one is the compiler's. */
Object013ef2e0::~Object013ef2e0() {}

void Object013ef2e0::reset()
{
    values18.resize(36);
    for (unsigned i = 0; i < values18.size(); ++i)
        values18[i] = 0;
}
