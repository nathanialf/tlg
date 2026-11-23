/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_links00c63970.h"

extern const Name D_57d6b88; /* derived name */

/* FUN_004af420: the given name, the name at 0x57d6b88 and the second given
 * name posted to the game's dispatcher (FUN_00482b90, FUN_004a3870) */
void FUN_004af420(const Name &first, const Name &third) /* derived name */
{
    postMessage(first, D_57d6b88, third);
}
