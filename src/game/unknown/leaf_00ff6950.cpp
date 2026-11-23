/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d5140.h"

Object016d5140::~Object016d5140() {}

/* FUN_00ff8880: the owned names deleted and the pointer cleared, then the base's
 * destructor in line (its Name, then its entries' block) */
Object016c0710::~Object016c0710()
{
    if (names78) {
        delete names78;
        names78 = 0;
    }
}
