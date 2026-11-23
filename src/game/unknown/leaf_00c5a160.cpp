/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01343880.h"
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the component taken out of the node at its +0x28, when
 * it has one, under the world's write lock (the node read once, before the
 * lock: `mov rbx, [r14+0x28]`) */
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 190 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_00c5a160(Object01343880 *object)
{
    Object016b85e0 *holder = static_cast<Object016b85e0 *>(object->unknown28);
    if (holder) {
        WorldWriteLock05938c40 lock;
        holder->removeChild(object);
    }
}
