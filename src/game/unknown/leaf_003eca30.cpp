/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9328.h"

/* slot 5: slot 5 of every child, first to last (the counter unsigned, the
 * element read at a signed index: `movsxd` in the loop) */
void Object016a9328::slot5()
{
    for (unsigned i = 0; i < children.size(); ++i)
        children.at(i).get()->slot5();
}
