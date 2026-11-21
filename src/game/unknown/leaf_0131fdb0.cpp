/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c3be0.h"

Object016c3be0::~Object016c3be0()
{
    if (state124 != 1 && state124 != 3) {
        returnEntry(entry30);
        returnEntry(entry40);
        returnEntry(entry48);
        returnEntry(entry58);
    }
}
