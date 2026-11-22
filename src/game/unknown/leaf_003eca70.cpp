/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9328.h"

/* slot 6: slot 6 of every child with the argument, their answers not
 * read; the answer is 1 */
int Object016a9328::slot6(void *argument)
{
    for (unsigned i = 0; i < children.size(); ++i)
        children.at(i).get()->slot6(argument);
    return 1;
}
