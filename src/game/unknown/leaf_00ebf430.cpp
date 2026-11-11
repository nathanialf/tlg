/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: a callback FUN_00eb45d0 stores at +0x4cc8 of the object
 * the pointer at 0x5a8dfa0 holds, its context beside it at +0x4cd0: takes
 * the recursive lock of the object at +0x100 of the object at 0x5938c40, as
 * FUN_00ea2bd0 takes its own (unless the calling thread already owns it,
 * locks the mutex at +0x170 and becomes the owner at +0x178; then counts one
 * more level at +0x180), and sets the flag at +0x188. Its context is unused;
 * the callback's type is not traced. */
struct Lock05938c40_100 { /* derived name */
    u8 unknown0[0x170];
    pthread_mutex_t mutex; /* +0x170 */
    /* volatile: the state the recursive lock shares between threads, as
     * FUN_00ea2bd0's: the owner is compared with the calling thread before
     * the mutex is held (the base reads it into a register of its own). */
    pthread_t volatile owner; /* +0x178 */
    volatile int depth;       /* +0x180 */
    u8 unknown184[4];
    int unknown188; /* +0x188: the flag */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x100];
    Lock05938c40_100 *unknown100; /* +0x100 */
};

extern Object05938c40 *D_5938c40;

void FUN_00ebf430(void *) /* derived name */
{
    Lock05938c40_100 *lock = D_5938c40->unknown100;
    pthread_t thread = scePthreadSelf();
    if (lock->owner != thread) {
        scePthreadMutexLock(&lock->mutex);
        lock->owner = thread;
    }
    ++lock->depth;
    lock->unknown188 = 1;
}
