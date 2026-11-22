/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a92c8.h"

/* slot 5 (0x16a92c8's word at 0x16a9300): slot 5 of every child, first to
 * last (the counter unsigned, the element read at a signed index: `movsxd`
 * in the loop) */
void Object016a92c8::slot5()
{
    for (unsigned i = 0; i < children.size(); ++i)
        children.at(i).get()->slot5();
}
