/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3e10.h"

/* derived name: the destructor empties the reference by compare-and-swap,
 * then the member's own destructor drops what is left the plain way (the
 * pointer read again at 0x13d8ee4) */
Object016d3e10::~Object016d3e10()
{
    reset();
}
