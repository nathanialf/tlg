/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_links00c63970.h"

/* FUN_00441670: with an object, the given name, the object's name and the
 * second given name posted to the game's dispatcher (FUN_0043c7b0) */
void FUN_00441670(const Object016b9108 *object, const Name &first,
                  const Name &third) /* derived name */
{
    if (object)
        postMessage(first, object->name, third);
}
