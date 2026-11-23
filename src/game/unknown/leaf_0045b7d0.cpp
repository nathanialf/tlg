/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_links00c63970.h"

extern const Name D_57d528c; /* derived name */
extern const Name D_57d5488; /* derived name */

/* FUN_0045b7d0: with an object, the names at 0x57d528c, the object's name and
 * the name at 0x57d5488 posted to the game's dispatcher */
void FUN_0045b7d0(const Object016b9108 *object) /* derived name */
{
    if (object)
        postMessage(D_57d528c, object->name, D_57d5488);
}
