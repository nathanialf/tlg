/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00ced570.h"

/* derived name: the complete destructor: the body detaches the linked
 * object where there is one; then the base's destructor is inlined (its
 * vptr store, then the two names). FUN_00ced620, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. */
Object00ced570::~Object00ced570()
{
    if (peer48 != 0)
        peer48->detach();
}
