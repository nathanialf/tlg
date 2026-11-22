/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00c5a160: as FUN_00c57220's (leaf_00c57120.cpp), the mutex unlock tail-called; the null test of the holder also branches the other way (first difference at instruction 7). */
#include "tlg_game_object01343880.h"
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the component taken out of the node at its +0x28, when
 * it has one, under the world's write lock (the node read once, before the
 * lock: `mov rbx, [r14+0x28]`) */
void FUN_00c5a160(Object01343880 *object)
{
    Object016b85e0 *holder = static_cast<Object016b85e0 *>(object->unknown28);
    if (holder) {
        D_5938c40->world->lockWrite();
        holder->removeChild(object);
        D_5938c40->world->unlockWrite();
    }
}
