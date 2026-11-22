/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00952760.h"

/* FUN_013b7530: a reference to the object appended to the array
 * (FUN_00952760, called with a temporary reference) when bit 0 of the
 * object's flags at +0x24 is set; returns 1. Its callers are not traced. */
int FUN_013b7530(Counted00952760 *object, Array00952760 *objects) /* derived name */
{
    if (object->flags24 & 1)
        objects->push(Ref00503fb0<Counted00952760>(object));
    return 1;
}
