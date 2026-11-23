/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_mutex.h"

/* derived names: an object of the pool below, counted by its users at +0x8;
 * the other fields are not traced */
struct Item00cb5ce0 { /* derived name */
    u8 unknown0[0x8];
    int users; /* +0x8 */
};

/* derived names: a pool of objects under a recursive mutex: those in use at
 * +0x18, those given back at +0x30 */
struct Pool00cb5ce0 {                    /* derived name */
    Mutex013847e0 mutex;                 /* +0x0 */
    Array05943280<Item00cb5ce0 *> used;  /* +0x18 */
    Array05943280<Item00cb5ce0 *> freed; /* +0x30 */
};

/* FUN_00cb5ce0: one user of the object less, under the pool's mutex; the
 * last moves it from the objects in use (the last one put in its place) to
 * those given back. derived name */
void FUN_00cb5ce0(Pool00cb5ce0 *pool, Item00cb5ce0 *item)
{
    pool->mutex.lock();
    if (item->users > 0 && --item->users == 0) {
        pool->used.removeSwap(pool->used.indexOf(item));
        pool->freed.push(item);
    }
    pool->mutex.unlock();
}
