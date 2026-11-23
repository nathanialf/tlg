/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c96e0.h"

/* FUN_00bc4600: the shared references dropped up from +0x20, then the
 * counted ones, then the three pointers cleared */
void Object013c96e0::releaseResources()
{
    releaseAndClear(shared20);
    releaseAndClear(shared28);
    releaseAndClear(shared38);
    releaseAndClear(shared40);
    releaseAndClear(counted50);
    releaseAndClear(counted58);
    unknown30 = 0;
    unknown48 = 0;
    unknown60 = 0;
}
