/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_frames013fb310.h"

/* FUN_013fcc20: a vector set made two zero vectors long (the array's and the
 * lock's constructors, then the resize to 2). Called by FUN_0107b510 and by
 * FUN_0108d540, the resize of the sets at +0xa0 of the poser
 * (tlg_game_frames013fb310.h). */
VectorSet01404660::VectorSet01404660()
{
    vectors.resize(2);
}
