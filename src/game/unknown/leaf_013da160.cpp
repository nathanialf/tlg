/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013da160.h"

/* derived name: the complete destructor (tlg_game_object013da160.h). The
 * destructor is the class's key function, so this file emits the vtable;
 * the deleting one is the compiler's. */
Object013da160::~Object013da160() {}

void Object013da160::reset()
{
    values18.resize(44);
    for (unsigned i = 0; i < values18.size(); ++i)
        values18[i] = 0;
}
