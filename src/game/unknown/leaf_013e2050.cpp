/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013e4200.h"

/* derived name: slot 2 of Object013e4200 (tlg_game_object013e4200.h): the base's
 * slot 2, then the vector at +0x510 cleared */
void Object013e4200::slot2()
{
    Object016d3ef8::slot2();
    unknown510 = _mm_setzero_ps();
}
