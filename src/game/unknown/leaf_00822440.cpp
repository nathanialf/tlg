/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aeab0.h"

void FUN_00822600(Object016aeab0 *object); /* derived name */

/* derived name: the body calls FUN_00822600 on the object; the references
 * at +0x250, +0x240 and +0x238 are released after it, then the base's
 * destructor FUN_00c55550 runs as a tail call */
Object016aeab0::~Object016aeab0()
{
    FUN_00822600(this);
}
