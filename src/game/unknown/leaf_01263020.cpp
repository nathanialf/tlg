/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d7840.h"

Object016d7840::~Object016d7840() {}

/* FUN_01264f50: the owned names deleted and the pointer cleared, then the base's
 * destructor in line (its Name, then its entries' block) */
Object016c28b8::~Object016c28b8()
{
    if (names78) {
        delete names78;
        names78 = 0;
    }
}
