/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a8c70.h"

/* derived name: the complete destructor of Object016a8c70
 * (tlg_game_object016a8c70.h): the body is empty and the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00379200,
 * slot 1, is the deleting one. The destructor is the class's key function,
 * so this file emits the vtable. */
Object016a8c70::~Object016a8c70() {}

/* derived name: the state the constructor puts back after its initialisers
 * (inlined in the creator FUN_00378fb0 by the link: its stores stay apart,
 * in this order) */
void Object016a8c70::reset()
{
    unknown24[0] = 0;
    unknown2c = 0;
    unknown30 = 0;
    unknown34 = 0;
    unknown80 = 0;
    unknown84 = 0;
    unknown88 = 0;
    unknown40.set(0.0f, 0.0f, 0.0f, 0.0f);
    unknown50 = 0;
    unknown8c = -1.0f;
    unknown90.set(0.0f, 0.0f, 0.0f, 0.0f);
}
