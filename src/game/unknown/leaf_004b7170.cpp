/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted004b7b20.h"

/* FUN_004b7170: a reference to the object appended to the array
 * (FUN_004b7b20, called with a temporary reference; an empty reference
 * for a null object). Its callers are not traced. */
void FUN_004b7170(Array004b7b20 *objects, Counted004b7b20 *object) /* derived name */
{
    objects->push(Ref00503fb0<Counted004b7b20>(object));
}
