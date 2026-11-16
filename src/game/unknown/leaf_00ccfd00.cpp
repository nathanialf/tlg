/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00ccfd00.h"

/* derived name: the complete destructor: the body detaches the linked
 * object where there is one; no member has a destructor; then the base's
 * destructor is inlined (its vptr store, then the two names).
 * FUN_00ccfdb0, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object00ccfd00::~Object00ccfd00()
{
    if (peer40 != 0)
        peer40->detach();
}
