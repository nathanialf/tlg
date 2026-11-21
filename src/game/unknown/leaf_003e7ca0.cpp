/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9238.h"

/* the pool closed when there is one, the reference emptied either way (the
 * null test jumps to the exchange, 0x3e7cc5). The destructor is the class's
 * key function: this file emits the vtable and the deleting destructor
 * FUN_003e7ec0. */
Object016a9238::~Object016a9238()
{
    if (Pool016a9238 *held = pool.get())
        held->close();
    pool.clear();
}
