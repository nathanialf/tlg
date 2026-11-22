/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"

/* FUN_00203760: a reference to the object appended to an array of counted
 * references (the array's append, FUN_0138e360, called with a temporary
 * reference); the index is not used */
void FUN_00203760(Object016b9108 *object, Object0134f620 *objects) /* derived name */
{
    if (object)
        objects->add(Ref00503fb0<Object016b9108>(object));
}
