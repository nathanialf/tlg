/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_links00c63970.h"

/* FUN_00a94780: three names posted to the game's dispatcher, the bytes of
 * FUN_004a6bf0 (FUN_003fd0a0 calls it; FUN_004a6bf0 has FUN_00accd20
 * and 27 more callers) */
void FUN_00a94780(const Name &first, const Name &second, const Name &third) /* derived name */
{
    postMessage(first, second, third);
}
