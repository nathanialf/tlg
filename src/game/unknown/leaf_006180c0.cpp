/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c77b8.h"

/* derived name: the complete destructor: the pool given up, then the
 * pool's reference released and the base's destructor inlined (its vptr
 * store, then its two names). FUN_006182d0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c77b8::~Object016c77b8()
{
    pool.shutdown();
}
