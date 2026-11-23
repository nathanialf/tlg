/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_links00c63970.h"

extern const Name D_57d547c; /* derived name */

/* FUN_0045b4e0: with an object, the name at 0x57d547c, the object's name and
 * the given name posted to the game's dispatcher */
void FUN_0045b4e0(const Object016b9108 *object, const Name &third) /* derived name */
{
    if (object)
        postMessage(D_57d547c, object->name, third);
}
