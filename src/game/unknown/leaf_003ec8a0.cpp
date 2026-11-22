/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a92c8.h"

/* slot 9: slot 9 of every child with the argument, first to last */
void Object016a92c8::slot9(void *argument)
{
    for (unsigned i = 0; i < children.size(); ++i)
        children.at(i).get()->slot9(argument);
}
