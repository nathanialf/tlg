/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_animationcamera.h"
#include "tlg_game_log.h"

extern const char D_15ab4ef[]; /* "AnimationCamera(%s)::Term\n" */

/* The complete destructor of AnimationCamera (tlg_game_animationcamera.h):
 * the reference at +0x1b8 is emptied by compare-and-swap and the Term
 * message logged with the name's string, then the members are torn down,
 * last first, and the base's destructor FUN_00afd410 runs as a tail call.
 * FUN_00afa930, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
AnimationCamera::~AnimationCamera()
{
    held1b8.clear();
    FUN_00c831d0(this, D_15ab4ef, D_17ac870[name.index].string0);
}
