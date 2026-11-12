/* src/include/tlg_game_object05945a38.h: the object the pointer at
 * 0x5945a38 holds (757 functions read it), as far as the four update
 * functions FUN_0133f330, FUN_01340240, FUN_01340310 and FUN_01342d50 read
 * it: the recursive lock at +0x201028. derived names throughout. */
#ifndef TLG_GAME_OBJECT05945A38_H
#define TLG_GAME_OBJECT05945A38_H

#include "tlg_sce_kernel.h"
#include "tlg_types.h"

/* the recursive lock (unless the calling thread already owns it, locks the
 * mutex and becomes the owner; then counts one more level; the last unlock
 * clears the owner and unlocks the mutex) */
struct RecursiveLock05945a38 { /* derived name */

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

    pthread_mutex_t mutex; /* +0x0 */
    /* volatile: the state the recursive lock shares between threads, as
     * FUN_00ea2bd0's (cookbook 1205): the owner is compared with the calling
     * thread before the mutex is held (the base reads it into a register of
     * its own), the depth tested again after its decrement. */
    pthread_t volatile owner; /* +0x8 */
    volatile int depth;       /* +0x10 */
};

struct Object05945a38 { /* derived name */
    u8 unknown0[0x201028];
    RecursiveLock05945a38 lock201028; /* +0x201028 */
};

extern Object05945a38 *D_5945a38;

#endif
