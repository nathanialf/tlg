/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a92c8.h"

/* slot 6: slot 6 of the children in order with the argument, stopping at
 * the first that answers 0 (`call [rax+0x30]; test eax, eax; je`); the
 * answer is 1 whatever the children said */
int Object016a92c8::slot6(void *argument)
{
    for (unsigned i = 0; i < children.size(); ++i)
        if (!children.at(i).get()->slot6(argument))
            break;
    return 1;
}
