/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ca768.h"

/* derived name: slot 2 of Object016ca568 (tlg_game_object016ca768.h), which its
 * eight derived classes keep: the base's slot 2, then the two vectors at
 * +0x240 cleared and the int at +0x260 set to 1 */
void Object016ca568::slot2()
{
    Object016d3ef8::slot2();
    unknown240 = _mm_setzero_ps();
    unknown250 = _mm_setzero_ps();
    unknown260 = 1;
}
