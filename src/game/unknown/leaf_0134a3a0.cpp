/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b85e0.h"

/* derived names: slot 4 of the scene node: the reader count at +0x22c
 * dropped */
void Object016b85e0::slot4()
{
    __sync_fetch_and_sub(&readers22c.count, 1);
}
