/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: a recursive lock: the mutex, its owner and its depth, as
 * FUN_00ea2bd0 and FUN_00ea2c20 hold theirs. */
struct RecursiveLock00a53160 { /* derived name */
    pthread_mutex_t mutex;     /* +0x0 */
    /* volatile: the state the recursive lock shares between threads, as
     * FUN_00ea2bd0's: the owner is compared with the calling thread before
     * the mutex is held, and the depth is read again after its decrement. */
    pthread_t volatile owner; /* +0x8 */
    volatile int depth;       /* +0x10 */

    void lock()
    {
        pthread_t thread = scePthreadSelf();
        if (owner != thread) {
            scePthreadMutexLock(&mutex);
            owner = thread;
        }
        ++depth;
    }

    void unlock()
    {
        --depth;
        if (depth == 0) {
            owner = 0;
            scePthreadMutexUnlock(&mutex);
        }
    }
};

struct Member057c9390_78 { /* derived name */
    u8 unknown0[0xa0];
    RecursiveLock00a53160 lock; /* +0xa0 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x78];
    Member057c9390_78 *unknown78;
};

extern Object057c9390 *D_57c9390;

struct Object00a53160 { /* derived name */
    u8 unknown0[0x248];
    bool unknown248; /* +0x248 */
};

/* derived names: a virtual method (its address at 0x16b20b8): when its byte
 * at +0x248 is set and the pointer at +0x78 of the object the pointer at
 * 0x57c9390 holds is set, takes and drops that object's recursive lock at
 * +0xa0 and clears the byte. Class and method unknown. */
void FUN_00a53160(Object00a53160 *self) /* derived name */
{
    if (!self->unknown248)
        return;
    Member057c9390_78 *member = D_57c9390->unknown78;
    if (!member)
        return;
    member->lock.lock();
    member->lock.unlock();
    self->unknown248 = false;
}
